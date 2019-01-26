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
    static void escribir(QString archivo,QString linea);
    static void escribir(QString archivo,QStringList lista);
    static void crearArchivo(QString archivo);
    static QUuid generarUUID();
    static QList<QString> buscarPorUUID(QUuid ID,QString tabla);
    static QString lastError();
};

#endif // UTILS_H
