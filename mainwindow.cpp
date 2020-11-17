#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogevent.h"
#include "dialogetat.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_event_clicked()
{
    Dialogevent dialogevent;
    dialogevent.setModal(true);
    dialogevent.exec();
}

void MainWindow::on_pushButton_etat_clicked()
{
    Dialogetat dialogetat;
    dialogetat.setModal(true);
    dialogetat.exec();
}


void MainWindow::on_MenuP_clicked()
{
    close();
}
