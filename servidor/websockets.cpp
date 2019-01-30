#include <QDebug>
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include "websockets.h"
#include "utils.h"

WebSocket::WebSocket() : m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Test Server")
                                                                 ,QWebSocketServer::NonSecureMode, this)){
    QStringList conf = Utils::leerArchivoLineaPorLinea("configWS.txt");
    m_host = new QString();
    m_port = new quint16();
    *m_host = conf.at(0);
    *m_port = conf.at(1).toUShort();
    if (m_pWebSocketServer->listen(QHostAddress::Any, *m_port))
    {
        qDebug() << "WS iniciado en puerto:" <<*m_port;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection, this, &WebSocket::onNewConnection);
        connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &WebSocket::closed);
    } // end if


}


WebSocket::~WebSocket()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
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
    qDebug() << "De:" << pClient << "Mensaje recibido:" << message;
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

