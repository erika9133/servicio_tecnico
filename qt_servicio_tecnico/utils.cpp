#include <QDebug>
#include <QSqlQuery>
#include <QSql>
#include <iostream>
#include <fstream>
#include "utils.h"

Utils::Utils()
{

}

Utils::~Utils(){}

QStringList Utils::leerArchivoLineaPorLinea(QString archivo)
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

void Utils::escribir(QString archivo, QString linea)
{
        std::ofstream archivoTemp;
        archivoTemp.open (archivo.toStdString().c_str(), std::ios::ate | std::ios::app);
        //archivoTemp << currentDateTime() << "\t" << datos << "\n" << std::endl;
        archivoTemp << linea.toStdString() << std::endl;
        archivoTemp.close();
}

void Utils::escribir(QString archivo, QStringList lista)
{
        std::ofstream archivoTemp;
        archivoTemp.open (archivo.toStdString().c_str(), std::ios::ate | std::ios::app);
        for(auto i : lista)
        {
             archivoTemp << i.toStdString() << std::endl;
        }
        archivoTemp.close();
}

void Utils::crearArchivo(QString archivo)
{
       std::ofstream archivoTemp;
       archivoTemp.open (archivo.toStdString().c_str(), std::ios::ate | std::ios::app);
       archivoTemp.close();
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

QString Utils::lastError(){
    QString devolver;
    QSqlQuery query;
  /*  QString  devolver = query.lastError().text().trimmed();

            if (!lastError.isEmpty())
            {
             devolver << lastError;
            }*/
    return devolver;
}
