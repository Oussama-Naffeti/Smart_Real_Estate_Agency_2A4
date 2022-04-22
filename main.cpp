#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QTranslator>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QMessageBox msgBox;
    msgBox.setText("Voulez-vous traduire en anglais ?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if (ret==1)
    {
        QTranslator t;
        t.load(":/lang_eng.qm");
        a.installTranslator(&t);
    }



    Connection c;
    bool test=c.createconnection();
    MainWindow w;
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
