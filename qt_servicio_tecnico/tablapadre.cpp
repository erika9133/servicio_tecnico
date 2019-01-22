#include "tablapadre.h"

tablaPadre::tablaPadre(QSqlDatabase &m_db)
{
   //ss m_db = &m_db;
}

QUuid tablaPadre::generarUUID()
{
  QUuid uuid = QUuid::createUuid();
  return uuid;
}
QList<QString> tablaPadre::buscarPorUUID(QUuid ID,QString tabla)
{

    QSqlQuery query("SELECT * FROM '"+tabla+"' where uuid='"+ID.toString()+"';");

    while(query.next())
     {

         // qDebug() << "nombre_marcas" << query.value(1).toString();
     }
    // db.commit();*/

}
