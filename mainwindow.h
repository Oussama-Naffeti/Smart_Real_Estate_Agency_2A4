#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include <QMainWindow>
#include "exportexcelobject.h"
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
    void on_pushButton_clicked();

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_supprimer_2_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_rechercher_textChanged();

    void on_pushButton_merier1_4_clicked();

    void on_pushButton_ajouter_3_clicked();

    void on_pushButton_merier1_2_clicked();

    void on_tableau_clicked();

    bool controlSaisie();

    void on_export_excel_clicked();

    void sendMail();

    void mailSent(QString);

    void browse();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    client cl;
    QStringList files;
    //stat_combo *s;
};

#endif // MAINWINDOW_H