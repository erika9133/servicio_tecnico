#ifndef WEBSOCKETS_H
#define WEBSOCKETS_H

#include <QObject>
#include <QList>
#include <QString>
#include <QByteArray>
#include <QPair>

class QWebSocketServer;
class QWebSocket;

struct MensajeEntrante {
  QString message;
  QWebSocket *cliente;
};

struct ClienteVerificado {
  QString nombre;
  QString tipo; //tecnico o cliente
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
    QList<ClienteVerificado> m_clientesVerificados;
    void emitTextMessage(QString message, QWebSocket *pClient);
    bool estaEnListaVerificados(QWebSocket * aVerificar);
    bool estaEnListaVerifcadosConTipo(QWebSocket * aVerificar, QString tipo);
signals:
    void closed();
    void mensajeRecibido(MensajeEntrante message);
private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void socketDisconnected();
private:
    QWebSocketServer *m_pWebSocketServer;

};

#endif // WEBSOCKETS_H
