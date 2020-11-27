#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ressourcemateriels.h"
#include"QString"





void MainWindow::RemplirTableRessource(QTableWidget* t) {
    for(int i=0; i<RessourceMateriels.size(); ++i) {
        t->setItem(i, 0, new QTableWidgetItem(RessourceMateriels[i].getId_composant()));
        t->setItem(i, 1, new QTableWidgetItem(RessourceMateriels[i].getNom_route()));
        t->setItem(i, 2, new QTableWidgetItem(QString(RessourceMateriels[i].getEtat_composant())));
        t->setItem(i, 3, new QTableWidgetItem(RessourceMateriels[i].getType_composant()));
        t->setItem(i, 4, new QTableWidgetItem((RessourceMateriels[i].getPosx_composant())+(RessourceMateriels[i].getPosy_composant())));

        t->setItem(i, 4, new QTableWidgetItem());
       // RessourceMateriels[i].Remplir(t, i);
    }


}

/*void Personne::Remplir(QTableWidget* t, int i) {
    t->setItem(i, 0, new QTableWidgetItem(QString::number(d_id));
    t->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(d_nom));
    t->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(d_prenom));
}  */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    RemplirTableRessource(ui->tableWidget_Ressources);
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
         ui->stackedWidget_RessourceMateriel->setCurrentIndex(1);


}

void MainWindow::on_buttonBox_rejected()
{
    ui->stackedWidget_RessourceMateriel->setCurrentIndex(0);

}

void MainWindow::on_buttonBox_accepted()
{

}



