#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "citoyen.h"
#include "evenement.h"
#include <QMainWindow>
#include<QIcon>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QChartView>
#include<QtCharts>
#include<QChart>
#include <QPieSeries>
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
    void on_pushButton_event_clicked();

    void on_pushButton_etat_clicked();


    void on_MenuP_clicked();

    void on_pushButtonajoutcit_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_maj_event_clicked();

    void on_pushButton_del_event_clicked();

    void on_maj_save_clicked();

    void on_maj_cancel_clicked();

    void on_ajouter_cit_clicked();

    void on_Menu_2_clicked();

    void on_recherche_clicked();

    void on_pushButton_save_2_clicked();

    void on_pushButton_cancel_2_clicked();

    void on_pushButton_impression_clicked();

    void on_pushButton_maj_cit_clicked();

    void on_pushButton_del_cit_clicked();

    void on_majcit_cancel_clicked();

    void on_maj_save_2_clicked();

    void on_maj_cancel_2_clicked();

    void on_Menu_clicked();


    void on_tableView_citoyen_activated(const QModelIndex &index);

    void on_tableView_event_activated(const QModelIndex &index);

    void on_exit_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_clicked();

    void statistiques();

    void on_stat_cancel_clicked();

private:
    Ui::MainWindow *ui;
    Citoyen Ctmp;
    Evenement Etmp;
    QString ID;
    QPropertyAnimation *animation;
    int num=0;
};
#endif // MAINWINDOW_H
