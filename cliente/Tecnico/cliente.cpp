#include <QDebug>
#include "cliente.h"


QT_USE_NAMESPACE

Cliente::Cliente()
{
    m_url = QUrl(QStringLiteral("ws://localhost:3344"));
}

Cliente::~Cliente()
{
 if (m_connected) disconnect();
 delete m_webSocket;
}

void Cliente::go()
{
    m_webSocket = new QWebSocket();
    connect(m_webSocket, SIGNAL(connected()),this,SLOT(connected()));
    connect(m_webSocket, SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(m_webSocket, SIGNAL(textMessageReceived(QString)),this,SLOT(reciveMessage(QString)));
    m_webSocket->open(m_url);
}

void Cliente::connected()
{
    m_connected = true;
    qDebug() << "WebSocket connected";
    qDebug() << m_connected;
    //sendMessage("a");
}

void Cliente::disconnected()
{
    m_connected = false;
    qDebug() << "WebSocket disconnected";
    m_webSocket->close();
}

void Cliente::sendMessage(QString message)
{
    if (m_connected){
        qDebug() << "Message enviado:" << message;
        m_webSocket->sendTextMessage(message);
    }
}

void Cliente::reciveMessage(QString message)
{
    emit procesarMensaje(message);
    qDebug() << "Message recibido:" << message;
}

