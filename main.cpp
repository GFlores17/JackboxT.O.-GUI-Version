#include "mainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("F:\\Downloads\\Jackbox Logo Icon.ico"));
    MainWindow w;
    w.show();
    return a.exec();
}
