#include "mainwindow.h"

#include <QApplication>
#include "connexion.h"
#include <QMessageBox>
#include <QApplication>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
  connexion c;
  c.ouvrircnx();
  QMessageBox msg;
  MainWindow w;



      w.show();
      return a.exec();
}
