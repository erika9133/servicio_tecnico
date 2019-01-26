#ifndef WEBSOCKETS_H
#define WEBSOCKETS_H

#include <QObject>
#include <QList>
#include <QString>
#include <QByteArray>

class QWebSocketServer;
class QWebSocket;

class WebSocket : public QObject
{
    Q_OBJECT

public:
    explicit WebSocket();
    ~WebSocket();
    bool *m_wsStatus;

signals:
    void closed();
    void mensajeRecibido(QString message);

private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void socketDisconnected();

private:
    QString *m_host = new QString();
    quint16 *m_port = new quint16();
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
};

#endif // WEBSOCKETS_H
