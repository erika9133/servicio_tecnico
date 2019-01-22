#ifndef BBDD_H
#define BBDD_H

#include <QtSql>
#include <QObject>

class BBDD
{
public:
    BBDD();
    ~BBDD();
    void connect();
    void disconnet();
protected:
    QSqlDatabase *m_db;
private:
    QString *m_driver;
    QString *m_host;
    quint16 *m_port;
    QString *m_databaseName;
    QString *m_username;
    QString *m_password;
};

#endif // BBDD_H
