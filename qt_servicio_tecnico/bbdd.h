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
     bool m_bdStatus;
protected:
     std::unique_ptr<QSqlDatabase> m_db;
private:
     QString m_driver;
     QString m_host;
     int m_port;
     QString m_databaseName;
     QString m_username;
     QString m_password;
};

#endif // BBDD_H
