
#include "maintenance.h"
#include "ui_maintenance.h"

#include <QDate>
#include <QDebug>
#include <QDebug>
#include <QLineEdit>
#include <QMessageBox>
#include <QSignalMapper>
#include <QTableWidget>
#include <Qt>
#include <iostream>
#include <qdebug.h>

// chart

// Widget used to display charts
#include <QtCharts/QChartView>

// Used to draw bars representing data provided
// grouped into categories
#include <QtCharts/QBarSeries>

// Represents 1 set of bars in a bar chart
#include <QtCharts/QBarSet>

// Displays the color used to represent each
// QBarSet
#include <QtCharts/QLegend>

// Adds categories to the charts axes
#include <QtCharts/QBarCategoryAxis>

// Used to create stacked bar charts
#include <QtCharts/QHorizontalStackedBarSeries>

// Used to create a line chart
#include <QtCharts/QLineSeries>

// Used to change names on axis
#include <QtCharts/QCategoryAxis>

// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

// Define the scope for your variables and functions
QT_CHARTS_USE_NAMESPACE
using namespace std;

Maintenance::Maintenance(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Maintenance)
{


    ui->setupUi(this);
    Reclamation R ;
   ui->tableView_Reclamations->setStyleSheet("QHeaderView::section { background-color: white ; color :  rgb(192, 128, 129) }");
   ui->tableView_Ressources->setStyleSheet("QHeaderView::section { background-color: white ; color : rgb(192, 128, 129) }");


}



Maintenance::~Maintenance()
{
    delete ui;
}








void Maintenance::on_pushButton_Maintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}






void Maintenance::on_pushButton_backMaintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void Maintenance::on_pushButton_backMaintenance_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

//////////Maintenance

void Maintenance::on_pushButton_Ressource_Materiel_clicked()
{
    RessourceMateriel R ;



    ui->tableView_Ressources->setModel( R.AfficherComposant());

    ////// edit delete buttons
    ///
    ///

    for (int i = 0; i< R.AfficherComposant()->rowCount(); i++)
       {
          QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
          QPushButton *DELETE = new QPushButton("DELETE");     

          DELETE->setStyleSheet("background-color : red;color : white ");

          EDIT->setStyleSheet("background-color : green;color : white ");



          ui->tableView_Ressources->setIndexWidget(ui->tableView_Ressources->model()->index(i, 5), EDIT);
           ui->tableView_Ressources->setIndexWidget(ui->tableView_Ressources->model()->index(i, 6), DELETE);


           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotRessource(int)));
                   connect(DELETE, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELETE, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotRessource(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);


        }
    ////

    ui->stackedWidget->setCurrentIndex(2);


}

void Maintenance::on_pushButton_AnnulerSauvgarderCoomposant_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void Maintenance::on_pushButton_SauvgarderComposant_clicked()
{

   qDebug("bouton: « ajouterPersonne » appuyé");



   QString TYPE = ui->comboBox_typeComp->currentText();
   QString ETAT = ui->comboBox_EtatComp->currentText();
   QString ROUTE = ui->comboBox_NomrouteComp->currentText();
   double POSX=ui->doubleSpinBox_XComp->value();
   double POSY=ui->doubleSpinBox_YComp->value();

   RessourceMateriel R(TYPE,ETAT,ROUTE,POSX,POSY);

   bool test = R.AjouterComposant();

   if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter "),
                    QObject::tr(" ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  ui->stackedWidget->setCurrentIndex(2);


  }
    else
      {  QMessageBox::critical(nullptr, QObject::tr("Ajouter"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }



   ui->tableView_Ressources->setModel( R.AfficherComposant());

   ////// edit delete buttons
   ///
   ///

    for (int i = 0; i< R.AfficherComposant()->rowCount(); i++)
      {
        QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
         QPushButton *DELETE = new QPushButton("DELETE");

         DELETE->setStyleSheet("background-color : red;color : white  ");

         EDIT->setStyleSheet("background-color : green;color : white ");

         ui->tableView_Ressources->setIndexWidget(ui->tableView_Ressources->model()->index(i, 5), EDIT);
          ui->tableView_Ressources->setIndexWidget(ui->tableView_Ressources->model()->index(i, 6), DELETE);


          QSignalMapper *signalMapper = new QSignalMapper(this);
              connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotRessource(int)));
                  connect(DELETE, SIGNAL(clicked()), signalMapper, SLOT(map()));
                  signalMapper->setMapping(DELETE, i);

                  QSignalMapper *signalMapper1 = new QSignalMapper(this);
                      connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotRessource(int)));
                          connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                          signalMapper1->setMapping(EDIT, i);




}

   ////


    ///// init comboboxs
    ui->comboBox_EtatComp->setCurrentIndex(0);
    ui->comboBox_NomrouteComp->setCurrentIndex(0);
    ui->comboBox_NatureRecl->setCurrentIndex(0);
    ui->comboBox_typeComp->setCurrentIndex(0);
    ui->doubleSpinBox_XComp->setValue(0.0);
    ui->doubleSpinBox_YComp->setValue(0.0);


    ///

}

