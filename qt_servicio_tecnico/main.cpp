#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    qDebug() << db.isValid();
    db.setHostName("www.3r1k4.com");
    db.setPort(5432);
    db.setDatabaseName("servicio_tecnico");
    db.setUserName("postgres");
    db.setPassword("voldemort872");
    bool ok = db.open();

    QSqlError error = db.lastError();
    qDebug() << error.text();
    qDebug() << "xxxxxxx" ;
    if (ok)
    {

        //db.transaction();
        qDebug() << "Conectado OK";
        for(int x=1;x<10;x++)
        {
           // QUuid uuid = QUuid::createUuid();
            QSqlQuery query;
           // query.exec("INSERT INTO tabla1 (id_tabla1,nombre_tabla11,uuid_tabla1) VALUES ('"+QString::number(x+10)+"','"+QString::number(x)+"','"+uuid.toString()+"')");
           // QSqlQuery query("INSERT INTO tablatest (nombre) VALUES ('x')",db);


           // QSqlQuery query("INSERT INTO tabla1 (nombre_tabla1,uuid_tabla1) VALUES ('x','"+ uuid.toString()+"')", db);
           /* QString lastError = query.lastError().text().trimmed();

            if (!lastError.isEmpty())
            {
             qDebug() << lastError;

            }*/

        }
       QSqlQuery query("SELECT nombre_marcas FROM marcas");

        while(query.next())
        {

             qDebug() << "nombre_marcas" << query.value(1).toString();
        }
       // db.commit();

    } else {
        qDebug() << "Error de conexion";
    } // end if

    return a.exec();
}

