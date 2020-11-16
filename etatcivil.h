#ifndef ETATCIVIL_H
#define ETATCIVIL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>

class etatCivil
{
    QString Nom_cit;
    QString Prenom_cit;
    QString Sexe_cit;
    QString Date_cit;
    QString Lieu_cit;
    QString Mail_cit;
    QString Tel_cit;

public:
    etatCivil();


    void setNom(QString nom) {Nom_cit=nom;}
    void setPrenom(QString prenom) {Prenom_cit=prenom;}
    void setSexe(QString sexe) {Sexe_cit=sexe;}
    void setDatec(QString date) {Date_cit=date;}
    void setLieu(QString lieu) {Lieu_cit=lieu;}
    void setMail(QString mail) {Mail_cit=mail;}
    void setTel(QString tel) {Tel_cit=tel;}

    QString getNom(){return Nom_cit;}
    QString getPrenom(){return Prenom_cit;}
    QString getSexe(){return Sexe_cit;}
    QString getDatec(){return Date_cit;}
    QString getLieu(){return Lieu_cit;}
    QString getMail(){return Mail_cit;}
    QString getTel(){return Tel_cit;}
};

#endif // ETATCIVIL_H
