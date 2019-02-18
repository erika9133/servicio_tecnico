#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include <QString>
#include "websockets.h"
#include "xml.h"
#include "bbdd.h"


class Controlador : public QObject
{
    Q_OBJECT
    BBDD *m_bbdd;
    WebSocket *m_ws;
    QList<OrdenesActivas> m_ordenesActivas;
    QUuid gestorDeColas(const QString criterio);
    void enviarFallo(int codigoError, QWebSocket &cliente);


public:
    Controlador();
    ~Controlador();
    void iniciarBBDD();
    void iniciarWS();
    //void setOrdenesActivas(const OrdenesActivas orden);
   // QList<OrdenesActivas> & OrdenesActivas();

private slots:
    void procesarPeticion( MensajeEntrante m);



};

#endif // CONTROLADOR_H
