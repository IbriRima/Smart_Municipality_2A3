#ifndef ETATCIVIL_H
#define ETATCIVIL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Citoyen
{
    int Id_cit;
    QString Nom_cit;
    QString Prenom_cit;
    QString Sexe_cit;
    QString Date_cit;
    QString Lieu_cit;
    QString Mail_cit;
    int Tel_cit;

public:
    //constructeurs
    Citoyen();
    Citoyen(int id,QString nom,QString prenom,QString sexe,QString date,QString lieu ,QString mail ,int tel);
    //setters
    void setId(int id) {Id_cit=id;}
    void setNom(QString nom) {Nom_cit=nom;}
    void setPrenom(QString prenom) {Prenom_cit=prenom;}
    void setSexe(QString sexe) {Sexe_cit=sexe;}
    void setDatec(QString date) {Date_cit=date;}
    void setLieu(QString lieu) {Lieu_cit=lieu;}
    void setMail(QString mail) {Mail_cit=mail;}
    void setTel(int tel) {Tel_cit=tel;}
    //getter
    int getId(){return Id_cit;}
    QString getNom(){return Nom_cit;}
    QString getPrenom(){return Prenom_cit;}
    QString getSexe(){return Sexe_cit;}
    QString getDatec(){return Date_cit;}
    QString getLieu(){return Lieu_cit;}
    QString getMail(){return Mail_cit;}
    int getTel(){return Tel_cit;}
    //fonctionnalités de base
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    //fonctionnalités avancées
};

#endif // ETATCIVIL_H
