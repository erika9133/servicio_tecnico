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

struct Cliente {
  QString nombre;
  QUuid id;
  QString tipo; //tecnico o cliente
  bool verificado;
  QWebSocket *cliente;
};

class WebSocket : public QObject
{
    Q_OBJECT
    QWebSocketServer *m_pWebSocketServer;
    static QStringList leerArchivoLineaPorLinea(const QString archivo);
    bool *m_wsStatus;
    QList<Cliente> m_clientes;
public:
    WebSocket();
    ~WebSocket();
    void emitTextMessage(const QString message, QWebSocket *pClient);
    void emitTextMessageACliente(QString message, QUuid id);
    bool estaVerificado(const QWebSocket * aVerificar);
    bool estaVerifcadoConTipo(const QWebSocket * aVerificar, const QString tipo);
    QList<Cliente>& clientes();
    void add_clientes(Cliente);
    Cliente& findClientes(QWebSocket &cliente) ;
    Cliente& findClientes(QString &id);
signals:
    void closed();
    void mensajeRecibido(MensajeEntrante message);
private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void socketDisconnected();
};
#endif // WEBSOCKETS_H
