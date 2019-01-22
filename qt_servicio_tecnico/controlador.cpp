#include <QDebug>
#include "controlador.h"


Controlador::Controlador()
{


   // st.connect();
    // tablaPadre tp(&st.m_db);
   // tp.buscarPorUUID("14373c86-0ae6-4ed8-900e-dffefdb83344","marcas");
  //s  TablaOrdenes to;
           // QUuid uuid = QUuid::createUuid();
           // QSqlQuery query;
           // query.exec("INSERT INTO tabla1 (id_tabla1,nombre_tabla11,uuid_tabla1) VALUES ('"+QString::number(x+10)+"','"+QString::number(x)+"','"+uuid.toString()+"')");
           // QSqlQuery query("INSERT INTO tablatest (nombre) VALUES ('x')",db);


           // QSqlQuery query("INSERT INTO tabla1 (nombre_tabla1,uuid_tabla1) VALUES ('x','"+ uuid.toString()+"')", db);
           /* QString lastError = query.lastError().text().trimmed();

            if (!lastError.isEmpty())
            {
             qDebug() << lastError;

            }*/


      // QSqlQuery query("SELECT * FROM marcas");

       /* while(query.next())
        {

             qDebug() << "nombre_marcas" << query.value(1).toString();
        }
       // db.commit();

     "Error de conexion";

*/
}
Controlador::~Controlador(){}

void Controlador::iniciarBBDD()
{
    m_bbdd = new BBDD();
    m_bbdd->connect();
}

void Controlador::iniciarWS()
{
    m_ws = new WebSocket();
  //  QObject::connect(m_ws, &m_ws::closed, &app, &QCoreApplication::quit);

}
