#include "dialogetat.h"
#include "ui_dialogetat.h"
#include<QMessageBox>
Dialogetat::Dialogetat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogetat)
{
    ui->setupUi(this);
}

Dialogetat::~Dialogetat()
{
    delete ui;
}

void Dialogetat::on_pushButton_clicked()
{
    ui->stackedWidge_etat->setCurrentIndex(1);
}

void Dialogetat::on_pushButton_save_clicked()
{
    QMessageBox msgB;
    msgB.setText("L'évenement a été enregistré avec succes ");
    msgB.exec();
    ui->stackedWidge_etat->setCurrentIndex(0);
}

void Dialogetat::on_pushButton_cancel_clicked()
{
    ui->stackedWidge_etat->setCurrentIndex(0);
}

void Dialogetat::on_pushButton_2_clicked()
{
     ui->stackedWidge_etat->setCurrentIndex(0);
}

void Dialogetat::on_tableWidget_etat_cellDoubleClicked(int row, int column)
{
    if(row==0 && column==0)
        ui->stackedWidge_etat->setCurrentIndex(2);
    if(row==0 && column==6)
        ui->stackedWidge_etat->setCurrentIndex(3);
    if(row==0 && column==7)
    {
        QMessageBox msgB;
        msgB.setText("L'évenement a été supprimer avec succés ");
        msgB.exec();
        ui->stackedWidge_etat->setCurrentIndex(0);
    }
    if(row==0 && column==8)
    {
        QMessageBox msgB;
        msgB.setText("L'évenement a été envoyé avec succes à votre liste de contact ");
        msgB.exec();
        ui->stackedWidge_etat->setCurrentIndex(0);
    }
}

void Dialogetat::on_maj_save_clicked()
{
    QMessageBox msgB;
    msgB.setText("L'évenement a été modifié avec succés ");
    msgB.exec();
    ui->stackedWidge_etat->setCurrentIndex(0);
}

void Dialogetat::on_maj_cancel_clicked()
{
    ui->stackedWidge_etat->setCurrentIndex(0);
}


void Dialogetat::on_Menu_clicked()
{
    close();
}
