#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
       static Connection c;
       c.createconnect();
       w.show();
       return a.exec();
          }
