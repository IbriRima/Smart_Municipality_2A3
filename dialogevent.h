#ifndef DIALOGEVENT_H
#define DIALOGEVENT_H

#include <QDialog>
#include "citoyen.h"
namespace Ui {
class Dialogevent;
}

class Dialogevent : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogevent(QWidget *parent = nullptr);
    ~Dialogevent();

private slots:
    void on_tableWidget_etat_cellDoubleClicked(int row, int column);

    void on_pushButton_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_2_clicked();

    void on_maj_save_clicked();

    void on_maj_cancel_clicked();

    void on_Menu_clicked();

    void on_pushButton_maj_cit_clicked();

    void on_pushButton_del_cit_clicked();

    void on_pushButton_impression_clicked();

private:
    Ui::Dialogevent *ui;
    Citoyen Ctmp;
};

#endif // DIALOGEVENT_H
