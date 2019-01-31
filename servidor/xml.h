#ifndef XML_H
#define XML_H

#include <QObject>
#include <QString>
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
    void generarOrden(QUuid id);
    QStringList procesarOrden(QStringList *orden);
    bool validaXML(QString *archivoXML);
    int tipo(QString *recibo);



};

#endif // XML_H
