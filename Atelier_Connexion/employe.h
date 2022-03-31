#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>

class Employe
{
public:
    Employe();

        Employe(int,QString,QString,QString,QString,QString,double,QString);

        //GETTERS
            int get_id();
            QString get_nom();
            QString get_prenom();
            QString get_adresse();
            QString get_email();
            QString get_agence();
            double get_salaire();
            QString get_mdp();

            //SETTERS
                void set_id(int);
                void set_nom(QString);
                void set_prenom(QString);
                void set_adresse(QString);
                void set_email(QString);
                void set_agence(QString);
                void set_salaire(double);
                void set_mdp(QString);
                bool ajouter();
                bool modifier();
                bool employeExist(int id);
                bool supprimer(int);
                QSqlQueryModel* afficher();
                QSqlQueryModel* rechercher(QString);
                QSqlQueryModel* tri();
                QSqlQueryModel* triN();
                QSqlQueryModel* triS();
                 int login(QString,QString);

private:
    int id;
    QString nom,prenom,adresse,email,ref_agence,mdp;
    double salaire;


};

#endif // EMPLOYE_H
