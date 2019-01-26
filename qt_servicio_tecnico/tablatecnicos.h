#ifndef TABLAPADRE_H
#define TABLAPADRE_H

#include <QObject>
#include <QList>
#include <QSqlQuery>
#include "bbdd.h"

class TablaTecnicos : protected BBDD
{
public:
    TablaTecnicos();
    ~TablaTecnicos();
    QUuid generarUUID();
    QList<QString> buscarPorUUID(QUuid ID,QString tabla);
protected:
  // QSqlDatabase *m_db;
private:

};

#endif // TABLAPADRE_H
