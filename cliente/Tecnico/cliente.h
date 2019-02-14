#ifndef CLIENTE_H
#define CLIENTE_H

#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>
#include "ui_mainwindow.h"

class QWebSocket;


class Cliente : public QObject
{
    Q_OBJECT

public:
    explicit Cliente();
    ~Cliente();
    void sendMessage(QString message);
    bool m_connected;
private:
     QWebSocket *m_webSocket;
signals:
    //void closed();
    void procesarMensaje(QString);
public slots:
    void go();
    void connected();
    void disconnected();
    void reciveMessage(QString message);
private:
    QUrl m_url;

};

#endif // CLIENTE_H
