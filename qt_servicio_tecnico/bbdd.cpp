#include <QDebug>
#include <QSqlQuery>
#include "bbdd.h"
#include "utils.h"

BBDD::BBDD()
{
    /*
     * 1 QString driver
     * 2 QString host
     * 3 int port
     * 4 QString databasename
     * 5 QString username
     * 6 QString password
     */
    QStringList conf = Utils::leer("configBBDD.txt");

    m_driver = new QString();
    m_host = new QString();
    m_port = new quint16();
    m_databaseName = new QString();
    m_username = new QString();
    m_password = new QString();
    m_db = new QSqlDatabase();

    *m_driver = conf.at(0);
    *m_host = conf.at(1).toUtf8();
    *m_port = conf.at(2).toUShort();
    *m_databaseName = conf.at(3);
    *m_username = conf.at(4);
    *m_password = conf.at(5);
    *m_db = QSqlDatabase::addDatabase(*m_driver);

    //i = i.remove(QRegExp(QString::fromUtf8("[-`~!@#$%^&*()_€”+=|:;<>«»,.?/{}\'\"")));

}

BBDD::~BBDD()
{
    disconnet();
}

void BBDD::connect()
{
    qDebug() << m_db->isValid();
    m_db->setHostName(*m_host);
    m_db->setPort(*m_port);
    m_db->setDatabaseName(*m_databaseName);
    m_db->setUserName(*m_username);
    m_db->setPassword(*m_password);
    bool ok = m_db->open();
    QSqlError error = m_db->lastError();
    qDebug() << error.text();
    if (ok)
    {
        qDebug() << "Conectado OK";
    }else{
        qDebug() << "Error de conexion";
    }

}

void BBDD::disconnet()
{
    m_db->close();
    bool ok = m_db->open();
    if (!ok)
    {
         qDebug() << "Desconectado OK";
    }
}
