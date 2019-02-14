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
    QUuid gestorDeColas(const QString criterio);

public:
    Controlador();
    ~Controlador();
    void iniciarBBDD();
    void iniciarWS();

private slots:
    void procesarPeticion(const MensajeEntrante m);



};

#endif // CONTROLADOR_H
