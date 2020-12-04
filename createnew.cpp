#include "createnew.h"
#include "ui_createnew.h"
#include<QFileDialog>
#include<login.h>
#include "passman.h"
#define empty ""


CreateNew::CreateNew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateNew)
{
    ui->setupUi(this);
}

CreateNew::~CreateNew()
{
    delete ui;
    this->setWindowTitle("New Database");
}

void CreateNew::on_file_button_clicked()
{
    QString fileName = QFileDialog::getExistingDirectory(this, "Select Folder", "c :");

     ui->file_edit->setText(fileName);
}

QString CreateNew:: create_path(QString str){
    QString final_string = str+"/credentials.db";
    return final_string;
}

void CreateNew::on_create_button_clicked()
{
    QString pass = ui->password_edit->text();
    QString c_pass = ui->conf_pass_edit->text();
    QString folder_name = ui->file_edit->text();


    if(pass == c_pass && pass!= empty && c_pass != empty && folder_name != empty){

        ui->info_label->setText("Matched");
        QString path = create_path(folder_name);
        password_manager.database_path = path;
        password_manager.key = pass;
        password_manager.encrypt();
        password_manager.save();

        Login *login ;
        hide();
        login = new Login();
        login->show();


    }
    else if(folder_name == empty ) {

        ui->info_label->setText("Folder Path empty");



    }
    else{
        ui->info_label->setText("Passwords dosen't match");
    }

}
