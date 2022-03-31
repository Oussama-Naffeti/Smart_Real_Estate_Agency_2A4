#include "statistiques.h"
#include "ui_statistiques.h"
#include "ui_mainwindow.h"
#include<iostream>
#include "mainwindow.h"


statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);
}

statistiques::~statistiques()
{
    delete ui;
}
int statistiques::statistiques_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from EMPLOYE where SALAIRE_EMPLOYE >5000") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}

int statistiques::statistiques_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from EMPLOYE where SALAIRE_EMPLOYE <5000") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}


void statistiques::paintEvent(QPaintEvent *)
{

    int b=statistiques_partie2();
    cout<<b<<endl ;
    int c=statistiques_partie3();
    cout<<c<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
    QPainter painter(this);
    QRectF size=QRectF(150,40,this->width()-600,this->width()-600);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("+5000") ;
    painter.setBrush(Qt::red);
    ui->label_3->setNum(q2) ;
    painter.drawPie(size,16*y,16*m);
    ui->label_4->setText("-5000") ;
    ui->label_6->setNum(q3) ;


}

