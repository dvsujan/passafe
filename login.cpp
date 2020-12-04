#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include<QFileDialog>
#include<QString>
#include<QDialog>
#include "createnew.h"


QString MainPassword;
QString MainDbPath;


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    this->setWindowTitle("Login");


}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{
    QString name = ui->db_name->text();
    QString password = ui->pass->text();


    password_manager.database_path = name ;

    password_manager.key = password;



    if(!password_manager.load()){

        ui->auth_info->setText("Database could not be Decrypted");

        return;



    }
    if (!password_manager.decrypt())
    {

        ui->auth_info->setText("Password is incorrect");
        return ;


    }

    else{
        hide();
        MainWindow *window ;
        MainPassword = password ;
        MainDbPath = name ;
        window = new MainWindow();
        window ->show();

    }


}

void Login::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Select DataBase"),"c:",tr("DB files (*.db)"));
     ui->db_name->setText(fileName);


}

void Login::on_pushButton_3_clicked()
{
    CreateNew * createnew ;
    hide();
    createnew = new CreateNew();
    createnew->show();
}








