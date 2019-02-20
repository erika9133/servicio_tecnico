#include <QDebug>
#include <iostream>
#include <fstream>
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include "websockets.h"

WebSocket::WebSocket() : m_pWebSocketServer(new QWebSocketServer(QStringLiteral("servicio_tecnico")
                                                                 ,QWebSocketServer::NonSecureMode, this))
{
    QStringList conf = leerArchivoLineaPorLinea("configWS.txt");
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
   // qDeleteAll(m_clientes.begin(), m_clientes.end());
    for(auto i : m_clientes)
    {
       delete i.cliente;
    }
    //qDeleteAll(m_clientesVerificados.begin(), m_clientesVerificados.end());
    //qDeleteAll(m_tecnicosVerificados.begin(), m_tecnicosVerificados.end());
    delete &m_clientes;
   // delete &m_clientesVerificados;
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
    Cliente cli;
    cli.nombre = "";
    cli.id = "00000000-0000-0000-0000-000000000000";
    cli.tipo = "";
    cli.verificado = false;
    cli.cliente = pSocket;
    m_clientes.append(cli);
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

void WebSocket::emitTextMessage(const QString message, QWebSocket *pClient)
{
    pClient->sendTextMessage(message);
}

void WebSocket::emitTextMessageACliente(QString message, QUuid id)
{
    //Version avanzada, emite a todos los clientes que comparten tienda
    //(estaciones de trabajo con diferentes sockets)s
    for(auto i: m_clientes)
    {
        if(i.id == id)
        {
            i.cliente->sendTextMessage(message);
        }
    }
}

bool WebSocket::estaVerificado(const QWebSocket * aVerificar)
{
    bool devolver = false;
    for(auto i: m_clientes)
    {
        if(i.cliente == aVerificar)
        {
            if(i.verificado) devolver = true;
            break;
        }
    }
    return devolver;
}
bool WebSocket::estaVerifcadoConTipo(const QWebSocket * aVerificar, const QString tipo)
{
    bool devolver = false;
    for(auto i: m_clientes)
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

QStringList WebSocket::leerArchivoLineaPorLinea(const QString archivo)
{
    QStringList lista;
    std::ifstream archivoTempI;
    std::string linea;
    archivoTempI.open (archivo.toStdString().c_str());
    if(archivoTempI.is_open())
    {
       while (getline(archivoTempI,linea))
       {
           lista.append(linea.c_str());
       }
    }
    return lista;
}

QList<Cliente>& WebSocket::clientes()
{
    return m_clientes;
}

void WebSocket::add_clientes(Cliente cli)
{
    m_clientes.append(cli);
}

Cliente& WebSocket::findClientes(QWebSocket &cliente)
{
    Cliente devolver;
    for(int i = 0 ; i < m_clientes.size() ; i++)
    {
        if(m_clientes.at(i).cliente == &cliente){
            //at devuelve un valor constante y no se puede modificar desde fuera
            devolver = m_clientes[i];
        }
    }
    return devolver;
}

Cliente &WebSocket::findClientes(QString &id)
{
    Cliente devolver = {};
    for( auto i : m_clientes)
    {
        if(i.id == id) devolver = i;
    }
    return devolver;
}
