#include <QSqlQuery>
#include <QSql>
#include "consultas.h"
#include "utils.h"

Consultas::Consultas()
{
   // m_db = *m_db;
   // *m_db = QSqlDatabase::addDatabase("QPSQL");
}

Consultas::~Consultas(){}


void Consultas::crearOrden(QString cliente, QUuid estados_reparacion,
                           QUuid tecnicos, QUuid dispositivos, QUuid listado_tiendas)
{
    //Test*
    //QString cliente = "pacooo";
    //test se anyaden luego
    estados_reparacion = "82bb727f-29db-4547-8488-6c30c2dfcc9b";
    tecnicos = "27e9cc28-56fb-4967-b72e-1615dc614559";
    //QUuid dispositivos = "920dddb7-3cf5-4e9a-8e2d-4426b1e8973a";
    //QUuid listado_tiendas = "a91d6f79-330e-4fa5-a27c-fae47d994b09";


    connect();
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
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
     qDebug() << lastError;

    }
    disconnet();


    //QSqlQuery query1("INSERT INTO tablatest (nombre) VALUES ('x')",m_db);
    // query.exec("INSERT INTO tabla1 (id_tabla1,nombre_tabla11,uuid_tabla1)
    //ALUES ('"+QString::number(x+10)+"','"+QString::number(x)+"','"+uuid.toString()+"')");


    //query.exec("INSERT INTO tabla1 (id_tabla1,nombre_tabla11,uuid_tabla1)
            //VALUES ('"+QString::number(x+10)+"','"+QString::number(x)+"','"+uuid.toString()+"')");
// QSqlQuery query("SELECT * FROM marcas");

/* while(query.next())
 {

      qDebug() << "nombre_marcas" << query.value(1).toString();
 }
// db.commit();*/
}

QStringList Consultas::devolverDispositivosAceptados()
{
    QStringList devolver;
    connect();
    m_db->transaction();
    QSqlQuery query("SELECT "
                    "dispositivos.nombre_dispositivos,"
                    "marcas.nombre_marcas "
                    "FROM dispositivos JOIN marcas ON "
                    "dispositivos.uuid_marcas = "
                    "marcas.uuid_marcas;", *m_db);


    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
     qDebug() << lastError;

    }else{
        int i = 0;
        while(query.next())
        {
            devolver << query.value(i).toString();
            i++;
        }
    }

    m_db->commit();
    disconnet();
    return devolver;
}

