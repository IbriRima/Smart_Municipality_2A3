#ifndef DIALOGEVENT_H
#define DIALOGEVENT_H

#include <QDialog>

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

private:
    Ui::Dialogevent *ui;
};

#endif // DIALOGEVENT_H
