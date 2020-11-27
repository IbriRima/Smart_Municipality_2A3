#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include"ressourcemateriels.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void RemplirTableRessource(QTableWidget* t);
    void Remplir(QTableWidget* t, int i);

private slots:

    void on_pushButton_clicked();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_Ressorces_cellChanged(int row, int column);



private:
    QVector<RessourceMateriels> RessourceMateriels;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
