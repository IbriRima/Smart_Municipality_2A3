#ifndef RECLAMATION_H
#define RECLAMATION_H

#include<QString>
#include"date.h"

class Reclamation
{
public:
    Reclamation();

    void AfficherReclamation();
    void AjouterReclamation();
    Reclamation ModifierReclamation(Reclamation R);
    void SupprimerReclamation(Reclamation R);
    Reclamation RechercheReclamation(Reclamation R);
    void Statistique();




private:
    int id_reclamation;
    QString nom_route;
    QString type_panne;
    Date date;
    int etat_reclamation;


public:
    int getId_reclamation() const;
    void setId_reclamation(int value);

    QString getNom_route() const;
    void setNom_route(const QString &value);

    QString getType_panne() const;
    void setType_panne(const QString &value);

    Date getDate() const;
    void setDate(const Date &value);

    int getEtat_reclamation() const;
    void setEtat_reclamation(int value);




};

#endif // RECLAMATION_H
