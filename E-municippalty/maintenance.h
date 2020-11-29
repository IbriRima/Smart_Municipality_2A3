#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QMainWindow>
#include<QVector>
#include <QTableWidget>
#include"reclamation.h"
#include"ressourcemateriel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Maintenance; }
QT_END_NAMESPACE

class Maintenance : public QMainWindow
{
    Q_OBJECT

public:
    Maintenance(QWidget *parent = nullptr);
    ~Maintenance();

  //  void enregis(int i , QString nature);
   // void Statistique();
public  slots:
    void DeleteSlotRessource(int);
    void DeleteSlotReclamation(int);

    void ModifierSlotRessource(int);
    void ModifierSlotReclamation(int);

    void on_pushButton_Maintenance_clicked();

    void on_pushButton_Ressource_Materiel_clicked();

    void on_pushButton_Reclamations_clicked();

    void on_pushButton_backMaintenance_clicked();

    void on_pushButton_backMaintenance_2_clicked();

    void on_pushButton_AnnulerSauvgarderCoomposant_clicked();

    void on_pushButton_SauvgarderComposant_clicked();

    void on_pushButton_AjouterComposant_clicked();

    void on_pushButton_Sauvgarder_Reclamation_clicked();

    void on_pushButton_Annuler_Reclamation_clicked();

    void on_pushButton_AjouterReclamation_clicked();





private slots:
    void on_Ressource_Search_textChanged(const QString &arg1);

    void on_checkBox_NOM_RESS_stateChanged(int arg1);

    void on_checkBox_TYPE_RESS_stateChanged(int arg1);

    void on_checkBox_ETAT_RESS_stateChanged(int arg1);


    void on_checkBox_nature_REc_stateChanged(int arg1);

    void on_checkBox_Type_REc_stateChanged(int arg1);

    void on_checkBox_Route_REc_stateChanged(int arg1);

    void on_Reclamation_Serach_textChanged(const QString &arg1);

    void on_Order_clicked();

    void on_pushButton_Statistique_clicked();

    void on_pushButton_clicked();

    void on_comboBox_stat_currentIndexChanged(int index);

private:
    Ui::Maintenance *ui;
    Reclamation Rec;
    RessourceMateriel Res;
};
#endif // MAINTENANCE_H
