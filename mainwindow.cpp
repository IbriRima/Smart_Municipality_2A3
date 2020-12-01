#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Employe.h"
#include<QMessageBox>
#include "compte.h"
#include<QListWidgetItem>
#include"connection.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtMultimedia/QMediaPlayer>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);



  ui->lineEdit_cin_compte_AJ->setValidator(new QIntValidator(0,99999999, this));
  ui->lineEdit_cin_MAJ_compte->setValidator(new QIntValidator(0,99999999, this));
  ui->lineEdit_cin_employe_AJ->setValidator(new QIntValidator(0,99999999, this));
  ui->lineEdit_cin_employe_MAJ->setValidator(new QIntValidator(0,99999999, this));
  
  ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
  ui->listView_2->setContextMenuPolicy(Qt::CustomContextMenu);
      connect(ui->listView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
      connect(ui->listView_2, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenue(QPoint)));

}

MainWindow::~MainWindow()
{
    delete ui;

}




void MainWindow::on_pushButton_Annuler_compte_MAJ_clicked()
{
    load();
     ui->stackedWidget_resources_humaines->setCurrentIndex(5);
}




void MainWindow::on_pushButton_clicked()
{
    loade();

    ui->stackedWidget_resources_humaines->setCurrentIndex(3);

}


void MainWindow::on_pushButton_Annuler_AJ_clicked()
{
    loade();
    ui->lineEdit_mail_employe_AJ->clear();
    ui->lineEdit_nom_employe_AJ->clear();
    ui->lineEdit_prenom_employe_AJ->clear();

    ui->lineEdit_cin_employe_AJ->clear();

    ui->stackedWidget_resources_humaines->setCurrentIndex(2);
}

void MainWindow::on_pushButton_Annuler_MAJ_clicked()
{
      ui->stackedWidget_resources_humaines->setCurrentIndex(2);
}

void MainWindow::on_pushButton_Save_MAJ_clicked()
{
QString Type;
QString Nom;
QString Prenom;
QString mail;
QString cin;
QString etat;


bool test;
Nom= ui->lineEdit_nom_employe_MAJ->text();
Prenom= ui->lineEdit_prenom_employe_MAJ->text();

mail = ui->lineEdit_mail_employe_MAJ->text();

Type = ui->comboBox_Type_MAJ_compte->currentText();

cin = ui->lineEdit_cin_employe_MAJ->text();

etat = ui->comboBox_etat_employe_MAJ->currentText();

Employe e(Type,Nom,Prenom,cin,mail,etat);
if(!(ui->lineEdit_nom_employe_MAJ->text().isEmpty()||ui->lineEdit_prenom_employe_MAJ->text().isEmpty()||ui->lineEdit_cin_employe_MAJ->text().isEmpty()||ui->lineEdit_mail_employe_MAJ->text().isEmpty()))
{

 test = e.Update();
  }
if(test)

{

    QMessageBox :: information(nullptr, QObject :: tr("compte Modifié"),

                               QObject::tr("compte Modifié"),QMessageBox::Ok);
}

else

{
    QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");


}

}

void MainWindow::on_pushButton_compte_clicked()
{

    load();


    ui->stackedWidget_resources_humaines->setCurrentIndex(5);
}



void MainWindow::on_pushButton_Annuler_compte_clicked()
{
    load();
    ui->lineEdit_Identifiant_compte_AJ->clear();
    ui->lineEdit_mdp_compte_AJ->clear();
    ui->lineEdit_cin_compte_AJ->clear();
    ui->stackedWidget_resources_humaines->setCurrentIndex(5);
}





void MainWindow::on_pushButton_Ajout_compte_clicked()
{
    load();

    ui->stackedWidget_resources_humaines->setCurrentIndex(6);
}





void MainWindow::on_pushButton_Save_compte_MAJ_clicked()
{
    QString Type;
    QString mdp;
    QString Identifiant;
    QString cin;
 bool test;

    Identifiant = ui->lineEdit_ID_MAJ_compte->text();

    mdp = ui->lineEdit_mdp_MAJ_compte->text();

    Type = ui->comboBox_Type_MAJ_compte->currentText();

    cin = ui->lineEdit_cin_MAJ_compte->text();


    compte u(Type,Identifiant,cin,mdp);

    if(!(ui->lineEdit_ID_MAJ_compte->text().isEmpty()||ui->lineEdit_mdp_MAJ_compte->text().isEmpty()||ui->lineEdit_cin_MAJ_compte->text().isEmpty()))
    {

    test = u.Update();
    }

    if(test)

    {

        QMessageBox :: information(nullptr, QObject :: tr("compte Modifié"),

                                   QObject::tr("compte Modifié"),QMessageBox::Ok);
        ui->stackedWidget_resources_humaines->setCurrentIndex(5);

    }

    else

    {

        QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");



    }
    load();


}

