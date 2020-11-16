#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Evenement
{   private :
    int Id_event;
    QString Type_event;
    QString Date_event;
    QString Horaire_event;
    QString Empl_event;
    QString Etat_event;
      public :
     //constructeurs
     Evenement();
     Evenement(QString,QString,QString,QString,QString,QString);
     //setters
     void setId(int id) {Id_event=id;}
     void setType(QString type) {Type_event=type;}
     void setDate(QString date) {Date_event=date;}
     void setHor(QString hor) {Horaire_event=hor;}
     void setEmpl(QString empl) {Empl_event=empl;}
     void setEtat(QString etat) {Etat_event=etat;}
     //getters
     int getId(){return Id_event;}
     QString getType(){return Type_event;}
     QString getDate(){return Date_event;}
     QString getHor(){return Horaire_event;}
     QString getEmpl(){return Empl_event;}
     QString getEtat(){return Etat_event;}
     //fonctionnalités de base
     bool ajouter();
     QSqlQueryModel * afficher();
     bool supprimer(int);
     //fonctionnalités avancées

};

#endif // EVENEMENT_H
