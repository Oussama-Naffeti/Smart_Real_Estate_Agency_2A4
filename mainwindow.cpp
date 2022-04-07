#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QFileDialog>
#include <QtCharts/QBarSeries>
#include "statistique.h"
#include "smtp.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableau->setModel(cl.afficher());
    ui->server->setText("smtp.gmail.com");
    ui->port->setText("465");


    //ui->lineEditID->setvalidator(new QIntvalidator(0, 999999, this));
    //for email tab
    /*connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_2_clicked()//ajouter
{
   if (controlSaisie())
   {
    //recuperation des informations
    int id=ui->lineEditID->text().toInt();
    ui->lineEditID->clear();
    QString nom=ui->linenom->text();
    ui->linenom->clear();
    QString prenom=ui->lineEdit_prenom->text();
    ui->lineEdit_prenom->clear();
    QString adresse_client=ui->lineEdit_ad->currentText();
    QString email_client=ui->lineEdit_email->text();
    ui->lineEdit_email->clear();
    client c(id,nom,prenom,adresse_client,email_client);
    bool test=c.ajouter();
     ui->tableau->setModel(cl.afficher());
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
   }else
        QMessageBox::critical(nullptr, QObject::tr("not nok"),
                               QObject::tr("Ajout non effectué\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supprimer_2_clicked()
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
void MainWindow::on_pushButton_ajouter_3_clicked() //afficher
{
 ui->tableau->setModel(cl.afficher());
}
void MainWindow::on_pushButton_modifier_2_clicked()
{

    if (controlSaisie()){
    //modifier les valeur de class
    int id=ui->lineEditID->text().toInt();
    ui->lineEditID->clear();
    QString nom=ui->linenom->text();
    ui->linenom->clear();
    QString prenom=ui->lineEdit_prenom->text();
    ui->lineEdit_prenom->clear();
    QString adresse_client=ui->lineEdit_ad->currentText();
    ui->lineEdit_ad->clear();
    QString email_client=ui->lineEdit_email->text();
    ui->lineEdit_email->clear();
    client cl(id,nom,prenom,adresse_client,email_client);

bool test = cl.modifier(id);
if(test)
{
    ui->tableau->setModel(cl.afficher());
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("client modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
    }else
    QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("client non modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_clicked() //tri
{
    //ui->tableau->setModel(cl.afficher());
    ui->tableau->setModel(cl.triParId());

}

void MainWindow::on_rechercher_textChanged()
{
    QString rech=ui->rechercher->text();
    ui->tableau->setModel(cl.recherche(rech));
}


void MainWindow::on_pushButton_merier1_2_clicked()//stat
{
    statistique s;
    s.exec();
}
bool MainWindow::controlSaisie(){
    QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailREX.setCaseSensitivity(Qt::CaseInsensitive);
    mailREX.setPatternSyntax(QRegExp::RegExp);

    if (
            !(ui->linenom->text().contains(QRegExp("^[A-Za-z]+$"))) ||

            !(ui->lineEdit_prenom->text().contains(QRegExp("^[A-Za-z]+$"))) ||

            !(mailREX.exactMatch(ui->lineEdit_email->text())) )
        return 0;
    else
        return 1;
}

void MainWindow::on_export_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                       tr("Excel Files (*.xls)"));
       if (fileName.isEmpty())
           return;

       ExportExcelObject obj(fileName, "mydata", ui->tableau);

       //colums to export
       obj.addField(0, "id", "char(20)");
       obj.addField(1, "nom", "char(20)");
       obj.addField(2, "prenom", "char(20)");
       obj.addField(3, "adresse_client", "char(20)");
       obj.addField(4, "email_client", "char(20)");


       int retVal = obj.export2Excel();
       if( retVal > 0)
       {
           QMessageBox::information(this, tr("Done"),
                                    QString(tr("%1 records exported!")).arg(retVal)
                                    );
       }
}

void MainWindow::on_pushButton_3_clicked()
{
     ui->tableau->setModel(cl.triParNOM());
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableau->setModel(cl.triParPRENOM());

}

void MainWindow::on_pushButton_4_clicked()//PRENOM
{
     ui->tableau->setModel(cl.triParPRENOM());
}




void MainWindow::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());

    QMessageBox::information(nullptr, QObject::tr("Succès"),
                QObject::tr("Le mail a été envoyé avec succès.\n"
                            "Cliquer sur Cancel to exit."), QMessageBox::Cancel);

}
