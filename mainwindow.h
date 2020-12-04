#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "passman.h"
#include "login.h"
#include<QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    passman password_manager;
    void Decrypt();
    void save_database();
    bool saved = true;
    void remove_entry();
    void closeEvent(QCloseEvent *event) override;



private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


   void on_pushButton_3_clicked();

    void on_rand_gen_clicked();

    void add_entry();

    void on_add_btn_clicked();

    void on_save_btn_clicked();


    void on_remove_btn_clicked();


    void on_actionNew_triggered();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
