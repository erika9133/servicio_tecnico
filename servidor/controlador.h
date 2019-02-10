#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include <QString>
#include "websockets.h"
#include "xml.h"
#include "consultas.h"


class Controlador : public QObject
{
    Q_OBJECT

public:
    Controlador();
    ~Controlador();
    void iniciarBBDD();
    void iniciarWS();
private slots:
    void procesarPeticion(MensajeEntrante m);
private:
   BBDD *m_bbdd;
   WebSocket *m_ws;
   XML *m_xml;
   Consultas *m_consultas;
   QUuid gestorDeColas(QString criterio);

};

#endif // CONTROLADOR_H
