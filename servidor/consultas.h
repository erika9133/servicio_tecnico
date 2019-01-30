#ifndef CONSULTAS_H
#define CONSULTAS_H

#include <QObject>
#include <QString>
#include <QUuid>
#include "bbdd.h"

class Consultas : protected BBDD
{
public:
    Consultas();
    ~Consultas();
    void crearOrden(QString cliente, QUuid estados_reparacion,
                    QUuid tecnicos, QUuid dispositivos, QUuid listado_tiendas);
    QStringList devolverDispositivosAceptados();
    //QString cliente, QUuid estados_reparacion,
    //QUuid tecnicos, QUuid dispositivos, QUuid listado_tiendas
};

#endif // CONSULTAS_H
