#include "employe.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include "mainwindow.h"
#include <QSqlQueryModel>
#include <QString>

Employe::Employe()
{
       id  =0;
        nom="";
        prenom="";
        adresse="";
        email="";
        ref_agence="";
        salaire=0.00;
        mdp="";

}

Employe::Employe(int id,QString nom,QString prenom,QString adresse,QString email,QString ref_agence,double salaire,QString mdp)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->email=email;
    this->ref_agence=ref_agence;
    this->salaire=salaire;
    this->mdp=mdp;
}

int Employe::get_id()
{
    return id;
}

QString Employe::get_nom()
{
    return nom;
}


QString Employe::get_prenom()
{
    return prenom;
}

QString Employe::get_adresse()
{
    return adresse;
}

QString Employe::get_email()
{
    return email;
}

QString Employe::get_agence()
{
    return ref_agence;
}

double Employe::get_salaire()
{
    return  salaire;
}

QString Employe::get_mdp()
{
    return mdp;
}
void Employe::set_id(int id)
{
    this->id=id;
}


void Employe::set_nom(QString nom)
{
    this->nom=nom;
}
void Employe::set_prenom(QString prenom)
{
    this->prenom=prenom;
}

void Employe::set_adresse(QString adresse)
{
    this->adresse=adresse;
}

void Employe::set_email(QString email)
{
    this->email=email;
}

void Employe::set_agence(QString ref_agence)
{
    this->ref_agence=ref_agence;
}
void Employe::set_salaire(double salaire)
{
    this->salaire=salaire;
}
void Employe::set_mdp(QString mdp)
{
    this->mdp=mdp;
}

bool Employe::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(id);

    query.prepare("INSERT INTO EMPLOYE (ID,NOM, PRENOM, ADRESSE_EMPLOYE, EMAIL_EMPLOYE, REF_AGENCE, SALAIRE_EMPLOYE,MDP) "
                  "VALUES (:ID,:NOM, :PRENOM, :ADRESSE_EMPLOYE, :EMAIL_EMPLOYE, :REF_AGENCE, :SALAIRE_EMPLOYE, :MDP)");

    query.bindValue(":ID", id_string);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":ADRESSE_EMPLOYE", adresse);
    query.bindValue(":EMAIL_EMPLOYE", email);
    query.bindValue(":REF_AGENCE", ref_agence);
    query.bindValue(":SALAIRE_EMPLOYE", salaire);
    query.bindValue(":MDP", mdp);


    return  query.exec();

}


bool Employe::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE from EMPLOYE where ID=:ID") ;

                            query.bindValue(":ID", id);
                       return     query.exec();
}

QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


        model->setQuery("SELECT * FROM EMPLOYE");


    return model;

}

QSqlQueryModel * Employe::rechercher(QString rechercher)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM EMPLOYE WHERE ID LIKE '"+rechercher+"%' OR nom LIKE '"+rechercher+"%' OR prenom LIKE '"+rechercher+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGENCE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("MDP"));
    return model;
}

QSqlQueryModel * Employe::tri()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from EMPLOYE ORDER BY CAST(id AS number)");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGENCE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("MDP"));
    return model;
}
QSqlQueryModel * Employe::triN()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from EMPLOYE ORDER BY nom ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGENCE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("MDP"));
    return model;
}
QSqlQueryModel * Employe::triS()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from EMPLOYE ORDER BY CAST(SALAIRE_EMPLOYE AS number)");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGENCE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("MDP"));
    return model;
}
bool Employe::employeExist(int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(id);
    model->setQuery("select * from EMPLOYE WHERE id="+res);
    return  model->rowCount();
}
int Employe::login(QString email, QString mdp)
{
     int row_count = 0;
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE where EMAIL_EMPLOYE= ? and MDP= ? ");
    query.addBindValue(email);
    query.addBindValue(mdp);
 query.exec();
 while(query.next())
 {
     row_count++;
 }
qDebug() << "Number of Rows: " << row_count;
return row_count;
}
