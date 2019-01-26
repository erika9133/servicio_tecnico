#ifndef BBDD_H
#define BBDD_H

#include <QtSql>
#include <QObject>
#include <iostream>
#include <memory>

class BBDD
{
public:
    BBDD();
    ~BBDD();
     void connect();
     void disconnet();
     std::unique_ptr<bool> m_bdStatus;
protected:
     std::unique_ptr<QSqlDatabase> m_db;
private:
     std::unique_ptr<QString> m_driver;
     std::unique_ptr<QString> m_host;
     std::unique_ptr<quint16> m_port;
     std::unique_ptr<QString> m_databaseName;
     std::unique_ptr<QString> m_username;
     std::unique_ptr<QString> m_password;
};

#endif // BBDD_H
