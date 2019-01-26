#ifndef TABLAORDENES_H
#define TABLAORDENES_H

#include <QObject>
#include <QString>
#include <QUuid>
#include "bbdd.h"

class TablaOrdenes : protected BBDD
{
public:
    TablaOrdenes();
    ~TablaOrdenes();
    void crearOrden();
    //QString cliente, QUuid estados_reparacion,
    //QUuid tecnicos, QUuid dispositivos, QUuid listado_tiendas
};

#endif // TABLAORDENES_H
