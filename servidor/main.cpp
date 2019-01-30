#include <QCoreApplication>
#include <QDebug>
#include "controlador.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Controlador * ctl = new Controlador();

   return a.exec();

}
