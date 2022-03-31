#ifndef STATISTIQUES_H
#define STATISTIQUES_H


#include <QDialog>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>

using namespace std;

namespace Ui {
class statistiques;
}

class statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
    int statistiques_partie2() ;
        int statistiques_partie3() ;
         int statistiques_partie4() ;
         int statistiques_partie5() ;
         int statistiques_partie6() ;
        void paintEvent(QPaintEvent *) ;

    ~statistiques();

private:
    Ui::statistiques *ui;
private slots :
};

#endif // STATISTIQUES_H
