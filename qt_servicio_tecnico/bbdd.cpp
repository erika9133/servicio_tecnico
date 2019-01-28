#include <QDebug>
#include <QSqlQuery>
#include <QDebug>
#include "bbdd.h"
#include "utils.h"

BBDD::BBDD()
{
     qDebug() << "entra";
    //disconnet();
    /*
     * 1 QString driver
     * 2 QString host
     * 3 int port
     * 4 QString databasename
     * 5 QString username
     * 6 QString password
     */

    QStringList conf = Utils::leerArchivoLineaPorLinea("configBBDD.txt");
    m_db = std::make_unique<QSqlDatabase>();
    m_bdStatus = false;
    m_driver = conf.at(0);
    m_host = conf.at(1);
    m_port = conf.at(2).toUShort();
    m_databaseName = conf.at(3);
    m_username = conf.at(4);
    m_password = conf.at(5);
    *m_db = QSqlDatabase::addDatabase(m_driver);

    //i = i.remove(QRegExp(QString::fromUtf8("[-`~!@#$%^&*()_€”+=|:;<>«»,.?/{}\'\"")));
   }

BBDD::~BBDD()
{
        m_bdStatus = false;
        disconnet();
}

void BBDD::connect()
{
    if(!m_bdStatus)
    {
        qDebug() << m_db->isValid();
        m_db->setHostName(m_host);
        m_db->setPort(m_port);
        m_db->setDatabaseName(m_databaseName);
        m_db->setUserName(m_username);
        m_db->setPassword(m_password);
        bool ok = m_db->open();
        QSqlError error = m_db->lastError();
        qDebug() << error.text();
        if (ok)
        {
            m_bdStatus = true;
            qDebug() << "Conectado OK";
        }else{
            qDebug() << "Error de conexion";
        }
    }
}

void BBDD::disconnet()
{
    if(m_bdStatus)
    {
        m_db->close();
        m_bdStatus = false;
        qDebug() << "Desconectado OK";
    }
}
