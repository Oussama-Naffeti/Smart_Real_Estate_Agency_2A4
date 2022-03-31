#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "statistique.h"
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include "connection.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QDate>
#include "statistiques.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_emp->setModel(e.afficher());
}
void MainWindow::refresh(){
    ui->tab_emp->setModel(e.afficher());
                     }


MainWindow::~MainWindow()
{
    delete ui;
}





/* void MainWindow::on_pushButton_clicked()
{
    QString id =ui-> lineEdit_id->text();

    QString mdp=ui-> lineEdit_mdp->text();

    if ((id == "admin" &&  mdp == "admin")||(id =="agent" && mdp == "agent") ||(id =="respcom" && mdp == "respcom") )
    {
         QMessageBox::information(this,"Login","id et mot de passe correct !");
    }

else {
       QMessageBox::warning(this,"Login","id et mot de passe incorrect !");
    }
}
  */

void MainWindow::on_ajouter_clicked()
{

    QString nom = ui->nom->text();
        QString prenom = ui->prenom->text();
        QString adresse = ui->adresse->currentText();
        QString email =ui->email->text();
        QString ref_agence = ui->ref_agence->text();
        double salaire = ui->salaire->text().toDouble();
        int id = ui->id->text().toInt();
        QString mdp=ui->mdp->text();

        Employe e(id,nom,prenom,adresse,email,ref_agence,salaire,mdp);

        if (id == NULL) {
                    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                          QObject::tr("Il faut saisir un ID !"), QMessageBox::Cancel);
                }
        else if (nom == NULL) {
                    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                          QObject::tr("Il faut saisir un nom !"), QMessageBox::Cancel);
                }
        else if (prenom== NULL) {
                    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                          QObject::tr("Il faut saisir un prenom !"), QMessageBox::Cancel);
                }
        else if (adresse == NULL) {
                    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                          QObject::tr("Il faut saisir une adresse !"), QMessageBox::Cancel);
                }
        else if (email== NULL) {
                    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                          QObject::tr("Il faut saisir un email !"), QMessageBox::Cancel);
                }
        else if (ref_agence == NULL) {
                    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                          QObject::tr("Il faut saisir une reference !"), QMessageBox::Cancel);
                }
        else if (salaire == NULL) {
                    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                          QObject::tr("Il faut saisir un salaire !"), QMessageBox::Cancel);
                }
        else if (mdp == NULL) {
                    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                          QObject::tr("Il faut saisir un salaire !"), QMessageBox::Cancel);
                }
        else {
            bool test=e.ajouter();
            if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Succès"),
                            QObject::tr("employe ajouté avec succès.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_emp->setModel(e.afficher());
            }
    }

}
void MainWindow::on_pushButton_supprimer_clicked() //supprimer
{
    Employe e1;
    if (ui->id_supp->text().isEmpty())
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("veuillez entrer un id.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    else if (e1.employeExist(ui->id_supp->text().toInt())==0)
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("employee n'existe pas.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    else {
    e1.set_id(ui->id_supp->text().toInt());


       bool test=e1.supprimer(e1.get_id());

       if (test)
       {
          ui->tab_emp->setModel(e1.afficher());
           QMessageBox::information(nullptr, QObject::tr("Succès"),
                       QObject::tr("Employé supprimé avec succès.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }}
}

void MainWindow::on_pushButton_afficher_clicked()
{
    ui->tab_emp->setModel(e.afficher());
}
void MainWindow::on_pushButton_modifier_clicked()
{
    QString nom = ui->nom_modif->text();
    QString prenom = ui->prenom_modif->text();
    QString adresse =ui->adresse_modif->currentText();
    QString email = ui->email_modif->text();
    QString agence = ui->agence_modif->text();
    double salaire = ui->salaire_modif->text().toDouble();
    int id = ui->id_modif->text().toInt();
    QString mdp=ui->mdp_2->text();


    QSqlQuery verif,query1,query2,query3,query4,query5,query6;
                        //chnage name
    verif.prepare("SELECT ID FROM EMPLOYE WHERE EXISTS (SELECT * FROM EMPLOYE e WHERE ? = e.ID)");
                     verif.addBindValue(id);
                     verif.exec();
                     verif.next();
                     if (verif.value(0).toBool())
                     {
                         QMessageBox::information(nullptr,"Information"," Employé modifié avec succès !");
                            query1.prepare("UPDATE EMPLOYE SET NOM = ? WHERE ID = ?");
                            query1.addBindValue(nom);

                            query1.addBindValue(id);
                              query1.exec();
                              //chnage prenom
                              query2.prepare("UPDATE EMPLOYE SET PRENOM = ? WHERE ID = ?");
                              query2.addBindValue(prenom);

                              query2.addBindValue(id);
                              query2.exec();
                              //change mail
                              query3.prepare("UPDATE EMPLOYE SET ADRESSE_EMPLOYE = ? WHERE ID = ?");
                              query3.addBindValue(adresse);

                              query3.addBindValue(id);
                              query3.exec();
                              //chnage phone
                              query4.prepare("UPDATE EMPLOYE SET EMAIL_EMPLOYE = ? WHERE ID = ?");
                              query4.addBindValue(email);

                              query4.addBindValue(id);
                              query4.exec();
                              //change adress
                              query5.prepare("UPDATE EMPLOYE SET SALAIRE_EMPLOYE = ? WHERE ID = ?");
                              query5.addBindValue(salaire);

                              query5.addBindValue(id);
                              query5.exec();

                              query6.prepare("UPDATE EMPLOYE SET REF_AGENCE = ? WHERE ID = ?");
                              query6.addBindValue(agence);

                              query6.addBindValue(id);
                              query6.exec();

                             }
                             else
                     {
                         QMessageBox::critical(nullptr,"Information","Employé n'existe pas  !");
                     }

                               ui->tab_emp->setModel(e.afficher());

}

bool MainWindow::controlSaisie(){
    QRegExp mailREX("\b[A-Z0-9._%+-]+@[A-Z0-9.-]+.[A-Z]{2,4}\b");
        mailREX.setCaseSensitivity(Qt::CaseInsensitive);
        mailREX.setPatternSyntax(QRegExp::RegExp);

        if (
                !(ui->nom->text().contains(QRegExp("^[A-Za-z]+$"))) ||

                !(ui->prenom->text().contains(QRegExp("^[A-Za-z]+$"))) ||

                !(ui->adresse->currentText().contains(QRegExp("^[A-Za-z]+$"))) ||

                !(ui->ref_agence->text().contains(QRegExp("^[A-Za-z]+$"))) ||

        !(ui->salaire->text().contains(QRegExp("^[ 0 - 454646]+$"))) ||

                !(mailREX.exactMatch(ui->email->text())) )
            return 0;
        else
            return 1;
}

void MainWindow::on_rechercher_textChanged()
{
    QString rech=ui->rechercher->text();
        ui->tab_emp->setModel(e.rechercher(rech));
}

void MainWindow::on_pushButton_30_clicked()//tri
{
    ui->tab_emp->setModel(e.tri());

}

void MainWindow::on_pushButton_31_clicked()
{
    statistique s;
    s.exec();
}

void MainWindow::on_pushButton_33_clicked()
{
    ui->tab_emp->setModel(e.triS());
}


void MainWindow::on_pushButton_35_clicked()
{
    ui->tab_emp->setModel(e.triN());
}

void MainWindow::on_pushButton_29_clicked()
{
        QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tab_emp->model()->rowCount();
                    const int columnCount = ui->tab_emp->model()->columnCount();
                    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                    out <<"<html>\n"
                          "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        << "<title> LISTE DES PRODUITS<title>\n "
                        << "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"
                        "<h1 style=\"text-align: center;\"><strong> **LISTE DES EMPLOYES ** "+TT+"</strong></h1>"
                        "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                          "</br> </br>";
                    // headers
                    out << "<thead><tr bgcolor=#d6e5ff>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tab_emp->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_emp->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tab_emp->isColumnHidden(column)) {
                                QString data =ui->tab_emp->model()->data(ui->tab_emp->model()->index(row, column)).toString().simplified();
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

                    QPrinter printer;

                    QPrintDialog *test = new QPrintDialog(&printer, NULL);
                    if (test->exec() == QDialog::Accepted) {
                        document->print(&printer);
                    }

                    delete document;

     }


void MainWindow::on_login_clicked()
{
    QString email = ui->email_login->text();
       QString mdp = ui->mdp_login->text();
       int test;
       test=e.login(email,mdp);
           if (test==0)
           {
               QMessageBox::critical(nullptr, QObject::tr("Echèc"),
                           QObject::tr("Mot de passe ou email non valide.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           }
           else
           {
    ui->stackedWidget->setCurrentIndex(0);

           }

}


void MainWindow::on_pushButton_34_clicked()
{
    statistiques s;
    s.exec();
}
