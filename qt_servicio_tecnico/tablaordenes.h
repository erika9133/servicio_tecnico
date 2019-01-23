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
};

#endif // TABLAORDENES_H
