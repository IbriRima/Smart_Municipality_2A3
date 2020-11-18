#include "dialogetat.h"
#include "ui_dialogetat.h"
#include<QMessageBox>
#include "evenement.h"
Dialogetat::Dialogetat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogetat)
{
    ui->setupUi(this);
    //ui->tableWidget_event->setModel(Etmp.afficher());
}

Dialogetat::~Dialogetat()
{
    delete ui;
}

void Dialogetat::on_pushButton_clicked()
{
    ui->stackedWidge_event->setCurrentIndex(1);
}

void Dialogetat::on_pushButton_save_clicked()
{
    //recupération des information saisies
    int id= ui->input_id->text().toInt();
    QString nom= ui->input_nom->text();
    QString type= ui->input_type->text();
    QString date= ui->input_date->text();
    QString hor= ui->input_hor->text();
    QString empl= ui->input_empl->text();
    QString etat= ui->input_etat->text();
    Evenement E(id,nom,type,date,hor,empl,etat); //instancier un objet de la classe citoyen
    bool test=E.ajouter(); //insertion de citoyen dans la table
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectuée \n click cancel to exit"),QMessageBox::Cancel);
        //ui->tableWidget_etat->setModel(Ctmp.afficher());  //actualisation de la liste
        ui->stackedWidge_event->setCurrentIndex(0);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectuée \n click cancel to exit"),QMessageBox::Cancel);
    }

}

void Dialogetat::on_pushButton_cancel_clicked()
{
    ui->stackedWidge_event->setCurrentIndex(0);
}

void Dialogetat::on_pushButton_2_clicked()
{
     ui->stackedWidge_event->setCurrentIndex(0);
}

void Dialogetat::on_tableWidget_etat_cellDoubleClicked(int row, int column)
{
    if(row==0 && column==0)
        ui->stackedWidge_event->setCurrentIndex(2);
}

void Dialogetat::on_maj_save_clicked()
{
    QMessageBox msgB;
    msgB.setText("L'évenement a été modifié avec succés ");
    msgB.exec();
    ui->stackedWidge_event->setCurrentIndex(0);
}

void Dialogetat::on_maj_cancel_clicked()
{
    ui->stackedWidge_event->setCurrentIndex(0);
}


void Dialogetat::on_Menu_clicked()
{
    close();
}

void Dialogetat::on_pushButton_maj_event_clicked()
{
    ui->stackedWidge_event->setCurrentIndex(3);
}

void Dialogetat::on_pushButton_del_event_clicked()
{

    int id=ui->out_id->text().toInt();
    bool test=Etmp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectuée \n click cancel to exit"),QMessageBox::Cancel);
        //ui->tableWidget_event->setModel(Etmp.afficher());  //actualisation de la liste
        ui->stackedWidge_event->setCurrentIndex(0);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectuée \n click cancel to exit"),QMessageBox::Cancel);

    }
    /*QMessageBox msgB;
    msgB.setText("L'évenement a été supprimer avec succés ");
    msgB.exec();
    ui->stackedWidge_event->setCurrentIndex(0); */
}

void Dialogetat::on_pushButton_mail_clicked()
{
    QMessageBox msgB;
    msgB.setText("L'évenement a été envoyé avec succes à votre liste de contact ");
    msgB.exec();
    ui->stackedWidge_event->setCurrentIndex(0);
}
