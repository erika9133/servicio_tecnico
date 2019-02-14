#ifndef WEBSOCKETS_H
#define WEBSOCKETS_H

#include <QObject>
#include <QList>
#include <QUuid>
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
  QUuid id;
  QString tipo; //tecnico o cliente
  QWebSocket *cliente;
};

class WebSocket : public QObject
{
    Q_OBJECT
    QWebSocketServer *m_pWebSocketServer;
    static QStringList leerArchivoLineaPorLinea(const QString archivo);

public:
    explicit WebSocket();
    ~WebSocket();
    bool *m_wsStatus;
    QList<QWebSocket *> m_clientes;
    QList<ClienteVerificado> m_clientesVerificados;
    void emitTextMessage(const QString message, QWebSocket *pClient);
    void emitTextMessageACliente(const QString message, const QUuid id);
    bool estaEnListaVerificados(const QWebSocket * aVerificar);
    bool estaEnListaVerifcadosConTipo(const QWebSocket * aVerificar, const QString tipo);
signals:
    void closed();
    void mensajeRecibido(const MensajeEntrante message);
private slots:
    void onNewConnection();
    void processTextMessage(const QString message);
    void socketDisconnected();
};
#endif // WEBSOCKETS_H