void Maintenance::on_pushButton_AjouterComposant_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}





///////////////// reclamations
///
///
void Maintenance::on_pushButton_Reclamations_clicked()
{
    Reclamation R ;

    ui->tableView_Reclamations->setModel( R.AfficherReclamation());


    ////// edit delete buttons
    ///
    ///
    for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
       {
        QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
          QPushButton *DELETE = new QPushButton("DELETE");

          DELETE->setStyleSheet("background-color : red;color : white ");

          EDIT->setStyleSheet("background-color : green;color : white ");

          ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 5), EDIT);
           ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 6), DELETE);


           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                   connect(DELETE, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELETE, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);


}
    ////
    ui->stackedWidget->setCurrentIndex(3);

}

void Maintenance::on_pushButton_AjouterReclamation_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}


void Maintenance::on_pushButton_Sauvgarder_Reclamation_clicked()
{
    qDebug("bouton: « ajouterPersonne » appuyé");




    QString TYPE =ui->comboBox_TypeRecl->currentText();

    QString ROUTE = ui->comboBox_NomRouteRecl->currentText();

    QString DATE =QDate::currentDate().toString();
    QString NATURE = ui->comboBox_NatureRecl->currentText();

    Reclamation R(ROUTE,TYPE,DATE,1,NATURE);

    bool test = R.AjouterReclamation();
    if(test)
   {

   QMessageBox::information(nullptr, QObject::tr("Ajouter "),
                     QObject::tr(" ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   ui->stackedWidget->setCurrentIndex(3);


   }
     else
       {  QMessageBox::critical(nullptr, QObject::tr("Ajouter"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }


    ui->tableView_Reclamations->setModel( R.AfficherReclamation());

    ////// edit delete buttons
    ///
    ///
    for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
       {
        QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
          QPushButton *DELETE = new QPushButton("DELETE");

          DELETE->setStyleSheet("background-color : red;color : white ");

          EDIT->setStyleSheet("background-color : green;color : white ");

          ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 5), EDIT);
           ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 6), DELETE);


           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                   connect(DELETE, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELETE, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);

}
    ////

    ///int combos !
   ui->comboBox_NatureRecl->setCurrentIndex(0);
   ui->comboBox_TypeRecl->setCurrentIndex(0);
   ui->comboBox_NomRouteRecl->setCurrentIndex(0);


    ///

}

void Maintenance::on_pushButton_Annuler_Reclamation_clicked()
{
    ///int combos !
   ui->comboBox_NatureRecl->setCurrentIndex(0);
   ui->comboBox_TypeRecl->setCurrentIndex(0);
   ui->comboBox_NomRouteRecl->setCurrentIndex(0);


    ///
    ui->stackedWidget->setCurrentIndex(3);

}



//////////////// methodes /////



void Maintenance::DeleteSlotRessource(int i){

    RessourceMateriel R ;


   QString id= ui->tableView_Ressources->model()->index(i,7).data().toString();

     R.SupprimerComposant(id);
     ui->tableView_Ressources->setModel( R.AfficherComposant());

     ////// edit delete buttons
     ///
     ///

      for (int i = 0; i< R.AfficherComposant()->rowCount(); i++)
        {
          QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
           QPushButton *DELETE = new QPushButton("DELETE");

           DELETE->setStyleSheet("background-color : red;color : white  ");

           EDIT->setStyleSheet("background-color : green;color : white ");

           ui->tableView_Ressources->setIndexWidget(ui->tableView_Ressources->model()->index(i, 5), EDIT);
            ui->tableView_Ressources->setIndexWidget(ui->tableView_Ressources->model()->index(i, 6), DELETE);

            QSignalMapper *signalMapper = new QSignalMapper(this);
                connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotRessource(int)));
                    connect(DELETE, SIGNAL(clicked()), signalMapper, SLOT(map()));
                    signalMapper->setMapping(DELETE, i);

                    QSignalMapper *signalMapper1 = new QSignalMapper(this);
                        connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                            connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                            signalMapper1->setMapping(EDIT, i);


  }

     ////
      ui->Reclamation_Serach->setText("");


}

