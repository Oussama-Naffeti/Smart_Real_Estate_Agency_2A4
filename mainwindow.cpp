#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agence.h"
#include"historique.h"
#include "statistique.h"
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include "connection.h"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/qprinter.h>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/qprintdialog.h>
#include <QTextDocument>
#include <QDate>
#include <QTranslator>
#include <qtranslator.h>




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
    //QString adresse=ui->lineEdit_adresse->text();
    QString adresse=ui->comboBox_adresse->currentText();
    float budget=ui->lineEdit_budget->text().toFloat();
    int nbr_employe=ui->lineEdit_nbr_employe->text().toInt();
    //int nbr_client=ui->lineEdit_nbr_client->text().toInt();
    //int nbr_bien=ui->lineEdit_nbr_bien->text().toInt();
    Agence ag(id,adresse,budget,nbr_employe,0,0);
    int k=ag.get_id();

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
          else if (ag.agence_exist(ui->lineEdit_supprimer->text().toInt()) != 0) {
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("Agence Déja existante ! \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        }
    else {
      bool test=ag.ajouter();
     if(test)
    {
         ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("Ajout effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        QString textajouter;
        historique h;
        QSqlQuery qry;
        qry.prepare("select * from AGENCE");
        textajouter="L'ajout d'une agence a la base de donnees d' ID : "+QString::number(k)+" a ete effectue avec succees";
        h.write(textajouter);

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
    Agence ag;
    if (ui->lineEdit_supprimer->text().isEmpty())
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("veuillez entrer un id.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    else if (ag.agence_exist(ui->lineEdit_supprimer->text().toInt())==0)
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("Agence n'existe pas.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    else {
    int id=ui->lineEdit_supprimer->text().toInt();
    int k=id;
    bool test=Etmp.supprimer(id);

    if(test)
    {
         ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("Suppression effectuée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        QString textajouter;
        historique h;
        QSqlQuery qry;
        qry.prepare("select * from AGENCE");
        textajouter="La suppression d'une agence a la base de donnees d' ID : "+QString::number(k)+" a ete effectue avec succees";
        h.write(textajouter);

          }
              else
                  QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
}

/*void MainWindow::on_pushButton_supprimer_2_clicked()
{
    if (ui->lineEditID->text().isEmpty())
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("veuillez entrer un id.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    else if (cl.clientExist(ui->lineEditID->text().toInt())==0)
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("employee n'existe pas.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    else {
    int id=ui->lineEditID->text().toInt();
    ui->lineEditID->clear();
    bool test=cl.supprimer(id);

    ui->tableau->setModel(cl.afficher());
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Suppression effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("not nok"),
                               QObject::tr("Suppression non effectué\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}}
*/

void MainWindow::on_pushButton_modifier_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    //QString adresse=ui->lineEdit_adresse->text();
    QString adresse=ui->comboBox_adresse->currentText();
    float budget=ui->lineEdit_budget->text().toFloat();
    int nbr_employe=ui->lineEdit_nbr_employe->text().toInt();
    Agence ag(id,adresse,budget,nbr_employe);
    int k=ag.get_id();
    if (ui->lineEdit_id->text().isEmpty())
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("veuillez entrer un id.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    else if (ag.agence_exist(ui->lineEdit_id->text().toInt())==0)
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("Agence n'existe pas.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    else {

        bool test = ag.modifier();

if(test)
{
    ui->tableView->setModel(Etmp.afficher());
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("agence modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    QString textajouter;
    historique h;
    QSqlQuery qry;
    qry.prepare("select * from AGENCE");
    textajouter="La modification d'une agence a la base de donnees d' ID : "+QString::number(k)+" a ete effectue avec succees";
    h.write(textajouter);

}
else
    QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("agence non modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
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






void MainWindow::on_pushButton_statistique_clicked()
{
    statistique s;
    s.exec();
}

void MainWindow::on_pushButton_imprimer_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tableView->model()->rowCount();
                const int columnCount = ui->tableView->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title> LISTE DES PRODUITS<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> **LISTE DES AGENCES ** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tableView->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tableView->isColumnHidden(column)) {
                            QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                //QPrinter printer;
                QPrinter printer;

                QPrintDialog *test = new QPrintDialog(&printer, NULL);
                if (test->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;

}

void MainWindow::on_pushButton_traduction_clicked()
{
    QMessageBox::information(this,QObject::tr("Notice"),QObject::tr("Langue: Francais"),QMessageBox::Yes);

}
