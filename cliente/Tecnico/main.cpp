#include <QApplication>
#include "aplicacion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Aplicacion app;
    return a.exec();
}
