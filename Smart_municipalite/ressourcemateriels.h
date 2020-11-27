#ifndef RESSOURCEMATERIELS_H
#define RESSOURCEMATERIELS_H

#include<QString>

class RessourceMateriels
{
public:
    RessourceMateriels();

    QString gen_random();

    void AfficherComposant(QVector<RessourceMateriels> RessourceMateriels);
    void AjouterComposant(RessourceMateriels R);
    RessourceMateriels ModifierComposant(RessourceMateriels R);
    void SupprimerComposant(RessourceMateriels R);
    RessourceMateriels RechercheComposant(RessourceMateriels R );
    void ChangerCouleur();


private:

    QString id_composant;
    QString type_composant;
    int etat_composant;
    QString nom_route;
    double posx_composant;
    double posy_composant;


public:
    QString getId_composant() const;
    void setId_composant(int value);

    QString getType_composant() const;
    void setType_composant(const QString &value);

    int getEtat_composant() const;
    void setEtat_composant(int value);

    double getPosx_composant() const;
    void setPosx_composant(double value);

    double getPosy_composant() const;
    void setPosy_composant(double value);


    QString getNom_route() const;
    void setNom_route(const QString &value);
};

#endif // RESSOURCEMATERIELS_H
