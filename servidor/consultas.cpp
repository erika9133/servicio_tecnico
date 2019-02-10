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

bool Consultas::crearOrden(QString cliente, QUuid estados_reparacion,
                           QUuid tecnicos, QUuid dispositivos, QUuid listado_tiendas)
{
    //Test*
    //QString cliente = "pacooo";
    //test se anyaden luego
    //estados_reparacion = "82bb727f-29db-4547-8488-6c30c2dfcc9b";
    //tecnicos = "27e9cc28-56fb-4967-b72e-1615dc614559";
    //QUuid dispositivos = "920dddb7-3cf5-4e9a-8e2d-4426b1e8973a";
    //QUuid listado_tiendas = "a91d6f79-330e-4fa5-a27c-fae47d994b09";

    bool devolver = false;
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
    }else{
        devolver = true;
    }
    m_bbdd->m_db->commit();
    m_bbdd->disconnet();
    return devolver;
}

QStringList Consultas::devolverConsultaDosCondiciones(QString select, QString from, QString where, QString like)
{
    if (like == "")
    {
        like = "'%'";
    }else{
        like = "'%"+like+"%'";
    }
    QStringList devolver;
    m_bbdd->connect();
    m_bbdd->m_db->transaction();
    QSqlQuery query("SELECT "
               +select+
               " FROM "
               +from+
               " WHERE "
               +where+
               " like "
               +like+
               ";", *m_bbdd->m_db);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
        qDebug() << lastError;

    }else{
        while(query.next())
        {
            //qDebug() << query.value(0).toString();
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

bool Consultas::verificarLogin(QString user, QString pass, QString tabla)
{
    bool devolver = false;
    QString respuesta = "";
    m_bbdd->connect();
    m_bbdd->m_db->transaction();
    QSqlQuery query("SELECT "
                    "nombre_"+tabla+
                    " FROM "
                    +tabla+
                    " WHERE "
                    "password_"+tabla+
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
        respuesta = query.value(0).toString();
    }
    m_bbdd->m_db->commit();
    m_bbdd->disconnet();
    if(respuesta == user) devolver = true;
    return devolver;
}

QUuid Consultas::devolverTecnicoMenosOrdenesReparando()
{
    QUuid devolver;
    m_bbdd->connect();
    m_bbdd->m_db->transaction();
    QSqlQuery query("SELECT tecnicos.uuid_tecnicos "
                    "FROM tecnicos "
                    "join ordenes on ordenes.uuid_tecnicos=tecnicos.uuid_tecnicos "
                    "join estados_reparacion on estados_reparacion.uuid_estados_reparacion=ordenes.uuid_estados_reparacion "
                    "where nombre_estados_reparacion like 'reparando' "
                    "group by tecnicos.uuid_tecnicos "
                    "order by count(*) asc limit 1; ", *m_bbdd->m_db);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
        qDebug() << lastError;

    }else{
        query.first();
        devolver = query.value(0).toUuid();
    }
    m_bbdd->m_db->commit();
    m_bbdd->disconnet();
    return devolver;
}

QString Consultas::devolverOrdenesActicas(QString tecnico, QString tipo)
{
    QString devolver;
    m_bbdd->connect();
    m_bbdd->m_db->transaction();
    QSqlQuery query("SELECT uuid_ordenes, cliente_ordenes FROM tecnicos "
                    " join ordenes on ordenes.uuid_tecnicos=tecnicos.uuid_tecnicos "
                    " join estados_reparacion on estados_reparacion.uuid_estados_reparacion=ordenes.uuid_estados_reparacion "
                    " where nombre_estados_reparacion like '"+tipo+"' and tecnicos.nombre_tecnicos like '"+tecnico+"';", *m_bbdd->m_db);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
        qDebug() << lastError;

    }else{
        while(query.next())
        {
            //qDebug() << query.value(0).toString();
            //WIP Devolver DOs tipos distintos para mostrar en el cliente del tecnico.
            devolver.append(query.value(0).toString()+"\n");
        }
    }
    m_bbdd->m_db->commit();
    m_bbdd->disconnet();
    return devolver;
}

