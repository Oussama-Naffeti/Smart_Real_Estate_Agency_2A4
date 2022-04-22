#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "agence.h"
#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_tri_id_clicked();

    void on_pushButton_tri_budget_clicked();

    void on_textEdit_textChanged();

    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_pushButton_tri_nbr_client_clicked();

    void on_pushButton_tri_nbr_employe_clicked();

    void on_pushButton_statistique_clicked();

    void on_pushButton_metier3_clicked();

    void on_pushButton_imprimer_clicked();

private:
    Ui::MainWindow *ui;
    Agence Etmp;
};

#endif // MAINWINDOW_H