void Maintenance::DeleteSlotReclamation(int i){

    Reclamation R ;


   QString id= ui->tableView_Reclamations->model()->index(i,7).data().toString();


     R.SupprimerReclamation(id);

     ui->tableView_Reclamations->setModel( R.AfficherReclamation());

     ////// edit delete buttons
     ///
     ///

      for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
        {
          QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
           QPushButton *DELETE = new QPushButton("DELETE");

           DELETE->setStyleSheet("background-color : red;color : white  ");

           EDIT->setStyleSheet("background-color : green;color : white ");

           ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 5), EDIT);
            ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 6), DELETE);

            QSignalMapper *signalMapper = new QSignalMapper(this);
                connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                    connect(DELETE, SIGNAL(clicked()), signalMapper, SLOT(map()));
                    signalMapper->setMapping(DELETE, i);
                    QSignalMapper *signalMapper1 = new QSignalMapper(this);
                        connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                            connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                            signalMapper1->setMapping(EDIT, i);


  }

     ////
      ui->Reclamation_Serach->setText("");


}


void Maintenance::ModifierSlotReclamation(int i){


Reclamation R ;


QString id= ui->tableView_Reclamations->model()->index(i,7).data().toString();
QString NATURE= ui->tableView_Reclamations->model()->index(i,4).data().toString();


if( NATURE == "")
{

    ui->comboBox_NatureRecl->setCurrentIndex(1);
    NATURE = ui->comboBox_NatureRecl->currentText();
}
else if(NATURE == "Urgente")
{
     qDebug("INN URGENTE");

    ui->comboBox_NatureRecl->setCurrentIndex(0);
    NATURE = ui->comboBox_NatureRecl->currentText();
}

  R.ModifierReclamation(id,NATURE);

  ui->tableView_Reclamations->setModel( R.AfficherReclamation());

  ////// edit delete buttons
  ///
  ///

   for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
     {
       QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
        QPushButton *DELETE = new QPushButton("DELETE");

        DELETE->setStyleSheet("background-color : red;color : white  ");

        EDIT->setStyleSheet("background-color : green;color : white ");

        ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 5), EDIT);
         ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 6), DELETE);

         QSignalMapper *signalMapper = new QSignalMapper(this);
             connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                 connect(DELETE, SIGNAL(clicked()), signalMapper, SLOT(map()));
                 signalMapper->setMapping(DELETE, i);

                 QSignalMapper *signalMapper1 = new QSignalMapper(this);
                     connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                         connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                         signalMapper1->setMapping(EDIT, i);


}

  ////
   ui->Reclamation_Serach->setText("");


}

void Maintenance:: ModifierSlotRessource(int i){


 RessourceMateriel R ;


 QString id= ui->tableView_Ressources->model()->index(i,7).data().toString();
 QString ETAT_COMP= ui->tableView_Ressources->model()->index(i,1).data().toString();


 if( ETAT_COMP == "Fonctionne")
 {

     ui->comboBox_EtatComp->setCurrentIndex(1);
     ETAT_COMP = ui->comboBox_EtatComp->currentText();
 }
 else if(ETAT_COMP == "En Panne")
 {
      qDebug("INN URGENTE");

     ui->comboBox_EtatComp->setCurrentIndex(0);
     ETAT_COMP = ui->comboBox_EtatComp->currentText();
 }

   R.ModifierComposant(id,ETAT_COMP);

   ui->tableView_Ressources->setModel( R.AfficherComposant());

   ////// edit delete buttons
   ///
   ///

    for (int i = 0; i< R.AfficherComposant()->rowCount(); i++)
      {
        QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
         QPushButton *DELETE = new QPushButton("DELETE");

         DELETE->setStyleSheet("background-color : red;color : white  ");

         EDIT->setStyleSheet("background-color : green;color : white ");

         ui->tableView_Ressources->setIndexWidget(ui->tableView_Ressources->model()->index(i, 5), EDIT);
          ui->tableView_Ressources->setIndexWidget(ui->tableView_Ressources->model()->index(i, 6), DELETE);

          QSignalMapper *signalMapper = new QSignalMapper(this);
              connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotRessource(int)));
                  connect(DELETE, SIGNAL(clicked()), signalMapper, SLOT(map()));
                  signalMapper->setMapping(DELETE, i);

                  QSignalMapper *signalMapper1 = new QSignalMapper(this);
                      connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotRessource(int)));
                          connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                          signalMapper1->setMapping(EDIT, i);


 }

   ////

    ui->Ressource_Search->setText("");
};




