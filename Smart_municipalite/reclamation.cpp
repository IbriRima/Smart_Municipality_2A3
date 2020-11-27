#include<QString>
#include "reclamation.h"

Reclamation::Reclamation()
{

}

int Reclamation::getId_reclamation() const
{
    return id_reclamation;
}

void Reclamation::setId_reclamation(int value)
{
    id_reclamation = value;
}

QString Reclamation::getNom_route() const
{
    return nom_route;
}

void Reclamation::setNom_route(const QString &value)
{
    nom_route = value;
}

QString Reclamation::getType_panne() const
{
    return type_panne;
}

void Reclamation::setType_panne(const QString &value)
{
    type_panne = value;
}

Date Reclamation::getDate() const
{
    return date;
}

void Reclamation::setDate(const Date &value)
{
    date = value;
}

int Reclamation::getEtat_reclamation() const
{
    return etat_reclamation;
}

void Reclamation::setEtat_reclamation(int value)
{
    etat_reclamation = value;
}
