#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"ramassage.h"
#include"zone_verte.h"
#include"capteur_humidite.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


   // void createTable_Ramassage(Ramassage R);
   // void createTableZV(Zone_Verte Z);

    void on_pushButton_clicked();

    void on_pushButton_Save_AJ_clicked();

    void on_pushButton_Annuler_AJ_clicked();

    void on_pushButton_Annuler_MAJ_clicked();

    void on_pushButton_SaveR_MAJ_clicked();

    void on_pushButton_ZV_clicked();

    void on_pushButton_Annuler_ZV_clicked();

    void on_pushButton_Menu_Environ_Aff_clicked();

    void on_pushButton_Ajout_ZV_clicked();

    void on_pushButton_Annuler_ZV_MAJ_clicked();

    void on_pushButton_Save_ZV_clicked();

    void on_pushButton_Save_ZV_MAJ_clicked();

    void on_pushButton_Menu_Environ_Aff_ZV_clicked();

    void on_pushButton_Close_Envir_clicked();

    void on_pushButton_Close_Envir_2_clicked();

    void on_pushButton_Close_Envir_3_clicked();

    void on_pushButton_Close_Envir_4_clicked();

    void on_pushButton_Close_Envir_5_clicked();

    void on_pushButton_Close_Envir_6_clicked();

    void on_pushButton_Close_Envir_8_clicked();


    void on_pushButton_Environ_pressed();

    void on_pushButton_Environ_clicked();

    void on_pushButton_Marche_clicked();

    void on_pushButton_Marche_pressed();

    void on_pushButton_MP_pressed();

    void on_pushButton_MP_clicked();

    void on_pushButton_Maintenance_clicked();

    void on_pushButton_Maintenance_pressed();

    void on_pushButton_RH_clicked();

    void on_pushButton_RH_pressed();


    void on_pushButton_R_clicked();

    void on_tableView_ZV_activated(const QModelIndex &index);

    void on_tableView_Ramas_activated(const QModelIndex &index);

    void on_pushButton_MAJ_Ramas_clicked();

    void on_pushButton_MAJ_ZV_clicked();


    void on_pushButton_Delete_Ramas_clicked();



    void on_pushButton_Sup_ZV_clicked();






void on_lineEdit_recherche_ZV_returnPressed();

void on_lineEdit_recherche_R_returnPressed();


void on_pushButton_StatR_clicked();


void on_pushButton_Menu_Environ_Aff_2_clicked();


void on_comboBox_TypeRech_Ramas_currentIndexChanged(int index);
void on_comboBox_TypeRech_ZV_currentIndexChanged(int index);


void on_pushButton_Imprimer_clicked();

void on_pushButton_Print_clicked();

void on_pushButton_Menu_Environ_Aff_3_clicked();

void update_label();


void on_ON_clicked();

void on_Date_Stat_dateChanged(const QDate &date);


void on_comboBox_Type_Tri_activated(int index);

void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Zone_Verte tmpZV;
    Ramassage tmpR,tmpR2;
   Capteur_humidite C;
   QByteArray data;

};
#endif // MAINWINDOW_H
