#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "marchand.h"
#include "mission.h"
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
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
    void on_ajouter_marchant_clicked();

    void on_modifier_marchand_clicked();

    void on_supprimer_marchand_clicked();

    void on_ajouter_mission_clicked();

    void on_modifier_mission_clicked();

    void on_supprimer_mission_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_recherche_textChanged(const QString &arg1);
    void stat();

    void on_afficher_marchand_activated(const QModelIndex &index);

    void on_afficher_mission_activated(const QModelIndex &index);

    void on_recherche_mission_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    marchand tmp1;
    mission tmp2;
};
#endif // MAINWINDOW_H
