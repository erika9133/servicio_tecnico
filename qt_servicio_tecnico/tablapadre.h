#ifndef TABLAPADRE_H
#define TABLAPADRE_H

#include <QObject>
#include <QUuid>
#include <QList>
#include <QSqlQuery>

class tablaPadre
{
public:
    tablaPadre(QSqlDatabase &m_db);

    QUuid generarUUID();
    QList<QString> buscarPorUUID(QUuid ID,QString tabla);
protected:
    QSqlDatabase m_db;
private:

};

#endif // TABLAPADRE_H
