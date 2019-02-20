#include <QDebug>
#include <QSqlQuery>
#include <QDebug>
#include <QSql>
#include <iostream>
#include <fstream>
#include "bbdd.h"

BBDD::BBDD()
{
    cargarDatosConfig();
}

BBDD::~BBDD()
{
    disconnect();
    //delete m_db; Descomentar si se hace puntero NO DINAMICO
}

void BBDD::connect()
{
    if(!m_bdStatus)
    {
        //qDebug() << m_db->isValid();
        m_db.setHostName(m_host);
        m_db.setPort(m_port);
        m_db.setDatabaseName(m_databaseName);
        m_db.setUserName(m_username);
        m_db.setPassword(m_password);
        bool ok = m_db.open();
        QSqlError error = m_db.lastError();
        if (ok)
        {
            m_bdStatus = true;
        }else{
            m_bdStatus = false;
            qDebug() << "Error de conexion" << error.text();
        }
      // qDebug() << "" << QUuid::createUuid().toString();
    }
}

void BBDD::disconnect()
{
    if(m_bdStatus) m_bdStatus = false;
    if(m_db.open()) m_db.close();
}

void BBDD::cargarDatosConfig()
{
    /*
     * 1 QString driver
     * 2 QString host
     * 3 int port
     * 4 QString databasename
     * 5 QString username
     * 6 QString password
     */

    QStringList conf = BBDD::leerArchivoLineaPorLinea("configBBDD.txt");
    //m_db = std::make_unique<QSqlDatabase>();
    //m_db = QSqlDatabase;
    m_bdStatus = false;
    m_host = conf.at(0);
    m_port = conf.at(1).toUShort();
    m_databaseName = conf.at(2);
    m_username = conf.at(3);
    m_password = conf.at(4);
    m_db = QSqlDatabase::addDatabase(m_driver);
    qDebug() << "Postgres cargado en puerto:" << m_port;
    // Para remover caracteres raros
    //i = i.remove(QRegExp(QString::fromUtf8("[-`~!@#$%^&*()_€”+=|:;<>«»,.?/{}\'\"")));
}

bool BBDD::crearOrden(QString cliente, QUuid estados_reparacion,
                           QUuid tecnicos, QUuid dispositivos, QUuid listado_tiendas)
{
    //Test*
    //QString cliente = "pacooo";
    //test se anyaden luego
    //estados_reparacion = "82bb727f-29db-4547-8488-6c30c2dfcc9b";
    //tecnicos = "27e9cc28-56fb-4967-b72e-1615dc614559";
    //QUuid dispositivos = "920dddb7-3cf5-4e9a-8e2d-4426b1e8973a";
    //QUuid listado_tiendas = "a91d6f79-330e-4fa5-a27c-fae47d994b09";
    if(tecnicos == "00000000-0000-0000-0000-000000000000") tecnicos = "";
    bool devolver = false;
    connect();
    m_db.transaction();
    QUuid uuid_ordenes = QUuid::createUuid();
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
                    ")", m_db);
    query.bindValue(0,cliente);
    query.bindValue(1,estados_reparacion);
    query.bindValue(2,tecnicos);
    query.bindValue(3,cliente);
    query.bindValue(4,dispositivos);
    query.bindValue(5,listado_tiendas);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
        qDebug() << lastError;
    }else{
        query.first();
        devolver = true;
    }
    m_db.commit();
    disconnect();
    return devolver;
}

QStringList BBDD::devolverConsultaDosCondiciones(QString select, QString from, QString where, QString like)
{
    if (like == "")
    {
        like = "'%'";
    }else{
        like = "'%"+like+"%'";
    }
    QStringList devolver;
    connect();
    m_db.transaction();
    QSqlQuery query("SELECT "
               +select+
               " FROM "
               +from+
               " WHERE "
               +where+
               " like "
               +like+
               ";", m_db);
    query.bindValue(0,select);
    query.bindValue(1,from);
    query.bindValue(2,where);
    query.bindValue(3,like);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
        qDebug() << lastError;

    }else{
        while(query.next())
        {
            //qDebug() << query.value(0).toString();
           // devolver.append(query.value(0).toString()+"\n");
             devolver.append(query.value(0).toString());
        }
    }
    m_db.commit();
    disconnect();
    return devolver;
}

QUuid BBDD::devolverUuid(QString registro, QString tabla)
{
    QUuid devolver;
    connect();
    m_db.transaction();
    QSqlQuery query("SELECT "
                    "uuid_"+tabla+
                    " FROM "
                    +tabla+
                    " WHERE "
                    "nombre_"+tabla+
                    " = "
                    "'"+registro+"'"
                    " ;", m_db);
    query.bindValue(0,registro);
    query.bindValue(1,tabla);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
     qDebug() << lastError;
    }else{
        //You should call query.first() before you can access returned data. additionally if your query returns more than one row, you should iterate via query.next().
        query.first();
        devolver = query.value(0).toUuid();
    }
    m_db.commit();
    disconnect();
    return devolver;
}

