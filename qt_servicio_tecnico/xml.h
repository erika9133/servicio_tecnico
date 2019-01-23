#ifndef XML_H
#define XML_H

#include <QObject>

class XML
{
public:
    XML();
   ~XML();
    bool validaXML(const char *archivoXM);
};

#endif // XML_H
