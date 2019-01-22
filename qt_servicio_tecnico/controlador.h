#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include <QString>
#include "bbdd.h"
#include "websockets.h"
#include "tablaordenes.h"
#include "tablapadre.h"

class Controlador
{
public:
    Controlador();
    ~Controlador();
    void iniciarBBDD();
    void iniciarWS();
private:
   BBDD *m_bbdd;
   WebSocket *m_ws;
   tablaPadre *m_tablapadre;
};

#endif // CONTROLADOR_H
