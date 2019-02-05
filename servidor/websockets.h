#ifndef WEBSOCKETS_H
#define WEBSOCKETS_H

#include <QObject>
#include <QList>
#include <QString>
#include <QByteArray>

class QWebSocketServer;
class QWebSocket;

struct mensajeEntrante {
  QString message;
  QWebSocket *cliente;
};

class WebSocket : public QObject
{
    Q_OBJECT

public:
    explicit WebSocket();
    ~WebSocket();
    bool *m_wsStatus;
    QList<QWebSocket *> m_clients;
    QList<QWebSocket *> m_clientsVerificados;
    void emitTextMessage(QString message, QWebSocket *pClient);
signals:
    void closed();
    void mensajeRecibido(mensajeEntrante m);
private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void socketDisconnected();
private:
    QWebSocketServer *m_pWebSocketServer;

};

#endif // WEBSOCKETS_H
