#ifndef CONSULTAS_H
#define CONSULTAS_H

#include <QObject>
#include <QString>
#include <QUuid>
#include "bbdd.h"

class Consultas
{
public:
    Consultas();
    ~Consultas();

    void crearOrden(QString cliente, QUuid estados_reparacion,
                    QUuid tecnicos, QUuid dispositivos, QUuid listado_tiendas);
    QStringList devolverDispositivosAceptados(QString dispositivo);
    QUuid devolverUuid(QString registro, QString tabla);
    bool verificarTienda(QString tienda, QString pass);
private:
    BBDD *m_bbdd;

};

#endif // CONSULTAS_H
