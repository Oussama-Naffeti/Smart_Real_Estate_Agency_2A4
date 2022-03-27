/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget_agence;
    QWidget *tab_employe;
    QWidget *tab_client;
    QWidget *tab_agence;
    QPushButton *pushButton_metier2;
    QPushButton *pushButton_metier6;
    QPushButton *pushButton_metier3;
    QPushButton *pushButton_ajouter;
    QGroupBox *groupBox_emplye;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_budget;
    QLineEdit *lineEdit_adresse;
    QLabel *label_4;
    QLineEdit *lineEdit_nbr_employe;
    QLabel *label_5;
    QLineEdit *lineEdit_nbr_client;
    QLabel *label_6;
    QLineEdit *lineEdit_nbr_bien;
    QPushButton *pushButton_metier5;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_metier1;
    QScrollArea *scrollArea_affichage;
    QWidget *scrollAreaWidgetContents_6;
    QPushButton *pushButton_metier4;
    QPushButton *pushButton_modifier;
    QWidget *tab_bien;
    QWidget *tab_reclamation;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(862, 501);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(95, 95, 95);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget_agence = new QTabWidget(centralWidget);
        tabWidget_agence->setObjectName(QStringLiteral("tabWidget_agence"));
        tabWidget_agence->setGeometry(QRect(30, 10, 801, 431));
        tabWidget_agence->setStyleSheet(QStringLiteral("background-color: rgb(87, 126, 255);"));
        tab_employe = new QWidget();
        tab_employe->setObjectName(QStringLiteral("tab_employe"));
        tabWidget_agence->addTab(tab_employe, QString());
        tab_client = new QWidget();
        tab_client->setObjectName(QStringLiteral("tab_client"));
        tabWidget_agence->addTab(tab_client, QString());
        tab_agence = new QWidget();
        tab_agence->setObjectName(QStringLiteral("tab_agence"));
        pushButton_metier2 = new QPushButton(tab_agence);
        pushButton_metier2->setObjectName(QStringLiteral("pushButton_metier2"));
        pushButton_metier2->setGeometry(QRect(180, 20, 75, 23));
        pushButton_metier6 = new QPushButton(tab_agence);
        pushButton_metier6->setObjectName(QStringLiteral("pushButton_metier6"));
        pushButton_metier6->setGeometry(QRect(670, 20, 75, 23));
        pushButton_metier3 = new QPushButton(tab_agence);
        pushButton_metier3->setObjectName(QStringLiteral("pushButton_metier3"));
        pushButton_metier3->setGeometry(QRect(300, 20, 75, 23));
        pushButton_ajouter = new QPushButton(tab_agence);
        pushButton_ajouter->setObjectName(QStringLiteral("pushButton_ajouter"));
        pushButton_ajouter->setGeometry(QRect(110, 350, 75, 23));
        pushButton_ajouter->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        groupBox_emplye = new QGroupBox(tab_agence);
        groupBox_emplye->setObjectName(QStringLiteral("groupBox_emplye"));
        groupBox_emplye->setGeometry(QRect(40, 190, 731, 141));
        groupBox_emplye->setStyleSheet(QStringLiteral("background-color: rgb(90, 170, 72);"));
        label_1 = new QLabel(groupBox_emplye);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(50, 30, 81, 16));
        label_2 = new QLabel(groupBox_emplye);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 70, 47, 14));
        label_3 = new QLabel(groupBox_emplye);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 110, 47, 14));
        lineEdit_id = new QLineEdit(groupBox_emplye);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(160, 30, 113, 20));
        lineEdit_id->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_budget = new QLineEdit(groupBox_emplye);
        lineEdit_budget->setObjectName(QStringLiteral("lineEdit_budget"));
        lineEdit_budget->setGeometry(QRect(160, 110, 113, 20));
        lineEdit_budget->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_adresse = new QLineEdit(groupBox_emplye);
        lineEdit_adresse->setObjectName(QStringLiteral("lineEdit_adresse"));
        lineEdit_adresse->setGeometry(QRect(160, 70, 113, 20));
        lineEdit_adresse->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(groupBox_emplye);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(356, 30, 111, 20));
        lineEdit_nbr_employe = new QLineEdit(groupBox_emplye);
        lineEdit_nbr_employe->setObjectName(QStringLiteral("lineEdit_nbr_employe"));
        lineEdit_nbr_employe->setGeometry(QRect(500, 30, 113, 20));
        lineEdit_nbr_employe->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        label_5 = new QLabel(groupBox_emplye);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(356, 70, 111, 20));
        lineEdit_nbr_client = new QLineEdit(groupBox_emplye);
        lineEdit_nbr_client->setObjectName(QStringLiteral("lineEdit_nbr_client"));
        lineEdit_nbr_client->setGeometry(QRect(500, 70, 113, 20));
        lineEdit_nbr_client->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(groupBox_emplye);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(356, 110, 111, 20));
        lineEdit_nbr_bien = new QLineEdit(groupBox_emplye);
        lineEdit_nbr_bien->setObjectName(QStringLiteral("lineEdit_nbr_bien"));
        lineEdit_nbr_bien->setGeometry(QRect(500, 110, 113, 20));
        lineEdit_nbr_bien->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        pushButton_metier5 = new QPushButton(tab_agence);
        pushButton_metier5->setObjectName(QStringLiteral("pushButton_metier5"));
        pushButton_metier5->setGeometry(QRect(550, 20, 75, 23));
        pushButton_supprimer = new QPushButton(tab_agence);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(610, 350, 75, 23));
        pushButton_metier1 = new QPushButton(tab_agence);
        pushButton_metier1->setObjectName(QStringLiteral("pushButton_metier1"));
        pushButton_metier1->setGeometry(QRect(50, 20, 75, 23));
        scrollArea_affichage = new QScrollArea(tab_agence);
        scrollArea_affichage->setObjectName(QStringLiteral("scrollArea_affichage"));
        scrollArea_affichage->setGeometry(QRect(40, 60, 731, 121));
        scrollArea_affichage->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        scrollArea_affichage->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QStringLiteral("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 729, 119));
        scrollArea_affichage->setWidget(scrollAreaWidgetContents_6);
        pushButton_metier4 = new QPushButton(tab_agence);
        pushButton_metier4->setObjectName(QStringLiteral("pushButton_metier4"));
        pushButton_metier4->setGeometry(QRect(420, 20, 75, 23));
        pushButton_modifier = new QPushButton(tab_agence);
        pushButton_modifier->setObjectName(QStringLiteral("pushButton_modifier"));
        pushButton_modifier->setGeometry(QRect(340, 350, 75, 23));
        tabWidget_agence->addTab(tab_agence, QString());
        tab_bien = new QWidget();
        tab_bien->setObjectName(QStringLiteral("tab_bien"));
        tabWidget_agence->addTab(tab_bien, QString());
        tab_reclamation = new QWidget();
        tab_reclamation->setObjectName(QStringLiteral("tab_reclamation"));
        tabWidget_agence->addTab(tab_reclamation, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 862, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget_agence->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        tabWidget_agence->setTabText(tabWidget_agence->indexOf(tab_employe), QApplication::translate("MainWindow", "Employ\303\251s", Q_NULLPTR));
        tabWidget_agence->setTabText(tabWidget_agence->indexOf(tab_client), QApplication::translate("MainWindow", "Clients", Q_NULLPTR));
        pushButton_metier2->setText(QApplication::translate("MainWindow", "Metier 2", Q_NULLPTR));
        pushButton_metier6->setText(QApplication::translate("MainWindow", "Metier 6", Q_NULLPTR));
        pushButton_metier3->setText(QApplication::translate("MainWindow", "Metier 3", Q_NULLPTR));
        pushButton_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        groupBox_emplye->setTitle(QApplication::translate("MainWindow", "Employ\303\251", Q_NULLPTR));
        label_1->setText(QApplication::translate("MainWindow", "ID de l'agence", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Adresse :", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Budget", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Nombre d'employ\303\251s :", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Nombre de clients :", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Nombre de biens :", Q_NULLPTR));
        pushButton_metier5->setText(QApplication::translate("MainWindow", "Metier 5", Q_NULLPTR));
        pushButton_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        pushButton_metier1->setText(QApplication::translate("MainWindow", "Metier 1", Q_NULLPTR));
        pushButton_metier4->setText(QApplication::translate("MainWindow", "Metier 4", Q_NULLPTR));
        pushButton_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        tabWidget_agence->setTabText(tabWidget_agence->indexOf(tab_agence), QApplication::translate("MainWindow", "Agences", Q_NULLPTR));
        tabWidget_agence->setTabText(tabWidget_agence->indexOf(tab_bien), QApplication::translate("MainWindow", "Biens", Q_NULLPTR));
        tabWidget_agence->setTabText(tabWidget_agence->indexOf(tab_reclamation), QApplication::translate("MainWindow", "R\303\251clamations", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