void MainWindow::on_pushButton_Menu_compte_clicked()
{
     ui->stackedWidget_resources_humaines->setCurrentIndex(1);
}



//A MODIFIER


void MainWindow::on_pushButton_Close_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_Close_affu_clicked()
{
    QApplication::quit();

}

void MainWindow::on_pushButton_Close_Em_maj_clicked()
{
    QApplication::quit();

}

void MainWindow::on_pushButton_Close_Em_AJ_clicked()
{
     QApplication::quit();
}



void MainWindow::on_pushButton_Close_compte_MAJ_clicked()
{
      QApplication::quit();
}

void MainWindow::on_pushButton_Close_compte_AJ_clicked()
{
      QApplication::quit();
}

void MainWindow::on_pushButton_Close_em_clicked()
{
    QApplication::quit();

}


void MainWindow::on_pushButton_Close_compte_clicked()
{
    QApplication::quit();

}
void MainWindow::on_pushButton_Close_affe_clicked()
{
    QApplication::quit();

}



void MainWindow::on_pushButton_Environ_pressed()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Wassim/Desktop/my work/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_Environ,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,80, 171,41));
         animation->setEndValue(QRect(60,80,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_Environ,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,80, 171,41));
              animation2->setEndValue(QRect(20,80,171,41));
                 animation2->start();
  animation->destroyed() ;
    animation2->destroyed() ;
}

void MainWindow::on_pushButton_Environ_clicked()
{
    ui->stackedWidget_resources_humaines->setCurrentIndex(1);
}



void MainWindow::on_pushButton_Marche_clicked()
{
     ui->stackedWidget_resources_humaines->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Marche_pressed()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Wassim/Desktop/my work/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_Marche,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,140, 171,41));
         animation->setEndValue(QRect(60,140,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_Marche,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,140, 171,41));
              animation2->setEndValue(QRect(20,140,171,41));
                 animation2->start();
                 animation->destroyed() ;
                   animation2->destroyed() ;
}

void MainWindow::on_pushButton_MP_pressed()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Wassim/Desktop/my work/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_MP,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,20, 171,41));
         animation->setEndValue(QRect(60,20,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_MP,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,20, 171,41));
              animation2->setEndValue(QRect(20,20,171,41));
                 animation2->start();
                 animation2->destroyed() ;
                   animation->destroyed() ;
}

void MainWindow::on_pushButton_MP_clicked()
{
     ui->stackedWidget_resources_humaines->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Maintenance_clicked()
{
     ui->stackedWidget_resources_humaines->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Maintenance_pressed()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Wassim/Desktop/my work/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_Maintenance,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,260, 171,41));
         animation->setEndValue(QRect(60,260,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_Maintenance,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,260, 171,41));
              animation2->setEndValue(QRect(20,260,171,41));
                 animation2->start();
                 animation2->destroyed() ;
                   animation->destroyed() ;
}

void MainWindow::on_pushButton_RH_clicked()
{
     ui->stackedWidget_resources_humaines->setCurrentIndex(1);
}

void MainWindow::on_pushButton_RH_pressed()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Wassim/Desktop/my work/Click2.mp3"));
    player->setVolume(50);
    player->play();
    QPropertyAnimation *animation= new QPropertyAnimation(ui->pushButton_RH,"geometry");
         animation->setDuration(2000);
         animation->setStartValue(QRect(20,200, 171,41));
         animation->setEndValue(QRect(60,200,171,41));

         animation->start();

         QPropertyAnimation *animation2= new QPropertyAnimation(ui->pushButton_RH,"geometry");
              animation2->setDuration(1000);
              animation2->setStartValue(QRect(60,200, 171,41));
              animation2->setEndValue(QRect(20,200,171,41));
                 animation2->start();
                 animation2->destroyed() ;
                   animation->destroyed() ;
}

