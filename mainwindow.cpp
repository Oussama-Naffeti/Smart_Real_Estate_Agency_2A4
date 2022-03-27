#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agence.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Ajouter
void MainWindow::on_pushButton_ajouter_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    QString adresse=ui->lineEdit_adresse->text();
    float budget=ui->lineEdit_budget->text().toFloat();
    int nbr_employe=ui->lineEdit_nbr_employe->text().toInt();
    //int nbr_client=ui->lineEdit_nbr_client->text().toInt();
    //int nbr_bien=ui->lineEdit_nbr_bien->text().toInt();
    Agence ag(id,adresse,budget,nbr_employe,0,0);

    if (id == NULL) {
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                  QObject::tr("Il faut saisir un ID !"), QMessageBox::Cancel);
        } else if (adresse == NULL) {
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                  QObject::tr("Il faut saisir une adresse !"), QMessageBox::Cancel);
        } else if (budget == NULL) {
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                  QObject::tr("Il faut saisir un budget !"), QMessageBox::Cancel);
        } else if (nbr_employe == NULL) {
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                  QObject::tr("Il faut saisir un nombre d'employés !"), QMessageBox::Cancel);
        }
    else {
      bool test=ag.ajouter();
     if(test)
    {
         ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("Ajout effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }
              else
                  QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


//Supprimer
void MainWindow::on_pushButton_supprimer_clicked()
{
    int id=ui->lineEdit_supprimer->text().toInt();
    bool test=Etmp.supprimer(id);

    if(test)
    {
         ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("Suppression effectuée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

          }
              else
                  QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    QString adresse=ui->lineEdit_adresse->text();
    float budget=ui->lineEdit_budget->text().toFloat();
    int nbr_employe=ui->lineEdit_nbr_employe->text().toInt();
    Agence ag(id,adresse,budget,nbr_employe,0,0);
    bool test = ag.modifier();
    if (id == NULL) {
            test=false;
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                  QObject::tr("Il faut saisir un ID !"), QMessageBox::Cancel);
        }


if(test)
{
    ui->tableView->setModel(Etmp.afficher());
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("agence modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("agence non modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    Agence ag;
    QString rech=ui->lineEdit_recherche->text();
    ui->tableView->setModel(ag.recherche(rech));
}


void MainWindow::on_pushButton_tri_id_clicked()
{
    Agence ag;
    ui->tableView->setModel(ag.tri_id());
}

void MainWindow::on_pushButton_tri_budget_clicked()
{
    Agence ag;
    ui->tableView->setModel(ag.tri_budget());
}

void MainWindow::on_pushButton_tri_nbr_client_clicked()
{
    Agence ag;
    ui->tableView->setModel(ag.tri_nbr_client());
}

void MainWindow::on_pushButton_tri_nbr_employe_clicked()
{
    Agence ag;
    ui->tableView->setModel(ag.tri_nbr_employe());
}
