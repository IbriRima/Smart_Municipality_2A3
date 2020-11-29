/********************************************************************************
** Form generated from reading UI file 'maintenance.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTENANCE_H
#define UI_MAINTENANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Maintenance
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton_Maintenance;
    QWidget *page_2;
    QPushButton *pushButton_Reclamations;
    QPushButton *pushButton_Ressource_Materiel;
    QWidget *page_3;
    QPushButton *pushButton_AjouterComposant;
    QPushButton *pushButton_backMaintenance;
    QLineEdit *Ressource_Search;
    QCheckBox *checkBox_TYPE_RESS;
    QCheckBox *checkBox_NOM_RESS;
    QCheckBox *checkBox_ETAT_RESS;
    QTableView *tableView_Ressources;
    QWidget *page_4;
    QPushButton *pushButton_AjouterReclamation;
    QPushButton *pushButton_backMaintenance_2;
    QPushButton *pushButton_Statistique;
    QTableView *tableView_Reclamations;
    QLineEdit *Reclamation_Serach;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_Route_REc;
    QCheckBox *checkBox_Type_REc;
    QCheckBox *checkBox_nature_REc;
    QCheckBox *checkBox_Date;
    QPushButton *Order;
    QWidget *page_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_XComp;
    QDoubleSpinBox *doubleSpinBox_YComp;
    QComboBox *comboBox_NomrouteComp;
    QComboBox *comboBox_typeComp;
    QPushButton *pushButton_SauvgarderComposant;
    QPushButton *pushButton_AnnulerSauvgarderCoomposant;
    QComboBox *comboBox_EtatComp;
    QLabel *label_9;
    QWidget *page_6;
    QLabel *label_5;
    QPushButton *pushButton_Sauvgarder_Reclamation;
    QComboBox *comboBox_NomRouteRecl;
    QLabel *label_6;
    QPushButton *pushButton_Annuler_Reclamation;
    QLabel *label_7;
    QComboBox *comboBox_NatureRecl;
    QComboBox *comboBox_TypeRecl;
    QWidget *page_7;
    QComboBox *comboBox_stat;
    QPushButton *pushButton;
    QWidget *Stat;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Maintenance)
    {
        if (Maintenance->objectName().isEmpty())
            Maintenance->setObjectName(QStringLiteral("Maintenance"));
        Maintenance->resize(1249, 608);
        Maintenance->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"\n"
""));
        centralwidget = new QWidget(Maintenance);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 20, 1201, 531));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        pushButton_Maintenance = new QPushButton(page);
        pushButton_Maintenance->setObjectName(QStringLiteral("pushButton_Maintenance"));
        pushButton_Maintenance->setGeometry(QRect(730, 170, 181, 111));
        pushButton_Maintenance->setAutoFillBackground(false);
        pushButton_Maintenance->setStyleSheet(QLatin1String("background-color: rgb(223, 149, 0);\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-left-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);\n"
"font: 8pt \"MS Sans Serif\";\n"
"\n"
""));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_Reclamations = new QPushButton(page_2);
        pushButton_Reclamations->setObjectName(QStringLiteral("pushButton_Reclamations"));
        pushButton_Reclamations->setGeometry(QRect(320, 250, 191, 71));
        pushButton_Reclamations->setStyleSheet(QLatin1String("QPushButton#pushButton_Reclamations {\n"
"                   border-image: url(assest/Reclamation.png);\n"
"\n"
"\n"
"                   }\n"
"QPushButton#pushButton_Reclamations:hover {\n"
"                   border-image: url(assest/Reclamation_hover.png);\n"
"                   }; \n"
""));
        pushButton_Ressource_Materiel = new QPushButton(page_2);
        pushButton_Ressource_Materiel->setObjectName(QStringLiteral("pushButton_Ressource_Materiel"));
        pushButton_Ressource_Materiel->setGeometry(QRect(670, 250, 191, 71));
        pushButton_Ressource_Materiel->setStyleSheet(QLatin1String("QPushButton#pushButton_Ressource_Materiel {\n"
"                   border-image: url(assest/Ressource Materiels.png);\n"
"\n"
"\n"
"                   }\n"
"QPushButton#pushButton_Ressource_Materiel:hover {\n"
"                   border-image: url(assest/Ressource Materiels_hover.png);\n"
"                   }; \n"
""));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        pushButton_AjouterComposant = new QPushButton(page_3);
        pushButton_AjouterComposant->setObjectName(QStringLiteral("pushButton_AjouterComposant"));
        pushButton_AjouterComposant->setGeometry(QRect(100, 50, 131, 41));
        pushButton_AjouterComposant->setStyleSheet(QLatin1String("QPushButton#pushButton_AjouterComposant {\n"
"                   border-image: url(assest/Ajouter Composant.png);\n"
"\n"
"\n"
"                   }\n"
"QPushButton#pushButton_AjouterComposant:hover {\n"
"                   border-image: url(assest/Ajouter Composant_hover.png);\n"
"                   }; "));
        pushButton_backMaintenance = new QPushButton(page_3);
        pushButton_backMaintenance->setObjectName(QStringLiteral("pushButton_backMaintenance"));
        pushButton_backMaintenance->setGeometry(QRect(1040, 10, 111, 41));
        pushButton_backMaintenance->setStyleSheet(QLatin1String("\n"
"QPushButton#pushButton_backMaintenance {\n"
"\n"
"                   border-image: url(assest/Maintenance.png);\n"
"\n"
"                   }\n"
"QPushButton#pushButton_backMaintenance:hover {\n"
"                   border-image: url(assest/Maintenance_hover.png);\n"
"\n"
"                   }; "));
        Ressource_Search = new QLineEdit(page_3);
        Ressource_Search->setObjectName(QStringLiteral("Ressource_Search"));
        Ressource_Search->setGeometry(QRect(1050, 80, 113, 22));
        Ressource_Search->setFrame(true);
        Ressource_Search->setCursorPosition(0);
        checkBox_TYPE_RESS = new QCheckBox(page_3);
        checkBox_TYPE_RESS->setObjectName(QStringLiteral("checkBox_TYPE_RESS"));
        checkBox_TYPE_RESS->setGeometry(QRect(860, 80, 81, 20));
        checkBox_NOM_RESS = new QCheckBox(page_3);
        checkBox_NOM_RESS->setObjectName(QStringLiteral("checkBox_NOM_RESS"));
        checkBox_NOM_RESS->setGeometry(QRect(750, 80, 91, 16));
        checkBox_ETAT_RESS = new QCheckBox(page_3);
        checkBox_ETAT_RESS->setObjectName(QStringLiteral("checkBox_ETAT_RESS"));
        checkBox_ETAT_RESS->setGeometry(QRect(950, 80, 81, 20));
        tableView_Ressources = new QTableView(page_3);
        tableView_Ressources->setObjectName(QStringLiteral("tableView_Ressources"));
        tableView_Ressources->setGeometry(QRect(10, 110, 1181, 411));
        tableView_Ressources->setFrameShape(QFrame::Box);
        tableView_Ressources->horizontalHeader()->setCascadingSectionResizes(false);
        tableView_Ressources->horizontalHeader()->setDefaultSectionSize(200);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        pushButton_AjouterReclamation = new QPushButton(page_4);
        pushButton_AjouterReclamation->setObjectName(QStringLiteral("pushButton_AjouterReclamation"));
        pushButton_AjouterReclamation->setGeometry(QRect(100, 50, 131, 41));
        pushButton_AjouterReclamation->setStyleSheet(QLatin1String("\n"
"QPushButton#pushButton_AjouterReclamation {\n"
"\n"
"                   border-image: url(assest/Ajouter Reclamation.png);\n"
"\n"
"\n"
"                   }\n"
"QPushButton#pushButton_AjouterReclamation:hover {\n"
"                   border-image: url(assest/Ajouter Reclamation_hover.png);\n"
"\n"
"                   }; "));
        pushButton_backMaintenance_2 = new QPushButton(page_4);
        pushButton_backMaintenance_2->setObjectName(QStringLiteral("pushButton_backMaintenance_2"));
        pushButton_backMaintenance_2->setGeometry(QRect(1040, 10, 111, 41));
        pushButton_backMaintenance_2->setStyleSheet(QLatin1String("QPushButton#pushButton_backMaintenance_2 {\n"
"\n"
"                   border-image: url(assest/Maintenance.png);\n"
"\n"
"                   }\n"
"QPushButton#pushButton_backMaintenance_2:hover {\n"
"                   border-image: url(assest/Maintenance_hover.png);\n"
"\n"
"                   }; "));
        pushButton_Statistique = new QPushButton(page_4);
        pushButton_Statistique->setObjectName(QStringLiteral("pushButton_Statistique"));
        pushButton_Statistique->setGeometry(QRect(890, 10, 111, 41));
        pushButton_Statistique->setStyleSheet(QLatin1String("QPushButton#pushButton_Statistique {\n"
"\n"
"                   border-image: url(assest/Statistique.png);\n"
"\n"
"                   }\n"
"QPushButton#pushButton_Statistique:hover {\n"
"                   border-image: url(assest/Statistique_hover.png);\n"
"\n"
"                   }; "));
        tableView_Reclamations = new QTableView(page_4);
        tableView_Reclamations->setObjectName(QStringLiteral("tableView_Reclamations"));
        tableView_Reclamations->setGeometry(QRect(10, 120, 1181, 401));
        tableView_Reclamations->horizontalHeader()->setCascadingSectionResizes(false);
        tableView_Reclamations->horizontalHeader()->setDefaultSectionSize(200);
        Reclamation_Serach = new QLineEdit(page_4);
        Reclamation_Serach->setObjectName(QStringLiteral("Reclamation_Serach"));
        Reclamation_Serach->setGeometry(QRect(1070, 90, 113, 22));
        Reclamation_Serach->setFrame(true);
        Reclamation_Serach->setCursorPosition(0);
        layoutWidget = new QWidget(page_4);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(660, 90, 373, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(37);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(21, 0, 0, 0);
        checkBox_Route_REc = new QCheckBox(layoutWidget);
        checkBox_Route_REc->setObjectName(QStringLiteral("checkBox_Route_REc"));

        horizontalLayout->addWidget(checkBox_Route_REc);

        checkBox_Type_REc = new QCheckBox(layoutWidget);
        checkBox_Type_REc->setObjectName(QStringLiteral("checkBox_Type_REc"));

        horizontalLayout->addWidget(checkBox_Type_REc);

        checkBox_nature_REc = new QCheckBox(layoutWidget);
        checkBox_nature_REc->setObjectName(QStringLiteral("checkBox_nature_REc"));

        horizontalLayout->addWidget(checkBox_nature_REc);

        checkBox_Date = new QCheckBox(page_4);
        checkBox_Date->setObjectName(QStringLiteral("checkBox_Date"));
        checkBox_Date->setGeometry(QRect(550, 90, 92, 20));
        Order = new QPushButton(page_4);
        Order->setObjectName(QStringLiteral("Order"));
        Order->setGeometry(QRect(420, 80, 93, 28));
        Order->setStyleSheet(QLatin1String("background-color: rgb(217, 63, 67);\n"
"color :rblack;"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        label = new QLabel(page_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(390, 60, 161, 61));
        label->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(191, 56, 88)\n"
"\n"
""));
        label_2 = new QLabel(page_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(390, 210, 161, 61));
        label_2->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"\n"
"color: rgb(191, 56, 88)\n"
""));
        label_3 = new QLabel(page_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(390, 280, 161, 61));
        label_3->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"\n"
"color: rgb(191, 56, 88)\n"
""));
        label_4 = new QLabel(page_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 350, 161, 51));
        label_4->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"\n"
"color: rgb(191, 56, 88)\n"
""));
        doubleSpinBox_XComp = new QDoubleSpinBox(page_5);
        doubleSpinBox_XComp->setObjectName(QStringLiteral("doubleSpinBox_XComp"));
        doubleSpinBox_XComp->setGeometry(QRect(570, 300, 91, 31));
        doubleSpinBox_XComp->setStyleSheet(QStringLiteral("background-color: rgb(217, 63, 67);"));
        doubleSpinBox_YComp = new QDoubleSpinBox(page_5);
        doubleSpinBox_YComp->setObjectName(QStringLiteral("doubleSpinBox_YComp"));
        doubleSpinBox_YComp->setGeometry(QRect(570, 360, 91, 31));
        doubleSpinBox_YComp->setStyleSheet(QStringLiteral("background-color: rgb(217, 63, 67);"));
        comboBox_NomrouteComp = new QComboBox(page_5);
        comboBox_NomrouteComp->setObjectName(QStringLiteral("comboBox_NomrouteComp"));
        comboBox_NomrouteComp->setGeometry(QRect(550, 220, 141, 31));
        comboBox_NomrouteComp->setStyleSheet(QLatin1String("background-color: rgb(217, 63, 67);\n"
"font: 75 8pt \"MS Shell Dlg 2\";"));
        comboBox_typeComp = new QComboBox(page_5);
        comboBox_typeComp->setObjectName(QStringLiteral("comboBox_typeComp"));
        comboBox_typeComp->setGeometry(QRect(560, 80, 131, 31));
        comboBox_typeComp->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(217, 63, 67);"));
        pushButton_SauvgarderComposant = new QPushButton(page_5);
        pushButton_SauvgarderComposant->setObjectName(QStringLiteral("pushButton_SauvgarderComposant"));
        pushButton_SauvgarderComposant->setGeometry(QRect(800, 390, 111, 41));
        pushButton_SauvgarderComposant->setStyleSheet(QLatin1String("QPushButton#pushButton_SauvgarderComposant {\n"
"\n"
"                   border-image: url(assest/Sauvgarder.png);\n"
"\n"
"\n"
"                   }\n"
"QPushButton#pushButton_SauvgarderComposant:hover {\n"
"                   border-image: url(assest/Sauvgarder_hover.png);\n"
"\n"
"                   }; "));
        pushButton_AnnulerSauvgarderCoomposant = new QPushButton(page_5);
        pushButton_AnnulerSauvgarderCoomposant->setObjectName(QStringLiteral("pushButton_AnnulerSauvgarderCoomposant"));
        pushButton_AnnulerSauvgarderCoomposant->setGeometry(QRect(780, 440, 111, 41));
        pushButton_AnnulerSauvgarderCoomposant->setStyleSheet(QLatin1String("QPushButton#pushButton_AnnulerSauvgarderCoomposant {\n"
"\n"
"                   border-image: url(assest/ANNULER.png);\n"
"\n"
"\n"
"\n"
"                   }\n"
"QPushButton#pushButton_AnnulerSauvgarderCoomposant:hover {\n"
"                   border-image: url(assest/ANNULER_hover.png);\n"
"\n"
"                   }; "));
        comboBox_EtatComp = new QComboBox(page_5);
        comboBox_EtatComp->setObjectName(QStringLiteral("comboBox_EtatComp"));
        comboBox_EtatComp->setGeometry(QRect(560, 150, 131, 31));
        comboBox_EtatComp->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(217, 63, 67);"));
        label_9 = new QLabel(page_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(390, 130, 161, 61));
        label_9->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(191, 56, 88)\n"
"\n"
""));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        label_5 = new QLabel(page_6);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(400, 200, 161, 61));
        label_5->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(191, 56, 88)\n"
""));
        pushButton_Sauvgarder_Reclamation = new QPushButton(page_6);
        pushButton_Sauvgarder_Reclamation->setObjectName(QStringLiteral("pushButton_Sauvgarder_Reclamation"));
        pushButton_Sauvgarder_Reclamation->setGeometry(QRect(820, 380, 111, 41));
        pushButton_Sauvgarder_Reclamation->setStyleSheet(QLatin1String("QPushButton#pushButton_Sauvgarder_Reclamation {\n"
"\n"
"                   border-image: url(assest/Sauvgarder.png);\n"
"\n"
"\n"
"                   }\n"
"QPushButton#pushButton_Sauvgarder_Reclamation:hover {\n"
"                   border-image: url(assest/Sauvgarder_hover.png);\n"
"\n"
"                   }; "));
        comboBox_NomRouteRecl = new QComboBox(page_6);
        comboBox_NomRouteRecl->setObjectName(QStringLiteral("comboBox_NomRouteRecl"));
        comboBox_NomRouteRecl->setGeometry(QRect(560, 210, 141, 31));
        comboBox_NomRouteRecl->setStyleSheet(QStringLiteral("background-color: rgb(217, 63, 67);"));
        label_6 = new QLabel(page_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(400, 290, 161, 51));
        label_6->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(191, 56, 88)\n"
""));
        pushButton_Annuler_Reclamation = new QPushButton(page_6);
        pushButton_Annuler_Reclamation->setObjectName(QStringLiteral("pushButton_Annuler_Reclamation"));
        pushButton_Annuler_Reclamation->setGeometry(QRect(800, 430, 111, 41));
        pushButton_Annuler_Reclamation->setStyleSheet(QLatin1String("QPushButton#pushButton_Annuler_Reclamation {\n"
"\n"
"                   border-image: url(assest/ANNULER.png);\n"
"\n"
"\n"
"\n"
"                   }\n"
"QPushButton#pushButton_Annuler_Reclamation:hover {\n"
"                   border-image: url(assest/ANNULER_hover.png);\n"
"\n"
"                   }; "));
        label_7 = new QLabel(page_6);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(400, 110, 161, 61));
        label_7->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(191, 56, 88)\n"
""));
        comboBox_NatureRecl = new QComboBox(page_6);
        comboBox_NatureRecl->setObjectName(QStringLiteral("comboBox_NatureRecl"));
        comboBox_NatureRecl->setGeometry(QRect(560, 300, 131, 31));
        comboBox_NatureRecl->setStyleSheet(QStringLiteral("background-color: rgb(217, 63, 67);"));
        comboBox_TypeRecl = new QComboBox(page_6);
        comboBox_TypeRecl->setObjectName(QStringLiteral("comboBox_TypeRecl"));
        comboBox_TypeRecl->setGeometry(QRect(570, 120, 131, 31));
        comboBox_TypeRecl->setStyleSheet(QStringLiteral("background-color: rgb(217, 63, 67);"));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        comboBox_stat = new QComboBox(page_7);
        comboBox_stat->setObjectName(QStringLiteral("comboBox_stat"));
        comboBox_stat->setGeometry(QRect(20, 50, 91, 31));
        comboBox_stat->setStyleSheet(QStringLiteral("background-color: rgb(217, 63, 67);"));
        pushButton = new QPushButton(page_7);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1090, 490, 93, 28));
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(217, 63, 67);\n"
"color:black;"));
        Stat = new QWidget(page_7);
        Stat->setObjectName(QStringLiteral("Stat"));
        Stat->setGeometry(QRect(130, 50, 1001, 401));
        stackedWidget->addWidget(page_7);
        Maintenance->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Maintenance);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1249, 26));
        Maintenance->setMenuBar(menubar);
        statusbar = new QStatusBar(Maintenance);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Maintenance->setStatusBar(statusbar);

        retranslateUi(Maintenance);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Maintenance);
    } // setupUi

    void retranslateUi(QMainWindow *Maintenance)
    {
        Maintenance->setWindowTitle(QApplication::translate("Maintenance", "Maintenance", Q_NULLPTR));
        pushButton_Maintenance->setText(QApplication::translate("Maintenance", "Maintenance", Q_NULLPTR));
        pushButton_Reclamations->setText(QString());
        pushButton_Ressource_Materiel->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_AjouterComposant->setToolTip(QApplication::translate("Maintenance", "<html><head/><body><p>Ajouter Un Comlposant</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_AjouterComposant->setText(QString());
        pushButton_backMaintenance->setText(QString());
#ifndef QT_NO_TOOLTIP
        Ressource_Search->setToolTip(QApplication::translate("Maintenance", "search", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Ressource_Search->setInputMask(QString());
        Ressource_Search->setText(QString());
        Ressource_Search->setPlaceholderText(QApplication::translate("Maintenance", "search", Q_NULLPTR));
        checkBox_TYPE_RESS->setText(QApplication::translate("Maintenance", "Type ", Q_NULLPTR));
        checkBox_NOM_RESS->setText(QApplication::translate("Maintenance", " Route", Q_NULLPTR));
        checkBox_ETAT_RESS->setText(QApplication::translate("Maintenance", "Etat", Q_NULLPTR));
        pushButton_AjouterReclamation->setText(QString());
        pushButton_backMaintenance_2->setText(QString());
        pushButton_Statistique->setText(QString());
#ifndef QT_NO_TOOLTIP
        Reclamation_Serach->setToolTip(QApplication::translate("Maintenance", "search", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Reclamation_Serach->setInputMask(QString());
        Reclamation_Serach->setText(QString());
        Reclamation_Serach->setPlaceholderText(QApplication::translate("Maintenance", "search", Q_NULLPTR));
        checkBox_Route_REc->setText(QApplication::translate("Maintenance", "Route", Q_NULLPTR));
        checkBox_Type_REc->setText(QApplication::translate("Maintenance", "Type", Q_NULLPTR));
        checkBox_nature_REc->setText(QApplication::translate("Maintenance", "Nature", Q_NULLPTR));
        checkBox_Date->setText(QApplication::translate("Maintenance", "Date", Q_NULLPTR));
        Order->setText(QApplication::translate("Maintenance", "Order", Q_NULLPTR));
        label->setText(QApplication::translate("Maintenance", "Type de Composant :", Q_NULLPTR));
        label_2->setText(QApplication::translate("Maintenance", "Nom de Route :", Q_NULLPTR));
        label_3->setText(QApplication::translate("Maintenance", "PosX composant :", Q_NULLPTR));
        label_4->setText(QApplication::translate("Maintenance", "Posy Composant :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        doubleSpinBox_XComp->setToolTip(QApplication::translate("Maintenance", "<html><head/><body><p>Donner la position suivant (x)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        doubleSpinBox_YComp->setToolTip(QApplication::translate("Maintenance", "<html><head/><body><p>Donner la position suivant (y)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        comboBox_NomrouteComp->clear();
        comboBox_NomrouteComp->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Maintenance", "Ghazela", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_NomrouteComp->setToolTip(QApplication::translate("Maintenance", "<html><head/><body><p>Choisir le nom de route</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        comboBox_typeComp->clear();
        comboBox_typeComp->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Maintenance", "Poteau Electrique", Q_NULLPTR)
         << QApplication::translate("Maintenance", "Canal d'Eau", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_typeComp->setToolTip(QApplication::translate("Maintenance", "<html><head/><body><p>Choisir le type de composant !</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox_typeComp->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButton_SauvgarderComposant->setText(QString());
        pushButton_AnnulerSauvgarderCoomposant->setText(QString());
        comboBox_EtatComp->clear();
        comboBox_EtatComp->insertItems(0, QStringList()
         << QApplication::translate("Maintenance", "Fonctionne", Q_NULLPTR)
         << QApplication::translate("Maintenance", "En Panne", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_EtatComp->setToolTip(QApplication::translate("Maintenance", "<html><head/><body><p>Choisir le type de composant !</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox_EtatComp->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        label_9->setText(QApplication::translate("Maintenance", "Etat de Composant :", Q_NULLPTR));
        label_5->setText(QApplication::translate("Maintenance", "Nom de Route :", Q_NULLPTR));
        pushButton_Sauvgarder_Reclamation->setText(QString());
        comboBox_NomRouteRecl->clear();
        comboBox_NomRouteRecl->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Maintenance", "Ghazela", Q_NULLPTR)
         << QApplication::translate("Maintenance", "Nkhilette", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_NomRouteRecl->setToolTip(QApplication::translate("Maintenance", "<html><head/><body><p>Choisir le nom de route</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("Maintenance", "Nature de Reclamation", Q_NULLPTR));
        pushButton_Annuler_Reclamation->setText(QString());
        label_7->setText(QApplication::translate("Maintenance", "Type de Reclamation :", Q_NULLPTR));
        comboBox_NatureRecl->clear();
        comboBox_NatureRecl->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Maintenance", "Urgente", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_NatureRecl->setToolTip(QApplication::translate("Maintenance", "<html><head/><body><p>Choisir la nature de Reclamation</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        comboBox_TypeRecl->clear();
        comboBox_TypeRecl->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Maintenance", "potraux electrique", Q_NULLPTR)
         << QApplication::translate("Maintenance", "canal d'eau", Q_NULLPTR)
        );
        comboBox_stat->clear();
        comboBox_stat->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Maintenance", "Routes", Q_NULLPTR)
         << QApplication::translate("Maintenance", "Nature", Q_NULLPTR)
         << QApplication::translate("Maintenance", "Type", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("Maintenance", "Retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Maintenance: public Ui_Maintenance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTENANCE_H
