#ifndef XML_H
#define XML_H

#include <QObject>
#include <QString>

class XML
{
public:
    XML();
    QString generarConsultaDispositivos(QString consulta);
    QString enerarOrden(QString tienda,QString cliente,QString dispositivo);
};

#endif // XML_H
