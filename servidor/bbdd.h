#ifndef BBDD_H
#define BBDD_H

#include <QtSql>
#include <QObject>
#include <QVector>
#include <iostream>
#include <QUuid>
#include <memory>

//Se usa para devolver las ordenes de un tecnico
struct OrdenesActivas {
  QUuid id;
  QString cliente;
};

class BBDD{
     /// std::unique_ptr<QSqlDatabase> m_db;
     /// dinamico se borra al destruir bbdd. Para probar. Necesario c++14
     const QString m_driver = "QPSQL";
     QString m_host;
     QString m_databaseName;
     QString m_username;
     QString m_password;



     QSqlDatabase m_db; //almacena la conexion

     bool m_bdStatus;
     int m_port;
     void cargarDatosConfig();

public:
    BBDD();
    ~BBDD();

     //Conexion
     void connect();
     void disconnect();

     //Devolver Datos
     QUuid devolverUuid(const QString registro,const QString tabla);
     QUuid devolverTecnicoMenosOrdenesReparando();
     QUuid devolverOrdenLibre();
     QStringList devolverConsultaDosCondiciones(const QString select,const QString from,const QString where,const QString like);
     QList<OrdenesActivas> devolverOrdenesActicas(const QString tecnico,const QString tipo);
     QString devolverMensajeError(const int id);



     //Verificar datos
     bool verificarLogin(const QString user,const QString pass,const QString tabla);

     //Insertar Dtos
     bool crearOrden(const QString cliente, const QUuid estados_reparacion,
                     const QUuid tecnicos,const QUuid dispositivos, const QUuid listado_tiendas);
     //Mover UTILS AQUI Y terminar en controlador con lo que falte por linkear
     static QStringList leerArchivoLineaPorLinea(const QString archivo);



};
#endif // BBDD_H
