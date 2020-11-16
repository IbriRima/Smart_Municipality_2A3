#include "dialogevent.h"
#include "ui_dialogevent.h"
#include<QMessageBox>
Dialogevent::Dialogevent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogevent)
{
    ui->setupUi(this);
}

Dialogevent::~Dialogevent()
{
    delete ui;
}

void Dialogevent::on_tableWidget_etat_cellDoubleClicked(int row, int column)
{
    if(row==0 && column==0)
        ui->stackedWidge_etat->setCurrentIndex(2);
    if(row==0 && column==7)
        ui->stackedWidge_etat->setCurrentIndex(3);
    if(row==0 && column==8)
    {
        QMessageBox msgB;
        msgB.setText("Le citoyen a été supprimer avec succés ");
        msgB.exec();
        ui->stackedWidge_etat->setCurrentIndex(0);
    }
    if(row==0 && column==9)
    {
        QMessageBox msgB;
        msgB.setText("Limpression commence ");
        msgB.exec();
        ui->stackedWidge_etat->setCurrentIndex(0);
    }
}

void Dialogevent::on_pushButton_clicked()
{
     ui->stackedWidge_etat->setCurrentIndex(1);
}

void Dialogevent::on_pushButton_save_clicked()
{
    QMessageBox msgB;
    msgB.setText("Le citoyen a été enregistré avec succes ");
    msgB.exec();
    ui->stackedWidge_etat->setCurrentIndex(0);
}

void Dialogevent::on_pushButton_cancel_clicked()
{
     ui->stackedWidge_etat->setCurrentIndex(0);
}

void Dialogevent::on_pushButton_2_clicked()
{
     ui->stackedWidge_etat->setCurrentIndex(0);
}

void Dialogevent::on_maj_save_clicked()
{
    QMessageBox msgB;
    msgB.setText("L'évenement a été modifié avec succés ");
    msgB.exec();
    ui->stackedWidge_etat->setCurrentIndex(0);
}

void Dialogevent::on_maj_cancel_clicked()
{
     ui->stackedWidge_etat->setCurrentIndex(0);
}

void Dialogevent::on_Menu_clicked()
{
    close();
}
