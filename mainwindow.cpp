#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include "evenement.h"
#include "citoyen.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    /************************AFFICHAGE DES TABLES : RAFRAICHIR******************************/
    ui->tableView_event->setModel(Etmp.afficher());
    ui->tableView_citoyen->setModel(Ctmp.afficher());


    /**********************************ICON & ANIMATION**********************************/
    setWindowIcon(QIcon("C:/Users/user/Desktop/logo.jpg"));
    QPixmap pixel ("C:/Users/user/Desktop/logo.jpg");
    ui->icon->setPixmap(pixel.scaled(400,400,Qt::KeepAspectRatio));
    int w= ui->icon->width();
    int h=ui->icon->height();
    animation=new QPropertyAnimation(ui->icon,"geometry");
    animation->setDuration(5000);
    animation->setStartValue(ui->icon->geometry());
    animation->setEndValue(QRect(1100,150,w,h));
    animation->setLoopCount(-1);
    animation->start();
    statistiques();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_event_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView_event->setModel(Etmp.afficher());
}

void MainWindow::on_pushButton_etat_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->tableView_citoyen->setModel(Ctmp.afficher());
}


void MainWindow::on_MenuP_clicked()
{
    close();
}

void MainWindow::on_pushButtonajoutcit_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_save_clicked() /*************************************AJOUT EVENT**********************************/
{

    //recupération des information saisies
    QString id= ui->input_id->text();
    QString nom= ui->input_nom->text();
    QString type= ui->input_type->text();
    QString date= ui->input_date->text();
    QString hor= ui->input_hor->text();
    QString empl= ui->input_empl->text();
    QString etat= ui->input_etat->currentText();
    Evenement E(id,nom,type,date,hor,empl,etat); //instancier un objet de la classe citoyen
    bool controle=E.controle();
    if(controle)
    {
        bool test=E.ajouter(); //insertion de citoyen dans la table
        if (test)
        {
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectuée \n click cancel to exit"),QMessageBox::Cancel);
            ui->tableView_event->setModel(Etmp.afficher());  //actualisation de la liste
            ui->stackedWidget->setCurrentIndex(1);
        }
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectuée \n click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_maj_event_clicked()/********************************AFFICHAGE UPDATE EVENT************************************/
{
    QString ID= ui->out_id->text();
    QSqlQuery query=Etmp.select(ID);

    if(query.exec())
    {
        while(query.next())
        {
            ui->maj_id->setText(query.value(0).toString());
            ui->maj_nom->setText(query.value(1).toString());
            ui->maj_type->setText(query.value(2).toString());
            ui->maj_date->setText(query.value(3).toString());
            ui->maj_hor->setText(query.value(4).toString());
            ui->maj_empl->setText(query.value(5).toString());
            ui->maj_etat->setText(query.value(6).toString());
        }
        ui->stackedWidget->setCurrentIndex(4);
    }

}

void MainWindow::on_pushButton_del_event_clicked() /********************************DELETE EVENT********************************/
{
    QString id=ui->out_id->text();
    bool test=Etmp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectuée \n click cancel to exit"),QMessageBox::Cancel);
        ui->tableView_event->setModel(Etmp.afficher());  //actualisation de la liste

        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectuée \n click cancel to exit"),QMessageBox::Cancel);

    }

}

void MainWindow::on_maj_save_clicked()/****************************SAVE UPDATE EVENT CLICKED***********************************/
{
    QString id= ui->maj_id->text();
    QString nom= ui->maj_nom->text();
    QString type= ui->maj_type->text();
    QString date= ui->maj_date->text();
    QString hor= ui->maj_hor->text();
    QString empl= ui->maj_empl->text();
    QString etat= ui->maj_etat->text();
    Evenement E(id,nom,type,date,hor,empl,etat);
    E.maj(ID);
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView_event->setModel(Etmp.afficher());

}

void MainWindow::on_maj_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
/****************************************************CITOYENS*****************************************************/
void MainWindow::on_ajouter_cit_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_Menu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_recherche_clicked() /*******************************RECHERCHE CITOYEN**********************************/
{
    QString nom = ui->input_recherche->text();
    if(nom=="")
    {
        ui->tableView_citoyen->setModel(Ctmp.afficher());
    }
    else ui->tableView_citoyen->setModel(Ctmp.recherche(nom));
    // ui->tableView_citoyen->setModel(Ctmp.trier());
}

void MainWindow::on_pushButton_save_2_clicked()/********************************SAVE AJOUT CITOYEN***************************************/
{
    //recupération des information saisies
    QString id= ui->input_id_2->text();
    QString nom= ui->input_nom_2->text();
    QString prenom= ui->input_prenom->text();
    QString sexe= ui->input_sexe->currentText();
    QString date= ui->input_naissance->text();
    QString lieu= ui->input_lieu->text();
    QString mail= ui->input_mail->text();
    QString tel= ui->input_tel->text();
    Citoyen C(id,nom,prenom,sexe,date,lieu,mail,tel); //instancier un objet de la classe citoyen
    bool controle=C.controle();
    if(controle)
    {
        bool test=C.ajouter(); //insertion de citoyen dans la table

        if (test)
        {    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectuée \n click cancel to exit"),QMessageBox::Cancel);
            ui->tableView_citoyen->setModel(Ctmp.afficher());  //actualisation de la liste
            ui->stackedWidget->setCurrentIndex(5);
        }
    }
    else   {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectuée \n click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_cancel_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_pushButton_impression_clicked() /*******************************PDF CLICKED***********************************/
{
    QString id,nom,prenom,sexe,date,lieu,mail,tel;
    QSqlQuery query=Ctmp.select(ID);
    if(query.exec())
    {
        while(query.next())
        {
            id= query.value(0).toString();
            nom= query.value(1).toString();
            prenom= query.value(2).toString();
            sexe= query.value(3).toString();
            date= query.value(4).toString();
            lieu= query.value(5).toString();
            mail= query.value(6).toString();
            tel= query.value(7).toString();
        }
        num++;
        Citoyen C(id,nom,prenom,sexe,date,lieu,mail,tel);
        C.printPDF(num);
    }

}

void MainWindow::on_pushButton_maj_cit_clicked() /*******************AFFICHAGE UPDATE CITOYEN***********************************/
{
    QString ID= ui->out_id_2->text();

    QSqlQuery query=Ctmp.select(ID);
    if(query.exec())
    {
        while(query.next())
        {
            ui->maj_id_2->setText(query.value(0).toString());
            ui->maj_nom_2->setText(query.value(1).toString());
            ui->maj_prenom->setText(query.value(2).toString());
            ui->maj_sexe->setText(query.value(3).toString());
            ui->maj_date_cit->setText(query.value(4).toString());
            ui->maj_lieu->setText(query.value(5).toString());
            ui->maj_mail->setText(query.value(6).toString());
            ui->maj_tel->setText(query.value(7).toString());

        }
        ui->stackedWidget->setCurrentIndex(8);

    }
}

void MainWindow::on_pushButton_del_cit_clicked()/********************************DELETE CITOYEN**************************************/
{
    QString id=ui->out_id_2->text();
    bool test=Ctmp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectuée \n click cancel to exit"),QMessageBox::Cancel);
        ui->tableView_citoyen->setModel(Ctmp.afficher());  //actualisation de la liste
        ui->stackedWidget->setCurrentIndex(5);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectuée \n click cancel to exit"),QMessageBox::Cancel);

    }
}


void MainWindow::on_majcit_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_maj_save_2_clicked() /*********************************SAVE UPDATE CITOYEN****************************************/
{

    //recupération des données modifiées
    QString id= ui->maj_id_2->text();
    QString nom= ui->maj_nom_2->text();
    QString prenom= ui->maj_prenom->text();
    QString sexe= ui->maj_sexe->text();
    QString date= ui->maj_date_cit->text();
    QString lieu= ui->maj_lieu->text();
    QString mail= ui->maj_mail->text();
    QString tel= ui->maj_tel->text();
    Citoyen C(id,nom,prenom,sexe,date,lieu,mail,tel);
    C.maj(ID);
    ui->stackedWidget->setCurrentIndex(5);
    ui->tableView_citoyen->setModel(Ctmp.afficher());

}

void MainWindow::on_maj_cancel_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_Menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_tableView_citoyen_activated(const QModelIndex &index) /***********************AFFICHAGE UN CITOYEN ****************************/
{
    QString Id=ui->tableView_citoyen->model()->data(index).toString();
    ID=Id;
    QSqlQuery query=Ctmp.select(ID);
    if(query.exec())
    {
        while(query.next())
        {
            ui->out_id_2->setText(query.value(0).toString());
            ui->out_nom_2->setText(query.value(1).toString());
            ui->out_prenom->setText(query.value(2).toString());
            ui->out_sexe->setText(query.value(3).toString());
            ui->out_naissance->setText(query.value(4).toString());
            ui->out_lieu->setText(query.value(5).toString());
            ui->out_mail->setText(query.value(6).toString());
            ui->out_tel->setText(query.value(7).toString());

        }
        ui->stackedWidget->setCurrentIndex(7);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("citoyen non existant \n click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_tableView_event_activated(const QModelIndex &index)/*****************************AFFICHAGE D'UN EVENT***************************/
{
    QString id=ui->tableView_event->model()->data(index).toString();
    ID=id;
    QSqlQuery query=Etmp.select(ID);
    if(query.exec())
    {
        while(query.next())
        {
            ui->out_id->setText(query.value(0).toString());
            ui->out_nom->setText(query.value(1).toString());
            ui->out_type->setText(query.value(2).toString());
            ui->out_date->setText(query.value(3).toString());
            ui->out_hor->setText(query.value(4).toString());
            ui->out_empl->setText(query.value(5).toString());
            ui->out_etat->setText(query.value(6).toString());

        }
        ui->stackedWidget->setCurrentIndex(3);
    }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("not ok"),QObject::tr("evenement non existant \n click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_exit_clicked()/***********************************CLOSE ALL CLICKED**************************************/
{
    close();
}

void MainWindow::on_pushButton_stat_clicked()/************************AFFICHAGE STATISTIQUES***************************/
{
    //statistiques
    ui->stackedWidget->setCurrentIndex(9);
    statistiques();
}

void MainWindow::on_pushButton_clicked()/*****************************TRIER LES EVENTS**********************************/
{
    QString type= ui->input_tri->currentText();
    int tri=0;
    if(type=="TYPE")
    {
        tri=1;
    }
    else if(type=="ETAT")
    {
        tri=2;
    }
    else tri=3;

    ui->tableView_event->setModel(Etmp.trier(tri));
}
//******************************************************************************
void MainWindow::statistiques()
{
     QPieSeries *series = new QPieSeries();
     int nbpasse= Etmp.passe();
     int nbattente =Etmp.attente();
     int nbannule= Etmp.annule();
        series->append("Passé",nbpasse);
        series->append("En attente",nbattente);
        series->append("Annulé",nbannule);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nombre d'evenements selon l'état");

    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->frame);

}

void MainWindow::on_stat_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
