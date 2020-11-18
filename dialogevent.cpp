#include "dialogevent.h"
#include "ui_dialogevent.h"
#include<QMessageBox>
#include "citoyen.h"
Dialogevent::Dialogevent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogevent)
{
    ui->setupUi(this);
    //ui->tableWidget_etat->setModel(Ctmp.afficher());
}

Dialogevent::~Dialogevent()
{
    delete ui;
}

void Dialogevent::on_tableWidget_etat_cellDoubleClicked(int row, int column)
{
    if(row==0 && column==0)
        ui->stackedWidge_etat->setCurrentIndex(2);
}

void Dialogevent::on_pushButton_clicked()
{
     ui->stackedWidge_etat->setCurrentIndex(1);
}

void Dialogevent::on_pushButton_save_clicked()
{
    //recupération des information saisies
    int id= ui->input_id->text().toInt();
    QString nom= ui->input_nom->text();
    QString prenom= ui->input_prenom->text();
    QString sexe= ui->input_sexe->text();
    QString date= ui->input_naissance->text();
    QString lieu= ui->input_lieu->text();
    QString mail= ui->input_mail->text();
    int tel= ui->input_tel->text().toInt();
    Citoyen C(id,nom,prenom,sexe,date,lieu,mail,tel); //instancier un objet de la classe citoyen
    bool test=C.ajouter(); //insertion de citoyen dans la table
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectuée \n click cancel to exit"),QMessageBox::Cancel);
        //ui->tableWidget_etat->setModel(Ctmp.afficher());  //actualisation de la liste
        ui->stackedWidge_etat->setCurrentIndex(0);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectuée \n click cancel to exit"),QMessageBox::Cancel);
    }
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
    msgB.setText("Le citoyen a été modifié avec succés ");
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

void Dialogevent::on_pushButton_maj_cit_clicked()
{
    ui->stackedWidge_etat->setCurrentIndex(3);
}

void Dialogevent::on_pushButton_del_cit_clicked()
{
    int id=ui->out_id->text().toInt();
    bool test=Ctmp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectuée \n click cancel to exit"),QMessageBox::Cancel);
        //ui->tableWidget_etat->setModel(Ctmp.afficher());  //actualisation de la liste
        ui->stackedWidge_etat->setCurrentIndex(0);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectuée \n click cancel to exit"),QMessageBox::Cancel);

    }
   /* QMessageBox msgB;
    msgB.setText("Le citoyen a été supprimer avec succés ");
    msgB.exec();

    */
}

void Dialogevent::on_pushButton_impression_clicked()
{
    QMessageBox msgB;
    msgB.setText("Limpression commence ");
    msgB.exec();
    ui->stackedWidge_etat->setCurrentIndex(0);
}
