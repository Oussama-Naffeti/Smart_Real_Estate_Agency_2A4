#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet-2A");
db.setUserName("hend");//inserer nom de l'utilisateur
db.setPassword("esprit2A");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
