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

    bool crearOrden(QString cliente, QUuid estados_reparacion,
                    QUuid tecnicos, QUuid dispositivos, QUuid listado_tiendas);
    QStringList devolverConsultaDosCondiciones(QString select, QString where, QString like, QString from);
    QUuid devolverUuid(QString registro, QString tabla);
    bool verificarLogin(QString user, QString pass, QString tabla);
private:
    BBDD *m_bbdd;

};

#endif // CONSULTAS_H
