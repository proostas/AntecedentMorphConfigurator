#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("StasProkofyev");
    QCoreApplication::setOrganizationDomain("prokofyev.me");
    QCoreApplication::setApplicationName("AntecedentMorphConfigurator");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