/// Search
///
void Maintenance::on_Ressource_Search_textChanged(const QString &arg1)
{
    RessourceMateriel R;
    if(ui->checkBox_NOM_RESS->isChecked())
    {

        ui->tableView_Ressources->setModel( R.chercheComposant(1,arg1));

    }
    else if(ui->checkBox_ETAT_RESS->isChecked())
    {

        ui->tableView_Ressources->setModel( R.chercheComposant(2,arg1));

    }
    else if(ui->checkBox_TYPE_RESS->isChecked())
    {

        ui->tableView_Ressources->setModel( R.chercheComposant(3,arg1));

    }
    else
    {
        ui->tableView_Ressources->setModel( R.chercheComposant(1,arg1));

    }

    if(ui->Ressource_Search->text() == "")
    {
        ui->checkBox_NOM_RESS->setDisabled(false);
        ui->checkBox_TYPE_RESS->setDisabled(false);
        ui->checkBox_ETAT_RESS->setDisabled(false);
        ui->checkBox_NOM_RESS->setChecked(false);
        ui->checkBox_TYPE_RESS->setChecked(false);
        ui->checkBox_ETAT_RESS->setChecked(false);
        ui->tableView_Ressources->setModel( R.AfficherComposant());


    }

    ////// edit delete buttons
    ///
    ///

     for (int i = 0; i< R.AfficherComposant()->rowCount(); i++)
       {
         QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
          QPushButton *DELETE = new QPushButton("DELETE");

          DELETE->setStyleSheet("background-color : red;color : white  ");

          EDIT->setStyleSheet("background-color : green;color : white ");

          ui->tableView_Ressources->setIndexWidget(ui->tableView_Ressources->model()->index(i, 5), EDIT);
           ui->tableView_Ressources->setIndexWidget(ui->tableView_Ressources->model()->index(i, 6), DELETE);

           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotRessource(int)));
                   connect(DELETE, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELETE, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotRessource(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);


 }

    ////


}





void Maintenance::on_checkBox_NOM_RESS_stateChanged(int arg1)
{
    if(ui->checkBox_NOM_RESS->isChecked())
    {
    ui->checkBox_ETAT_RESS->setDisabled(true);
    ui->checkBox_TYPE_RESS->setDisabled(true);
    }
    else
    {
        ui->checkBox_TYPE_RESS->setDisabled(false);
        ui->checkBox_ETAT_RESS->setDisabled(false);
    }
}

void Maintenance::on_checkBox_TYPE_RESS_stateChanged(int arg1)
{

    if(ui->checkBox_TYPE_RESS->isChecked())
    {
        ui->checkBox_NOM_RESS->setDisabled(true);
        ui->checkBox_ETAT_RESS->setDisabled(true);
    }
    else
    {
        ui->checkBox_NOM_RESS->setDisabled(false);
        ui->checkBox_ETAT_RESS->setDisabled(false);
    }
}

void Maintenance::on_checkBox_ETAT_RESS_stateChanged(int arg1)
{

    if(ui->checkBox_ETAT_RESS->isChecked())
    {
        ui->checkBox_TYPE_RESS->setDisabled(true);
        ui->checkBox_NOM_RESS->setDisabled(true);
    }
    else
    {
        ui->checkBox_TYPE_RESS->setDisabled(false);
        ui->checkBox_NOM_RESS->setDisabled(false);
    }
}



//Reclamation





