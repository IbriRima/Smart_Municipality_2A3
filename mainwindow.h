#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<Employe.h>
#include<compte.h>
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





    void on_pushButton_clicked();

    void on_pushButton_Annuler_AJ_clicked();

    void on_pushButton_Annuler_MAJ_clicked();

    void on_pushButton_Save_MAJ_clicked();

    void on_pushButton_compte_clicked();


    void on_pushButton_Annuler_compte_clicked();





    void on_pushButton_Ajout_compte_clicked();


    void on_pushButton_Annuler_compte_MAJ_clicked();

    void on_pushButton_Save_compte_clicked();

    void on_pushButton_Save_compte_MAJ_clicked();

    void on_pushButton_Menu_compte_clicked();






    void on_pushButton_Close_Em_maj_clicked();

    void on_pushButton_Close_Em_AJ_clicked();


    void on_pushButton_Close_compte_MAJ_clicked();

    void on_pushButton_Close_compte_AJ_clicked();









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

void on_pushButton_employe_clicked();

void on_pushButton_Menu_RH_clicked();

void load();

void showContextMenu(const QPoint &pos);

void viewcompte();
void editcompte();
void deletecompte();
void viewemploye();
void editemploye();
void deleteemploye();
void loade();
void showContextMenue(const QPoint &pos);



void on_pushButton_Save_employe_clicked();




void on_pushButton_annuler_aff_clicked();
void on_lineEdit_recherche_compte_textChanged(const QString &arg1);


void on_pushButton_Close_clicked();


void on_pushButton_Close_em_clicked();


void on_pushButton_Close_affu_clicked();

void on_pushButton_Close_affe_clicked();

void on_pushButton_annuler_affe_clicked();

void on_pushButton_login_clicked();

void on_pushButton_Close_compte_clicked();
void on_pushButton_affiche_compte_clicked();
void on_pushButton_affiche_em_clicked();


void on_lineEdit_recherche_employe_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
