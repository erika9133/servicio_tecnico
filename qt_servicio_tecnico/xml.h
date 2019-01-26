#ifndef XML_H
#define XML_H

#include <QObject>
#include <QStringList>
#include <QUuid>
#include <QFile>
#include <QXmlInputSource>
#include <QDomDocument>



class XML : public QObject
{
    Q_OBJECT

public:
    XML();
   ~XML();
    QStringList *m_dtd;
    void GenerarOrden(QUuid id);
    void RecibirOrden();
    bool validaXML(QString *archivoXML);
    int tipo(QString *archivoXML);




};

#endif // XML_H
