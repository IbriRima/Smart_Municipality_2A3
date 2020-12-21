#include "mainwindow.h"

#include <QApplication>
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection C;
    QMessageBox msg;
    bool test=C.TestConnection();
    if (test)
      msg.setText("Connection réussite");
    else msg.setText("Connection impossible");
    msg.exec();
   w.show();

    return a.exec();
}
