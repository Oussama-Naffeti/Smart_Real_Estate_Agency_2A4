#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include <QDialog> /* */

/*QT_BEGIN_NAMESPACE */
namespace Ui { class MainWindow; }
/*QT_END_NAMESPACE */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void refresh();
    void clear();
    bool controlSaisie();
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_modifier_clicked();

    void on_rechercher_textChanged();

    void on_rechercher_textChanged(const QString &arg1);

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_29_clicked();

    void on_login_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_34_clicked();

private:
    Ui::MainWindow *ui;
    Employe e;
};

#endif // MAINWINDOW_H
