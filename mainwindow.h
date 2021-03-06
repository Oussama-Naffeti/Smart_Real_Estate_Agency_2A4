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

private:
    Ui::MainWindow *ui;
    Agence Etmp;
};

#endif // MAINWINDOW_H
