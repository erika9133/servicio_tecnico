#include <QDebug>
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include "websockets.h"
#include "utils.h"

WebSocket::WebSocket() : m_pWebSocketServer(new QWebSocketServer(QStringLiteral("servicio_tecnico")
                                                                 ,QWebSocketServer::NonSecureMode, this))
{
    QStringList conf = Utils::leerArchivoLineaPorLinea("configWS.txt");
    //QString host = conf.at(0);
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
    qDeleteAll(m_clientes.begin(), m_clientes.end());
    for(auto i : m_clientesVerificados)
    {
       delete i.cliente;
    }
    //qDeleteAll(m_clientesVerificados.begin(), m_clientesVerificados.end());
    //qDeleteAll(m_tecnicosVerificados.begin(), m_tecnicosVerificados.end());
    delete &m_clientes;
    delete &m_clientesVerificados;
    //delete &m_tecnicosVerificados;
    delete m_pWebSocketServer;
    delete m_wsStatus;
}

void WebSocket::onNewConnection()
{
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
    qDebug() << "Socket conectado:" << pSocket;
    connect(pSocket, &QWebSocket::textMessageReceived, this, &WebSocket::processTextMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &WebSocket::socketDisconnected);

    m_clientes << pSocket;
}

void WebSocket::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    MensajeEntrante m;
    m.cliente = pClient;
    m.message = message;
    emit mensajeRecibido(m);
   // qDebug() << "De: " << pClient << " Mensaje recibido";
}

void WebSocket::emitTextMessage(QString message, QWebSocket *pClient)
{
    pClient->sendTextMessage(message);
}

bool WebSocket::estaEnListaVerificados(QWebSocket * aVerificar)
{
    bool devolver = false;
    for(auto i: m_clientesVerificados)
    {
        if(i.cliente == aVerificar)
        {
            devolver = true;
            break;
        }
    }
    return devolver;
}
bool WebSocket::estaEnListaVerifcadosConTipo(QWebSocket * aVerificar, QString tipo)
{
    bool devolver = false;
    for(auto i: m_clientesVerificados)
    {
        if(i.cliente == aVerificar)
        {
            if(i.tipo == tipo)
            {
                devolver = true;
                break;
            }
        }
    }
    return devolver;
}

void WebSocket::socketDisconnected()
{
    QWebSocket * pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        qDebug() << "Socket desconectado:" << pClient;
        /*if(m_clientes.contains(pClient)) m_clientes.removeAll(pClient);

        m_clientesVerificados.removeAll(pClient);
        */
        pClient->deleteLater();
        //if(m_clientesVerificados.contains(pClient)) m_clientesVerificados.removeAll(pClient);
        //if(m_tecnicosVerificados.contains(pClient)) m_tecnicosVerificados.removeAll(122pClient);
    } // end if
}
