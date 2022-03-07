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

void MainWindow::on_pushButton_ajouter_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    QString adresse=ui->lineEdit_adresse->text();
    float budget=ui->lineEdit_budget->text().toFloat();
    int nbr_employe=ui->lineEdit_nbr_employe->text().toInt();
    int nbr_client=ui->lineEdit_nbr_client->text().toInt();
    int nbr_bien=ui->lineEdit_nbr_bien->text().toInt();
    Agence ag(id,adresse,budget,nbr_employe,nbr_client,nbr_bien);

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
