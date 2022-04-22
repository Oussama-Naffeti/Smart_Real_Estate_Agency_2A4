#ifndef AGENCE_H
#define AGENCE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Agence
{
public:
    //Constructeurs
    Agence();
    Agence(int,QString,float,int,int,int);
    Agence (int,QString,float,int);

    //Getters
    int get_id();
    int get_nbr_employe();
    int get_nbr_client();
    int get_nbr_bien();
    QString get_adresse();
    float get_budget();

    //Setters
    void set_id(int);
    void set_nbr_employe(int);
    void set_nbr_client(int);
    void set_nbr_bien(int);
    void set_adresse(QString);
    void set_budget(float);

    //fonctions
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * recherche(QString);
    QSqlQueryModel * tri_id();
    QSqlQueryModel * tri_budget();
    QSqlQueryModel * tri_nbr_client();
    QSqlQueryModel * tri_nbr_employe();
    bool agence_exist(int);



private :
    int id, nbr_employe, nbr_client,nbr_bien;
    QString adresse;
    float budget;
};

#endif // AGENCE_H
