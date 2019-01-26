#include <QDebug>
#include <QString>
#include "controlador.h"
#include "tablatecnicos.h"
#include "tablaordenes.h"

#include "xml.h"
#include "utils.h"

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
Controlador::~Controlador()
{
    if(m_bbdd->m_bdStatus)
    {
        m_bbdd->disconnet();
    }
    delete m_bbdd;
}

void Controlador::iniciarBBDD()
{

   // XML xml;
    //xml.GenerarOrden(Utils::generarUUID());
    m_bbdd = new BBDD();

    //hasta que el controlador no muera, se mantiene el puntero dinamico

    m_tablaOrdenes = new TablaOrdenes();
    m_tablaTecnicos = new TablaTecnicos();


}

void Controlador::iniciarWS()
{

   // m_ws = new WebSocket();
    m_xml = new XML();
    QString prueba = "prueba.xml";
    m_xml->validaXML(&prueba);


  //  QObject::connect(m_ws,SIGNAL(mensajeRecibido(QString)), this,SLOT(mensajeEntrante(QString)));

}

void Controlador::mensajeEntrante(QString message)
{
    message = "";
    /*
    bool validar = m_xml->validaXML(message);
    int tipo = m_xml->tipo();
    if(validar)
    {
        switch(tipo)
        case 1:
            break;
        case 2:
            break;
    }
    */
}

