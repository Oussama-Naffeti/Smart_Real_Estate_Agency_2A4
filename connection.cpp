#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Source_Projet2A");
db.setUserName("oussama");//inserer nom de l'utilisateur
db.setPassword("oussama");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
return  test;
}

void Connection::closeConnection(){db.close();}
