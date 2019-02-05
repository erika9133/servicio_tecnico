#include <QDebug>
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include "websockets.h"
#include "utils.h"

WebSocket::WebSocket() : m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Test Server")
                                                                 ,QWebSocketServer::NonSecureMode, this))
{
    QStringList conf = Utils::leerArchivoLineaPorLinea("configWS.txt");
    QString host = conf.at(0);
    quint16 port = conf.at(1).toUShort();
    if (m_pWebSocketServer->listen(QHostAddress::Any, port))
    {
        qDebug() << "WS iniciado en puerto:" << port;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection, this, &WebSocket::onNewConnection);
        connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &WebSocket::closed);
    } // end if
}

WebSocket::~WebSocket()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
    qDeleteAll(m_clientsVerificados.begin(), m_clientsVerificados.end());
    delete &m_clients;
    delete &m_clientsVerificados;
    delete m_pWebSocketServer;
    delete m_wsStatus;
}

void WebSocket::onNewConnection()
{
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
    qDebug() << "Socket conectado:" << pSocket;
    connect(pSocket, &QWebSocket::textMessageReceived, this, &WebSocket::processTextMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &WebSocket::socketDisconnected);
    m_clients << pSocket;
}

void WebSocket::processTextMessage(QString message)
{

    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    mensajeEntrante m;
    m.cliente = pClient;
    m.message = message;
    emit mensajeRecibido(m);
    qDebug() << "De: " << pClient << " Mensaje recibido";
}

void WebSocket::emitTextMessage(QString message, QWebSocket *pClient)
{
    pClient->sendTextMessage(message);
}

void WebSocket::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    qDebug() << "Socket desconectado:" << pClient;

    if (pClient)
    {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    } // end if
}