void MainWindow::on_pushButton_employe_clicked()
{
loade();
    ui->stackedWidget_resources_humaines->setCurrentIndex(2);

}

void MainWindow::on_pushButton_Menu_RH_clicked()
{
    ui->stackedWidget_resources_humaines->setCurrentIndex(1);

}

void MainWindow::load()
{
    compte u;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=u.load();
    ui->listView->setModel(model);
}




void MainWindow::showContextMenu(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listView->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;

    myMenu.addAction("Afficher", this, SLOT(viewcompte()));
    myMenu.addAction("Modifier",  this, SLOT(editcompte()));
    myMenu.addAction("Supprimer", this, SLOT(deletecompte()));


    // Show context menu at handling position
    myMenu.exec(globalPos);

}

void MainWindow::viewcompte()
{
   compte u;
           QModelIndex index = ui->listView->currentIndex();

               QString info = index.data(Qt::DisplayRole).toString();
               ui->tableView->setModel(u.read(info));

               ui->stackedWidget_resources_humaines->setCurrentIndex(8);
}

void MainWindow::deletecompte()
{
    compte u;
    QModelIndex index = ui->listView->currentIndex();

    QString info = index.data(Qt::DisplayRole).toString();



            bool test=u.Delete(info);

            if(test)
            {
                 load();
                 QMessageBox::information(this, tr("compte supprimé"),tr("OK"), QMessageBox::Ok);
            }
}

void MainWindow::editcompte()
{
    QModelIndex index = ui->listView->currentIndex();

        QString info = index.data(Qt::DisplayRole).toString();

        QSqlQuery view;

        compte u;

        view=u.editview(info);

        while(view.next())

        {

              ui->lineEdit_ID_MAJ_compte->setText(view.value(0).toString());

              ui->lineEdit_mdp_MAJ_compte->setText(view.value(1).toString());
             // ui->comboBox_Type_MAJ_compte->setText(view.value(2).toString());


              ui->lineEdit_cin_MAJ_compte->setText(view.value(3).toString());

    ui->stackedWidget_resources_humaines->setCurrentIndex(7);


        }



}


void MainWindow::on_pushButton_annuler_aff_clicked()
{
    ui->stackedWidget_resources_humaines->setCurrentIndex(5);
}



void MainWindow::on_pushButton_Save_employe_clicked()
{
    {
    bool test;
    QString Nom,Prenom,mail,cin,Type,etat,Nomtemp;

    Nom = ui->lineEdit_nom_employe_AJ->text();
    Prenom = ui->lineEdit_prenom_employe_AJ->text();

    mail = ui->lineEdit_mail_employe_AJ->text();
    Type = ui->comboBox_Type_employe_AJ->currentText();
    cin = ui->lineEdit_cin_employe_AJ->text();
    etat = ui->comboBox_etat_employe_AJ->currentText();



    Employe E(Type,Nom,Prenom,cin,mail,etat);
    if(!(ui->lineEdit_nom_employe_AJ->text().isEmpty()||ui->lineEdit_prenom_employe_AJ->text().isEmpty()||ui->lineEdit_cin_employe_AJ->text().isEmpty()||ui->lineEdit_mail_employe_AJ->text().isEmpty()))
    {
    test=E.ajouter();
}
    if(test)
    {
        QMessageBox :: information(nullptr, QObject :: tr("ajout employe"),
                                               QObject::tr("employe ajouté"),QMessageBox::Ok);
        ui->stackedWidget_resources_humaines->setCurrentIndex(2);

    }
    else
    {
        QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");


    }


    }

    ui->lineEdit_nom_employe_AJ->clear();
    ui->lineEdit_prenom_employe_AJ->clear();

    ui->lineEdit_mail_employe_AJ->clear();
    ui->lineEdit_cin_employe_AJ->clear();
    loade();




}

