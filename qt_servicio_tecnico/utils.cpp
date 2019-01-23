#include <QDebug>
#include <iostream>
#include <fstream>
#include <QSqlQuery>
#include "utils.h"

Utils::Utils()
{

}

Utils::~Utils(){}

QStringList Utils::leer(QString archivo)
{
    QStringList lista;
    std::ifstream archivoTempI;
    std::string linea;
    archivoTempI.open (archivo.toStdString().c_str());
    if(archivoTempI.is_open())
    {
       while (getline(archivoTempI,linea))
       {
           lista.append(linea.c_str());
       }
    }
    return lista;
}

QUuid Utils::generarUUID()
{
  QUuid uuid = QUuid::createUuid();
  return uuid;
}

QList<QString> Utils::buscarPorUUID(QUuid ID,QString tabla)
{

    QSqlQuery query("SELECT * FROM '"+tabla+"' where uuid='"+ID.toString()+"';");

    while(query.next())
     {

         // qDebug() << "nombre_marcas" << query.value(1).toString();
     }
    // db.commit();*/

}
