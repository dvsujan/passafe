#include "new_entry.h"
#include "ui_new_entry.h"
#include "rand_gen.h"
#include "mainwindow.h"



extern QString passWord;
extern QString MainPassword;
extern QString MainDbPath;



new_entry::new_entry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new_entry)
{
    ui->setupUi(this);


}

new_entry::~new_entry()
{
    delete ui;
}

void new_entry::set_passs(QString str){

    ui->password->setText(str);

}
void new_entry::on_pushButton_clicked()
{
    rand_gen *RandGenWind ;
    RandGenWind = new rand_gen();
    RandGenWind->show();


}

void new_entry::on_add_button_clicked()
{
    QString user_name = ui->username->text();
    QString password = ui->password->text();
    QString website = ui->website->text();
    QString email = ui->email->text();

    password_manager.database_path = MainDbPath;
    password_manager.key = MainPassword;

    password_manager.add_entry(website, user_name , password , email );
    password_manager.encrypt();

    password_manager.save();

    hide();

    MainWindow* window ;
    window = new MainWindow();
    window->hide();
    window->show();



}

void new_entry::on_cancel_button_clicked()
{
    hide();

}
