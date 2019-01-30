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
    void sendMessage(QString message);

signals:
    //void closed();
    void enviarMainWindow(QString);
public slots:
    void go();
    void connected();
    void disconnected();
    void reciveMessage(QString message);





private:
    QWebSocket *m_webSocket;
    QUrl  m_url;
    bool m_connected;

};

#endif // CLIENTE_H
