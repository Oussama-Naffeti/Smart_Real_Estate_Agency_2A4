#include "agence.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QtPrintSupport/QPageSetupDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtPrintSupport/QPrintPreviewWidget>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrinterInfo>
#include <QtGui>
#include <QtCore>


Agence::Agence()
{
  id=0;
  adresse="Local";
  budget=0;
  nbr_bien=0;
  nbr_client=0;
  nbr_employe=0;
}
Agence::Agence(int id,QString adresse,float budget,int nbr_employe,int nbr_client,int nbr_bien)
{
    this->id=id;
    this->adresse=adresse;
    this->budget=budget;
    this->nbr_employe=nbr_employe;
    this->nbr_client=nbr_client;
    this->nbr_bien=nbr_bien;
}
// GETTERS
int Agence::get_id()
{
    return id;
}

QString Agence::get_adresse()
{
    return adresse;
}

float Agence::get_budget()
{
    return budget;
}

int Agence::get_nbr_employe()
{
    return nbr_employe;
}

int Agence::get_nbr_client()
{
    return nbr_client;
}

int Agence::get_nbr_bien()
{
    return nbr_bien;
}



// SETTERS
void Agence::set_id(int id)
{
    this->id=id;
}
void Agence::set_nbr_employe(int nbr_employe)
{
    this->nbr_employe=nbr_employe;
}
void Agence::set_nbr_client(int nbr_client)
{
    this->nbr_client=nbr_client;
}
void Agence::set_nbr_bien(int nbr_bien)
{
    this->nbr_bien=nbr_bien;
}
void Agence::set_adresse(QString adresse)
{
    this->adresse=adresse;
}
void Agence::set_budget(float budget)
{
    this->budget=budget;
}

//Fonctions

bool Agence::ajouter()
{
    QSqlQuery query;

    QString id_string=QString::number(id);
    QString budget_string=QString::number(budget);
    QString nbr_employe_string=QString::number(nbr_employe);
    QString nbr_client_string=QString::number(nbr_client);
    QString nbr_bien_string=QString::number(nbr_bien);

    query.prepare("INSERT INTO AGENCE (ID, BUDGET, ADRESSE, NBR_EMPLOYE, NBR_CLIENT, NBR_BIEN)"
                    "Values (:id, :budget, :adresse, :nbr_employe, :nbr_client, :nbr_bien)");

    query.bindValue(":id",id_string);
    query.bindValue(":adresse",adresse);
    query.bindValue(":budget",budget_string);
    query.bindValue(":nbr_employe",nbr_employe_string);
    query.bindValue(":nbr_client",nbr_client_string);
    query.bindValue(":nbr_bien",nbr_bien_string);


    return query.exec();
}

QSqlQueryModel * Agence::afficher()
{
  QSqlQueryModel * model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM AGENCE");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("Budget"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("Adresse"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("Nbr Employés"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("Nbr Clients"));
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nbr Biens"));

  return model;
}

bool Agence::supprimer(int id)
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare(" DELETE FROM AGENCE WHERE ID= :id");
    query.bindValue(":id",id_string);
    return query.exec();
}

bool Agence::modifier()
{   QSqlQuery query;
    QString id_string=QString::number(id);
    QString budget_string=QString::number(budget);
    QString nbr_employe_string=QString::number(nbr_employe);

    query.prepare( "UPDATE AGENCE SET BUDGET=:budget,ADRESSE=:adresse,NBR_EMPLOYE=:nbr_employe WHERE ID=:id");
    query.bindValue(":id",id_string);
    query.bindValue(":budget",budget_string);
    query.bindValue(":adresse",adresse);
    query.bindValue(":nbr_employe",nbr_employe_string);
    return query.exec();
}

QSqlQueryModel * Agence::recherche(QString recherche)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM AGENCE WHERE ID LIKE '"+recherche+"%' OR ADRESSE LIKE '"+recherche+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NBR_EMPLOYE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBR_CLIENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR_BIEN"));
    return model;
}




QSqlQueryModel * Agence::tri_id()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from AGENCE ORDER BY ID ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NBR_EMPLOYE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBR_CLIENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR_BIEN"));
    return model;
}

QSqlQueryModel * Agence::tri_budget()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from AGENCE ORDER BY BUDGET ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NBR_EMPLOYE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBR_CLIENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR_BIEN"));
    return model;
}

QSqlQueryModel * Agence::tri_nbr_client()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from AGENCE ORDER BY NBR_ClIENT ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NBR_EMPLOYE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBR_CLIENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR_BIEN"));
    return model;
}

QSqlQueryModel * Agence::tri_nbr_employe()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from AGENCE ORDER BY NBR_EMPLOYE ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NBR_EMPLOYE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBR_CLIENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR_BIEN"));
    return model;
}


bool Agence::agence_exist(int id){
    QSqlQueryModel * model= new QSqlQueryModel();
    QString id_string= QString::number(id);
    model->setQuery("select * from agence WHERE id="+id_string);
    return  model->rowCount();
}
