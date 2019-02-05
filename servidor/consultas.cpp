#include <QSqlQuery>
#include <QSql>
#include <QDebug>
#include "consultas.h"
#include "utils.h"

Consultas::Consultas()
{
    m_bbdd = new BBDD();
}

Consultas::~Consultas()
{
    delete m_bbdd;
}

void Consultas::crearOrden(QString cliente, QUuid estados_reparacion,
                           QUuid tecnicos, QUuid dispositivos, QUuid listado_tiendas)
{
    //Test*
    //QString cliente = "pacooo";
    //test se anyaden luego
    //estados_reparacion = "82bb727f-29db-4547-8488-6c30c2dfcc9b";
    //tecnicos = "27e9cc28-56fb-4967-b72e-1615dc614559";
    //QUuid dispositivos = "920dddb7-3cf5-4e9a-8e2d-4426b1e8973a";
    //QUuid listado_tiendas = "a91d6f79-330e-4fa5-a27c-fae47d994b09";


    m_bbdd->connect();
    m_bbdd->m_db->transaction();
    QUuid uuid_ordenes = Utils::generarUUID();
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
                    ")", *m_bbdd->m_db);

    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
        qDebug() << lastError;
    }
    m_bbdd->m_db->commit();
    m_bbdd->disconnet();
}

QStringList Consultas::devolverDispositivosAceptados(QString dispositivo)
{
    if (dispositivo == "")
    {
        dispositivo = "'%'";
    }else{
        dispositivo = "'%"+dispositivo+"%'";
    }
    QStringList devolver;
    m_bbdd->connect();
    m_bbdd->m_db->transaction();
    QSqlQuery query("SELECT "
               "nombre_dispositivos "
               "FROM dispositivos "
               "WHERE "
               "nombre_dispositivos "
               "like "
               +dispositivo+
               ";", *m_bbdd->m_db);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
        qDebug() << lastError;

    }else{
        while(query.next())
        {
            qDebug() << query.value(0).toString();
            devolver.append(query.value(0).toString()+"\n");
        }
    }
    m_bbdd->m_db->commit();
    m_bbdd->disconnet();
    return devolver;
}

QUuid Consultas::devolverUuid(QString registro, QString tabla)
{
    QUuid devolver;
    m_bbdd->connect();
    m_bbdd->m_db->transaction();
    QSqlQuery query("SELECT "
                    "uuid_"+tabla+
                    " FROM "
                    +tabla+
                    " WHERE "
                    "nombre_"+tabla+
                    " = "
                    "'"+registro+"'"
                    " ;", *m_bbdd->m_db);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
     qDebug() << lastError;
    }else{
        //You should call query.first() before you can access returned data. additionally if your query returns more than one row, you should iterate via query.next().
        query.first();
        devolver = query.value(0).toUuid();
    }
    m_bbdd->m_db->commit();
    m_bbdd->disconnet();
    return devolver;
}

bool Consultas::verificarTienda(QString tienda, QString pass)
{
    bool devolver = false;
    QString tiendaRespuesta = "";
    m_bbdd->connect();
    m_bbdd->m_db->transaction();
    QSqlQuery query("SELECT "
                    "nombre_listado_tiendas "
                    " FROM "
                    "listado_tiendas"
                    " WHERE "
                    "password_listado_tiendas"
                    " = "
                    "'"+pass+"'"
                    " ;", *m_bbdd->m_db);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
     qDebug() << lastError;
    }else{
        //You should call query.first() before you can access returned data. additionally if your query returns more than one row, you should iterate via query.next().
        query.first();
        tiendaRespuesta = query.value(0).toString();
    }
    m_bbdd->m_db->commit();
    m_bbdd->disconnet();
    if(tiendaRespuesta == tienda) devolver = true;
    return devolver;
}
