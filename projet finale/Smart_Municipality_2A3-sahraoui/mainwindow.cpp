#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>


#include <QDate>
#include <QSqlQuery>

#include <QValidator>
#include <QSystemTrayIcon>
#include<QSystemTrayIcon>
#include <QPixmap>

#include "marchand.h"
#include "mission.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->afficher_marchand->setModel(tmp1.afficher());
   ui->afficher_mission->setModel(tmp2.afficher());
MainWindow::stat();
}

MainWindow::~MainWindow()
{
    delete ui;


}
//CRUD marchand



void MainWindow::on_ajouter_marchant_clicked()
{
    QString nom=ui->nom_marchand->text();
    QString prenom=ui->prenom_marchand->text();
    int numero=ui->numero_marchand->text().toInt();
    QString emplacement=ui->emplacement_marchand->text();

    QMessageBox msg;
    marchand m(nom,prenom,emplacement,numero);
    if(m.ajouter()){
           ui->afficher_marchand->setModel(tmp1.afficher());
    }else {
        msg.setText("failed to add");
           msg.exec();
    }


}

void MainWindow::on_modifier_marchand_clicked()
{ int id=ui->id_marchand->text().toInt();

    QString nom=ui->nom_marchand->text();
    QString prenom=ui->prenom_marchand->text();
    int numero=ui->numero_marchand->text().toInt();
    QString emplacement=ui->emplacement_marchand->text();
    QMessageBox msg;
    marchand m(nom,prenom,emplacement,numero);
    if(m.modifier(id)){
          ui->afficher_marchand->setModel(tmp1.afficher());

    }else {
        msg.setText("failed to edit");
           msg.exec();
    }

}



void MainWindow::on_supprimer_marchand_clicked()
{int id=ui->id_marchand->text().toInt();
    marchand m;
    QMessageBox msg;

    if(m.supprimer(id)){
      ui->afficher_marchand->setModel(tmp1.afficher());
    }else {
        msg.setText("failed to delete");
           msg.exec();
    }

}
// crud mission

void MainWindow::on_ajouter_mission_clicked()
{    int cin=ui->cin_mission->text().toInt();
     QString horaire=ui->horaire_mission->text();
     QString date=ui->date_mission->text();
     QString type=ui->type_mission->text();
     QString emplacement=ui->emplacement_mission->text();
      mission m(cin, horaire,date, type , emplacement);
      QMessageBox msg;

      if(m.ajouter()){
       ui->afficher_mission->setModel(tmp2.afficher());
      }else {
          msg.setText("failed to add");
             msg.exec();

      }


}

void MainWindow::on_modifier_mission_clicked()
{int cin=ui->cin_mission->text().toInt();
    QString horaire=ui->horaire_mission->text();
    QString date=ui->date_mission->text();
    QString type=ui->type_mission->text();
    QString emplacement=ui->emplacement_mission->text();
     mission m(cin, horaire,date, type , emplacement);
     QMessageBox msg;
if(m.modifier(cin)){
    ui->afficher_mission->setModel(tmp2.afficher());

}else {
    msg.setText("failed to edit");
       msg.exec();
}

}

void MainWindow::on_supprimer_mission_clicked()
{int cin=ui->cin_mission->text().toInt();
    mission m;
    QMessageBox msg;

    if(m.supprimer(cin)){
      ui->afficher_mission->setModel(tmp2.afficher());
    }else {
        msg.setText("failed to delete");
           msg.exec();
    }


}
//navigation
void MainWindow::on_pushButton_clicked()
{ui->stackedWidget->setCurrentIndex(1);


}

void MainWindow::on_pushButton_2_clicked()
{ui->stackedWidget->setCurrentIndex(2);


}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    MainWindow::stat();

}
//back
void MainWindow::on_pushButton_4_clicked()
{ ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_5_clicked()
{ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//----------les metiers--------------//


//recherche dynamic
void MainWindow::on_recherche_textChanged(const QString &arg1)
{    ui->afficher_marchand->setModel(tmp1.rechercheDynamic(arg1));


}

void MainWindow::on_recherche_mission_textChanged(const QString &arg1)
{

    ui->afficher_mission->setModel(tmp2.rechercheDynamic(arg1));


}
//stat


void MainWindow::stat(){


    QSqlQuery query;

            QString marchand="";
            query.prepare("SELECT COUNT(*) FROM marchand");
            query.exec();
            while(query.next()){
            marchand= query.value(0).toString();}


            QString mission="";
            query.prepare("SELECT COUNT(*) FROM mission");
            query.exec();
            while(query.next()){
            mission= query.value(0).toString();}



        QBarSet *set0 = new QBarSet("mission/marchand");


           *set0 << marchand.toInt()  << mission.toInt()   ;
        QBarSeries *series = new QBarSeries();
         series->append(set0);
         QChart *chart = new QChart();
             chart->addSeries(series);
             chart->setTitle("statistique");
             chart->setAnimationOptions(QChart::SeriesAnimations);

             QStringList categories;
                categories << "nombre mission" <<  "nombre marchand" ;
                QBarCategoryAxis *axisX = new QBarCategoryAxis();
                axisX->append(categories);
                chart->addAxis(axisX, Qt::AlignBottom);
                series->attachAxis(axisX);



                chart->legend()->setVisible(true);
                    chart->legend()->setAlignment(Qt::AlignBottom);

                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->setParent(ui->horizontalFrame);

}


void MainWindow::on_afficher_marchand_activated(const QModelIndex &index)
{
   QString val=ui->afficher_marchand->model()->data(index).toString();
   ui->id_marchand->setText(val);
}

void MainWindow::on_afficher_mission_activated(const QModelIndex &index)
{
    QString val=ui->afficher_mission->model()->data(index).toString();
    ui->cin_mission->setText(val);
}


