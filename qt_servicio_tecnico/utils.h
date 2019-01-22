#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QStringList>
#include <QString>

class Utils
{
public:
    Utils();
    ~Utils();
    static QStringList leer(QString archivo);
};

#endif // UTILS_H
