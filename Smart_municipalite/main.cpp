#include "mainwindow.h"

#include <QApplication>
#include<vector>
#include"ressourcemateriels.h"
#include"reclamation.h"

int main(int argc, char *argv[])
{
   QVector<RessourceMateriels> RessourceMateriels;
   QVector<Reclamation> Reclamation;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();





    return a.exec();
}
