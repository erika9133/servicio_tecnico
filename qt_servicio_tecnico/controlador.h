#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include <QString>
#include "bbdd.h"
#include "websockets.h"
#include "xml.h"
#include "tablatecnicos.h"
#include "tablaordenes.h"

class Controlador : public QObject
{
    Q_OBJECT

public:
    Controlador();
    ~Controlador();
    void iniciarBBDD();
    void iniciarWS();
private slots:
    void mensajeEntrante(QString message);
private:
   BBDD *m_bbdd;
   WebSocket *m_ws;
   XML *m_xml;
   TablaTecnicos *m_tablaTecnicos;
   TablaOrdenes *m_tablaOrdenes;
};

#endif // CONTROLADOR_H