QUuid BBDD::devolverOrdenLibre()
{
    QUuid devolver;
    connect();
    m_db.transaction();
    QSqlQuery query("SELECT ordenes.uuid_ordenes "
                    "FROM ordenes "
                    "join estados_reparacion on estados_reparacion.uuid_estados_reparacion=ordenes.uuid_estados_reparacion "
                    "where nombre_estados_reparacion like 'pendiente' "
                    "group by ordenes.uuid_ordenes "
                    "order by hora_ordenes asc limit 1; ", m_db);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
     qDebug() << lastError;
    }else{
        //You should call query.first() before you can access returned data. additionally if your query returns more than one row, you should iterate via query.next().
        query.first();
        devolver = query.value(0).toUuid();
    }
    m_db.commit();
    disconnect();
    return devolver;
}

bool BBDD::verificarLogin(QString user, QString pass, QString tabla)
{
    bool devolver = false;
    QString respuesta = "";
    connect();
    m_db.transaction();
    QSqlQuery query("SELECT "
                    "nombre_"+tabla+
                    " FROM "
                    +tabla+
                    " WHERE "
                    "password_"+tabla+
                    " = "
                    "'"+pass+"'"
                    " ;", m_db);
   // query.bindValue(0,user);
    //query.bindValue(1,pass);
    //query.bindValue(2,tabla);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
     qDebug() << lastError;
    }else{

        //You should call query.first() before you can access returned data. additionally if your query returns more than one row, you should iterate via query.next().
        query.first();
        respuesta = query.value(0).toString();
        qDebug() << respuesta;
    }
    m_db.commit();
    disconnect();
    if(respuesta == user) devolver = true;
    qDebug() << devolver;
    return devolver;
}

QUuid BBDD::devolverTecnicoMenosOrdenesReparando()
{
    QUuid devolver;
    connect();
    m_db.transaction();

    QSqlQuery query("SELECT tecnicos.uuid_tecnicos "
                    "FROM tecnicos "
                    "join ordenes on ordenes.uuid_tecnicos=tecnicos.uuid_tecnicos "
                    "join estados_reparacion on estados_reparacion.uuid_estados_reparacion=ordenes.uuid_estados_reparacion "
                    "where nombre_estados_reparacion like 'reparando' "
                    "group by tecnicos.uuid_tecnicos "
                    "order by count(*) asc limit 1; ", m_db);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
        qDebug() << lastError;

    }else{
        query.first();
        devolver = query.value(0).toUuid();
    }
    m_db.commit();
    disconnect();
    return devolver;
}

QList<OrdenesActivas> BBDD::devolverOrdenesActicas(QString tecnico, QString tipo)
{
    QList<OrdenesActivas> devolver;
    if(tecnico == "todos") tecnico = "%";
    connect();
    m_db.transaction();
    QSqlQuery query("SELECT uuid_ordenes, cliente_ordenes FROM tecnicos "
                    " join ordenes on ordenes.uuid_tecnicos=tecnicos.uuid_tecnicos "
                    " join estados_reparacion on estados_reparacion.uuid_estados_reparacion=ordenes.uuid_estados_reparacion "
                    " where nombre_estados_reparacion like '"+tipo+"' and tecnicos.nombre_tecnicos like '"+tecnico+"';", m_db);
    query.bindValue(0,tecnico);
    query.bindValue(1,tipo);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
        qDebug() << lastError;

    }else{
        while(query.next())
        {
            OrdenesActivas temp;
            temp.id = query.value(0).toString();
            temp.cliente = query.value(1).toString();
            devolver.append(temp);
        }
    }
    m_db.commit();
    disconnect();
    return devolver;
}

QStringList BBDD::leerArchivoLineaPorLinea(QString archivo)
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

QString BBDD::devolverMensajeError(const int id)
{
    connect();
    QString idString = QString::number(id);
    m_db.transaction();
    QString devolver = "";
    QSqlQuery query("SELECT nombre_codigos_error"
                    "FROM codigos_error"
                    "where id_codigos_error = "
                    +idString+";", m_db);
    query.bindValue(0,idString);
    QString lastError = query.lastError().text().trimmed();
    if (!lastError.isEmpty())
    {
        qDebug() << lastError;

    }else{
        query.first();
        devolver = query.value(0).toString();
    }
    m_db.commit();
    disconnect();
    return devolver;
}






