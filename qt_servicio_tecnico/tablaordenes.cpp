#include <QSqlQuery>
#include <QSql>
#include "tablaordenes.h"
#include "utils.h"



TablaOrdenes::TablaOrdenes()
{
    // m_db;
}

TablaOrdenes::~TablaOrdenes(){}


void TablaOrdenes::crearOrden()
{
    /*Test*/

    /*QString cliente, QUuid estados_reparacion,
                              QUuid tecnicos, QUuid dispositivos, QUuid listado_tiendas*/
    QString cliente = "juan";
    QUuid estados_reparacion = "82bb727f-29db-4547-8488-6c30c2dfcc9b";
    QUuid tecnicos = "27e9cc28-56fb-4967-b72e-1615dc614559";
    QUuid dispositivos = "920dddb7-3cf5-4e9a-8e2d-4426b1e8973a";
    QUuid listado_tiendas = "a91d6f79-330e-4fa5-a27c-fae47d994b09";

    BBDD::connect();
    QUuid uuid_ordenes = Utils::generarUUID();
    m_db->transaction();
    QSqlQuery query("INSERT INTO ordenes ("
                    "uuid_ordenes,"
                    "cliente_ordenes,"
                    "uuid_estados_reparacion,"
                    "uuid_tecnicos,"
                    "uuid_dispositivos,"
                    "uuid_listado_tiendas"
                    ") VALUES ("
                    "'"+uuid_ordenes.toString()+"',"
                    "'"+cliente+"',"
                    "'"+estados_reparacion.toString()+"',"
                    "'"+tecnicos.toString()+"',"
                    "'"+dispositivos.toString()+"',"
                    "'"+listado_tiendas.toString()+"'"
                    ")", *m_db);
    m_db->commit();

    //QSqlQuery query1("INSERT INTO tablatest (nombre) VALUES ('x')",m_db);
    // query.exec("INSERT INTO tabla1 (id_tabla1,nombre_tabla11,uuid_tabla1) VALUES ('"+QString::number(x+10)+"','"+QString::number(x)+"','"+uuid.toString()+"')");
    /* QString lastError = query.lastError().text().trimmed();



    //query.exec("INSERT INTO tabla1 (id_tabla1,nombre_tabla11,uuid_tabla1) VALUES ('"+QString::number(x+10)+"','"+QString::number(x)+"','"+uuid.toString()+"')");

     if (!lastError.isEmpty())
     {
      qDebug() << lastError;

     }*/


// QSqlQuery query("SELECT * FROM marcas");

/* while(query.next())
 {

      qDebug() << "nombre_marcas" << query.value(1).toString();
 }
// db.commit();*/
}