void MainWindow::on_pushButton_Save_compte_clicked()
{

    bool test;
    QString Identifiant,mdp,cin,Type;

    Identifiant = ui->lineEdit_Identifiant_compte_AJ->text();
    mdp = ui->lineEdit_mdp_compte_AJ->text();
    Type = ui->comboBox_Type_compte_AJ->currentText();
    cin = ui->lineEdit_cin_compte_AJ->text();

    compte u(Type,Identifiant,cin,mdp);
    if(!(ui->lineEdit_Identifiant_compte_AJ->text().isEmpty()||ui->lineEdit_mdp_compte_AJ->text().isEmpty()||ui->lineEdit_cin_compte_AJ->text().isEmpty()))
    {    test=u.ajouter();
}
    if(test)
    {
        QMessageBox :: information(nullptr, QObject :: tr("compte ajouté"),
                                               QObject::tr("compte ajouté"),QMessageBox::Ok);
        ui->stackedWidget_resources_humaines->setCurrentIndex(5);
    }
    else
    {
        QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");


    }

     ui->lineEdit_Identifiant_compte_AJ->clear();
     ui->lineEdit_mdp_compte_AJ->clear();
     ui->lineEdit_cin_compte_AJ->clear();

     load();



    }









void MainWindow::on_pushButton_affiche_compte_clicked()
{
    load();
}

void MainWindow::loade()
{
    Employe e;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=e.load();
    ui->listView_2->setModel(model);
}




void MainWindow::showContextMenue(const QPoint &pos2)
{
     //Handle global position
   QPoint globalPos2 = ui->listView_2->mapToGlobal(pos2);

    // Create menu and insert some actions
    QMenu myMenu2;
    myMenu2.addAction("Afficher", this, SLOT(viewemploye()));
    myMenu2.addAction("Modifier",  this, SLOT(editemploye()));
    myMenu2.addAction("Supprimer", this, SLOT(deleteemploye()));

    // Show context menu at handling position
    myMenu2.exec(globalPos2);
}

void MainWindow::viewemploye()
{
   Employe e;
           QModelIndex index = ui->listView_2->currentIndex();

               QString info = index.data(Qt::DisplayRole).toString();
               ui->tableView_2->setModel(e.read(info));

               ui->stackedWidget_resources_humaines->setCurrentIndex(9);
}

void MainWindow::deleteemploye()
{
    Employe e;
    QModelIndex index = ui->listView_2->currentIndex();

    QString info = index.data(Qt::DisplayRole).toString();



            bool test=e.Delete(info);

            if(test)
            {
                 loade();
                 QMessageBox::information(this, tr("employe supprimé"),tr("OK"), QMessageBox::Ok);
            }
}

void MainWindow::editemploye()
{
    QModelIndex index = ui->listView_2->currentIndex();

        QString info = index.data(Qt::DisplayRole).toString();

        QSqlQuery view;

        Employe e;

        view=e.editview(info);

        while(view.next())

        {

              ui->lineEdit_nom_employe_MAJ->setText(view.value(0).toString());

              ui->lineEdit_prenom_employe_MAJ->setText(view.value(1).toString());

              ui->lineEdit_mail_employe_MAJ->setText(view.value(2).toString());
              //ui->comboBox_Type_MAJ_compte->currentText(view.value(2).toString());


              ui->lineEdit_cin_employe_MAJ->setText(view.value(3).toString());


              ui->stackedWidget_resources_humaines->setCurrentIndex(4);


        }



}




void MainWindow::on_pushButton_affiche_em_clicked()
{
    loade();
}





void MainWindow::on_pushButton_annuler_affe_clicked()
{
    ui->stackedWidget_resources_humaines->setCurrentIndex(2);

}

void MainWindow::on_pushButton_login_clicked()
{

        QString Identifiant,mdp;
        compte u;
        Identifiant=(ui->Login_identifiant->text());
       mdp=(ui->Login_mdp->text());
    QSqlQuery qry;
            if(qry.exec("SELECT ID,MDP FROM compte Where ID=\'" + Identifiant +"\'AND MDP=\'" +mdp+"\'"))
        {
                if(qry.next())
                {
                    ui->stackedWidget_resources_humaines->setCurrentIndex(1);

                    QMessageBox::information(this,"login"," Bienvenue");


        }
        else
        {
        QMessageBox::information(this,"non existe"," id n'existe pas");
        }

    }
}


void MainWindow::on_lineEdit_recherche_compte_textChanged(const QString &arg1)
{
     compte c;
        QString info =arg1;
        if(info!="")
        ui->listView->setModel(c.chercher(info));
        else
            load();
}




void MainWindow::on_lineEdit_recherche_employe_textChanged(const QString &arg1)
{
    {
         Employe e;
            QString info =arg1;
            if(info!="")
            ui->listView_2->setModel(e.chercher(info));
            else
                loade();
    }

}
