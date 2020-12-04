#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"



namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    passman password_manager;


    ~Login();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();



private:
    Ui::Login *ui;





};

#endif // LOGIN_H
