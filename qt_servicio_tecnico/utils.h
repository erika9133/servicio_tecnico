#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QStringList>
#include <QString>
#include <QUuid>


class Utils
{
public:
    Utils();
    ~Utils();
    static QStringList leer(QString archivo);
    static QUuid generarUUID();
    static QList<QString> buscarPorUUID(QUuid ID,QString tabla);
};

#endif // UTILS_H