void Maintenance::on_Reclamation_Serach_textChanged(const QString &arg1)
{

    Reclamation R;

    if(ui->checkBox_Route_REc->isChecked())
    {

        ui->tableView_Reclamations->setModel( R.chercheReclamation(2,arg1));

    }
    else if(ui->checkBox_Type_REc->isChecked())
    {

        ui->tableView_Reclamations->setModel( R.chercheReclamation(3,arg1));

    }
    else if(ui->checkBox_nature_REc->isChecked())
    {

        ui->tableView_Reclamations->setModel( R.chercheReclamation(4,arg1));

    }
    else
    {
        ui->tableView_Reclamations->setModel( R.chercheReclamation(2,arg1));

    }

    if(ui->Reclamation_Serach->text() == "")
    {
        ui->checkBox_Type_REc->setDisabled(false);
        ui->checkBox_Route_REc->setDisabled(false);
        ui->checkBox_nature_REc->setDisabled(false);

        ui->checkBox_Type_REc->setChecked(false);
        ui->checkBox_Route_REc->setChecked(false);
        ui->checkBox_nature_REc->setChecked(false);
        ui->tableView_Reclamations->setModel( R.AfficherReclamation());


    }


    ////// edit delete buttons
    ///
    ///

     for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
       {
         QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
          QPushButton *DELETE = new QPushButton("DELETE");

          DELETE->setStyleSheet("background-color : red;color : white  ");

          EDIT->setStyleSheet("background-color : green;color : white ");

          ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 5), EDIT);
           ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 6), DELETE);

           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                   connect(DELETE, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELETE, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);


 }

    ////

}

void Maintenance::on_checkBox_nature_REc_stateChanged(int arg1)
{
    if(ui->checkBox_nature_REc->isChecked())
    {
    ui->checkBox_Type_REc->setDisabled(true);
    ui->checkBox_Route_REc->setDisabled(true);

    }
    else
    {
        ui->checkBox_Type_REc->setDisabled(false);
        ui->checkBox_Route_REc->setDisabled(false);
    }
}

void Maintenance::on_checkBox_Type_REc_stateChanged(int arg1)
{
    if(ui->checkBox_Type_REc->isChecked())
    {
    ui->checkBox_nature_REc->setDisabled(true);
    ui->checkBox_Route_REc->setDisabled(true);

    }
    else
    {
        ui->checkBox_nature_REc->setDisabled(false);
        ui->checkBox_Route_REc->setDisabled(false);
    }
}

void Maintenance::on_checkBox_Route_REc_stateChanged(int arg1)
{
    if(ui->checkBox_Route_REc->isChecked())
    {
    ui->checkBox_nature_REc->setDisabled(true);
    ui->checkBox_Type_REc->setDisabled(true);

    }
    else
    {
        ui->checkBox_nature_REc->setDisabled(false);
        ui->checkBox_Type_REc->setDisabled(false);
    }
}


///


///////// SORTTT

void Maintenance::on_Order_clicked()
{
    Reclamation R;

    if(ui->checkBox_Route_REc->isChecked())
    {

        ui->tableView_Reclamations->setModel( R.Sort(2));

    }
    else if(ui->checkBox_Type_REc->isChecked())
    {

        ui->tableView_Reclamations->setModel( R.Sort(3));

    }
    else if(ui->checkBox_nature_REc->isChecked())
    {

        ui->tableView_Reclamations->setModel(R.Sort(4));

    }
    else if(ui->checkBox_Date->isChecked())
    {

        ui->tableView_Reclamations->setModel( R.Sort(1));

    }
    else
    {
        ui->tableView_Reclamations->setModel( R.Sort(1));

    }

    ////// edit delete buttons
    ///
    ///

     for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
       {
         QPushButton *EDIT = new QPushButton(" CHANGER ETAT");
          QPushButton *DELETE = new QPushButton("DELETE");

          DELETE->setStyleSheet("background-color : red;color : white  ");

          EDIT->setStyleSheet("background-color : green;color : white ");

          ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 5), EDIT);
           ui->tableView_Reclamations->setIndexWidget(ui->tableView_Reclamations->model()->index(i, 6), DELETE);

           QSignalMapper *signalMapper = new QSignalMapper(this);
               connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(DeleteSlotReclamation(int)));
                   connect(DELETE, SIGNAL(clicked()), signalMapper, SLOT(map()));
                   signalMapper->setMapping(DELETE, i);

                   QSignalMapper *signalMapper1 = new QSignalMapper(this);
                       connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(ModifierSlotReclamation(int)));
                           connect(EDIT, SIGNAL(clicked()), signalMapper1, SLOT(map()));
                           signalMapper1->setMapping(EDIT, i);


 }

    ////

}

