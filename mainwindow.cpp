#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "mission.h"
#include "marchant.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddMarchantBTN_clicked()
{

    QString d= QDate::currentDate().toString();
    marchant *m =new marchant();

    int id=m->creat_ID();
    qDebug()<<id;
    m->setNom(ui->nomM->text());
    m->setPrenom(ui->prenomM->text());
    m->setEmpl(ui->emplM->text());
    m->setNum(ui->numM->text());

    if(ui->numM->text()== NULL || ui->nomM->text()==NULL|| ui->prenomM->text()==NULL|| ui->emplM->text()==NULL){
        QMessageBox::critical(nullptr, QObject::tr("Erreur "),
                           QObject::tr("Verifier vos donnés.\n"
                                       "cliqué ok pour continuer."), QMessageBox::Ok);
    }else{
        QMessageBox::information(nullptr, QObject::tr("Bien ajouter "),
                           QObject::tr("les donnés sont bien ajouter.\n"
                                       "cliqué ok pour continuer."), QMessageBox::Ok);
        m->ajouter_marchant(*m);
    }

}

void MainWindow::on_AddMissionBTN_clicked()
{
    QString d= QDate::currentDate().toString();
    mission *m =new mission();

    int id=m->creat_ID();
    qDebug()<<id;
    m->setCin(ui->cinMiss->text().toInt());
    m->setEmplacement(ui->emplMiss->text());
    m->setType(ui->typeMiss->text());
    m->setHoraire(ui->horaireMiss->text());
    m->setDate(d);

    if(ui->emplMiss->text()== NULL || ui->cinMiss->text().toInt()==NULL|| ui->typeMiss->text()==NULL|| ui->horaireMiss->text()==NULL){
        QMessageBox::critical(nullptr, QObject::tr("Erreur "),
                           QObject::tr("Verifier vos donnés.\n"
                                       "cliqué ok pour continuer."), QMessageBox::Ok);
    }else{
        QMessageBox::information(nullptr, QObject::tr("Bien ajouter "),
                           QObject::tr("les donnés sont bien ajouter.\n"
                                       "cliqué ok pour continuer."), QMessageBox::Ok);
        m->ajouter_mission(*m);
    }
}

void MainWindow::on_pushButton_clicked()
{
    mission *m =new mission();
    ui->tableView->setModel(m->afficherAll());

}

void MainWindow::on_pushButton_2_clicked()
{
    marchant *m =new marchant();
    ui->tableView_2->setModel(m->afficherAll());

}

void MainWindow::on_SuppM_clicked()
{
    int ligne = ui->tableView_2->currentIndex().row();
        int id = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 0)).toInt();
        marchant *m =new marchant();
        if(m->supprimerMarchant(id)){
            m->afficherAll();
            QMessageBox::information(nullptr, QObject::tr("Existe "),
                               QObject::tr("la fiche est bien supprimer.\n"
                                           "cliqué ok pour quitter."), QMessageBox::Ok);
        }

}

void MainWindow::on_SuppMiss_clicked()
{
    int ligne = ui->tableView->currentIndex().row();
        int id = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 0)).toInt();
        mission *m =new mission();
        if(m->supprimerMission(id)){
            m->afficherAll();
            QMessageBox::information(nullptr, QObject::tr("Existe "),
                               QObject::tr("la fiche est bien supprimer.\n"
                                           "cliqué ok pour quitter."), QMessageBox::Ok);
        }

}



void MainWindow::on_modifierM_clicked()
{
    int ligne = ui->tableView_2->currentIndex().row();
        int id = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 0)).toInt();
        QString nom = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 1)).toString();
        QString prenom = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 2)).toString();
        QString empl = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 3)).toString();
        QString num = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 4)).toString();
        qDebug()<< nom;
        ui->UNomM->setText(nom);
        ui->UPrenomM->setText(prenom);
        ui->UEmplM->setText(empl);
        ui->UNumM->setText(num);
}

void MainWindow::on_validerMBtn_clicked()
{
    int ligne = ui->tableView_2->currentIndex().row();
       int id = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ligne, 0)).toInt();

//       QString num = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 4)).toString();
//       QString traitement1 = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 5)).toString();
       QString nom = ui->UNomM->text();
       QString prenom = ui->UPrenomM->text();
       QString empl = ui->UEmplM->text();
       QString num = ui->UNumM->text();
       marchant *m =new marchant();
       m->modifierMarchant(id,nom,prenom,empl,num);
}

void MainWindow::on_modifierMiss_clicked()
{
    int ligne = ui->tableView->currentIndex().row();
    int id = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 0)).toInt();
        QString horaire = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 1)).toString();
        QString type = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 2)).toString();
        QString empl = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 3)).toString();

        ui->UEmplMiss->setText(empl);
        ui->UHoraireMiss->setText(horaire);
        ui->UTypeMiss->setText(type);
}

void MainWindow::on_validerMissBtn_clicked()
{
    int ligne = ui->tableView->currentIndex().row();
       int id = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 0)).toInt();

//       QString num = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 4)).toString();
//       QString traitement1 = ui->tableView->model()->data(ui->tableView->model()->index(ligne, 5)).toString();
       QString horaire = ui->UHoraireMiss->text();
       QString type = ui->UTypeMiss->text();
       QString empl = ui->UEmplMiss->text();
       mission *m =new mission();
       m->modifierMission(id,horaire,type,empl);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}
