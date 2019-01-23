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
    static void connect();
    static void disconnet();
    static std::unique_ptr<bool> m_bdStatus;
protected:
    static std::unique_ptr<QSqlDatabase> m_db;
private:
    static std::unique_ptr<QString> m_driver;
    static std::unique_ptr<QString> m_host;
    static std::unique_ptr<quint16> m_port;
    static std::unique_ptr<QString> m_databaseName;
    static std::unique_ptr<QString> m_username;
    static std::unique_ptr<QString> m_password;
};

#endif // BBDD_H