///

//////////////////Statistics

void Maintenance::on_pushButton_Statistique_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void Maintenance::on_pushButton_clicked()
{
    delete ui->Stat->layout();

     ui->comboBox_stat->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(3);

}

void Maintenance::on_comboBox_stat_currentIndexChanged(int index)
{

    Reclamation R ;
    int p=0,c=0;

    if(index==3)
    {
        for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
          {
            QString type= ui->tableView_Reclamations->model()->index(i,1).data().toString();
            if(type == "canal d'eau"){c++;}
            else{p++;};


          }

        QPieSeries *series = new QPieSeries();
            series->append("Canal D'Eau",c);
            series->append("Poteaux Electirque",p);


            // Add label to 1st slice
            QPieSlice *slice0 = series->slices().at(0);
            slice0->setLabelVisible();
            qDebug()<<p<<""<<c;

            // Add label, explode and define brush for 2nd slice
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setExploded();
            slice1->setLabelVisible();
            slice1->setPen(QPen(Qt::darkGreen, 2));
            slice1->setBrush(Qt::yellow);
            // Create the chart widget
            QChart *chart = new QChart();

            // Add data to chart with title and hide legend
            chart->addSeries(series);
            chart->setTitle("TYPES");
            chart->legend()->hide();

            // Used to display the chart
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            QGridLayout* gridLayout;

            gridLayout = new QGridLayout(ui->Stat);
            gridLayout->addWidget(chartView,0,0);

}

    if(index==1)
    {
        Reclamation R ;
        int Gha=0,Nkhi=0;
        for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
          {
            QString type= ui->tableView_Reclamations->model()->index(i,0).data().toString();
            if(type == "Ghazela"){Gha++;}
            else if(type == "Nkhilette") {Nkhi++;};


          }

        QPieSeries *series = new QPieSeries();
            series->append("Ghazela",Gha);
            series->append("Nkhilette",Nkhi);


            // Add label to 1st slice
            QPieSlice *slice0 = series->slices().at(0);
            slice0->setLabelVisible();
            qDebug()<<p<<""<<c;

            // Add label, explode and define brush for 2nd slice
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setExploded();
            slice1->setLabelVisible();
            slice1->setPen(QPen(Qt::gray, 2));
            slice1->setBrush(Qt::magenta);
            // Create the chart widget
            QChart *chart = new QChart();

            // Add data to chart with title and hide legend
            chart->addSeries(series);
            chart->setTitle("Routes");
            chart->legend()->hide();

            // Used to display the chart
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            QGridLayout* gridLayout;

            gridLayout = new QGridLayout(ui->Stat);
            gridLayout->addWidget(chartView,0,0);

    }


        if(index==2)
        {
            Reclamation R ;
            int urg=0,non=0;
            for (int i = 0; i< R.AfficherReclamation()->rowCount(); i++)
              {
                QString type= ui->tableView_Reclamations->model()->index(i,4).data().toString();
                if(type == "Urgente"){urg++;}
                else{non++;};


              }

            QPieSeries *series = new QPieSeries();
                series->append("Urgente",urg);
                series->append("N'est pas Urgente",non);


                // Add label to 1st slice
                QPieSlice *slice0 = series->slices().at(0);
                slice0->setLabelVisible();
                qDebug()<<p<<""<<c;

                // Add label, explode and define brush for 2nd slice
                QPieSlice *slice1 = series->slices().at(1);
                slice1->setExploded();
                slice1->setLabelVisible();
                slice1->setPen(QPen(Qt::red, 2));
                slice1->setBrush(Qt::green);
                // Create the chart widget
                QChart *chart = new QChart();

                // Add data to chart with title and hide legend
                chart->addSeries(series);
                chart->setTitle("Narure");
                chart->legend()->hide();

                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);

                QGridLayout* gridLayout;

                gridLayout = new QGridLayout(ui->Stat);
                gridLayout->addWidget(chartView,0,0);

        }
       if(ui->comboBox_stat->currentIndex()==0)
        {
           delete ui->Stat->layout();

        }



}
