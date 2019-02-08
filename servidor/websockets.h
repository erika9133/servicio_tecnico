#ifndef WEBSOCKETS_H
#define WEBSOCKETS_H

#include <QObject>
#include <QList>
#include <QString>
#include <QByteArray>
#include <QPair>

class QWebSocketServer;
class QWebSocket;

struct stringCliente {
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
    QList<QWebSocket *> m_clientes;
    QList<stringCliente> m_clientesVerificados;
    QList<stringCliente> m_tecnicosVerificados;
    void emitTextMessage(QString message, QWebSocket *pClient);
signals:
    void closed();
    void mensajeRecibido(stringCliente message);
private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void socketDisconnected();
private:
    QWebSocketServer *m_pWebSocketServer;

};

#endif // WEBSOCKETS_H
