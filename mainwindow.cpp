#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "new_entry.h"
#include <QWidgetItem>
#include<iostream>
#include<QClipboard>
#include<iostream>
#include<string>
#include "rand_gen.h"
#include<QCloseEvent>
#include<QMessageBox>
#include "createnew.h"



extern QString MainPassword;
extern QString MainDbPath;


using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("passafe");
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    password_manager.database_path = MainDbPath;
    password_manager.key = MainPassword;

    if(!password_manager.load()||!password_manager.decrypt()){
        ui->status_label->setStyleSheet("background-color:red; border-radius:20px");
    }
    else{
        ui->status_label->setStyleSheet("background-color:green; border-radius:10px");
    }
    if(saved==true){
        ui->save_info->setStyleSheet("background-color:green; border-radius:10px");
    }
    else{
        ui->save_info->setStyleSheet("background-color:red; border-radius:10px");
    }


    Decrypt();



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow:: Decrypt(){
    std::vector<std::array<QString, 4>> database = password_manager.get_database_copy();


    ui->table->setRowCount(static_cast<int>(database.size()));
    ui->table->setColumnCount(4);

    for (ulong i = 0; i < database.size(); i++)
    {
        for (ulong j = 0; j < database[i].size(); j++)
        {
            ui->table->setItem(static_cast<int>(i), static_cast<int>(j), new QTableWidgetItem(database[i][j]));
        }
    }
    ui->table->setEnabled(true);

    ui->table->setHorizontalHeaderLabels({"Website", "Username", "Password", "Email"});
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



}

void MainWindow::on_pushButton_2_clicked()
{

    hide();
    Login* login ;

    login = new Login();
    login->show();
    save_database();





}

void MainWindow::on_pushButton_clicked()
{


}


void MainWindow::remove_entry()
{
    QList<QTableWidgetItem*> selected = ui->table->selectedItems();

    saved = selected.size() <= 0;

    for (QTableWidgetItem* item : selected)
    {
        ui->table->removeRow(item->row());
    }
}

void MainWindow::save_database()
{
    password_manager.clear_database();

    std::array<QString, 4> tmp_row;
    for (int i = 0; i < ui->table->rowCount(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmp_row[static_cast<ulong>(j)] = ui->table->item(i, j)->text();
        }
        password_manager.add_entry(tmp_row[0], tmp_row[1], tmp_row[2], tmp_row[3]);
    }

    password_manager.encrypt();
    password_manager.save();
    saved = true ;


}
void MainWindow::closeEvent(QCloseEvent *event)
{

    QMessageBox exit_message_box;
    exit_message_box.setIcon(QMessageBox::Warning);
    exit_message_box.setText("You didn't save!");
    exit_message_box.setInformativeText("Do you want to save before exiting?");
    exit_message_box.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    exit_message_box.setDefaultButton(QMessageBox::Yes);

    switch (exit_message_box.exec()) {
        case QMessageBox::Save:
            save_database();
            event->accept();
            break;
        case QMessageBox::Discard:
            event->accept();
            break;
        case QMessageBox::Cancel:
            event->ignore();
            break;
        default:
            event->ignore();
            break;
    }
}

void MainWindow::add_entry()
{
    int row_count = ui->table->rowCount();

    ui->table->insertRow(row_count);
    ui->table->scrollToItem(ui->table->takeItem(row_count, 0));

    ui->table->setItem(row_count, 0, new QTableWidgetItem(""));
    ui->table->setItem(row_count, 1, new QTableWidgetItem(""));
    ui->table->setItem(row_count, 2, new QTableWidgetItem(""));
    ui->table->setItem(row_count, 3, new QTableWidgetItem(""));
    saved = false;

}



void MainWindow::on_pushButton_3_clicked()
{
    if (password_manager.backup())
    {
        ui->back_info->setStyleSheet("background-color:green; border-radius:10px");

    } else {

        ui->back_info->setStyleSheet("background-color:red; border-radius:10px");


    }

}

void MainWindow::on_rand_gen_clicked()
{
    rand_gen* generate ;
    generate = new rand_gen();
    generate->show();

}

void MainWindow::on_add_btn_clicked()
{
    add_entry();

}

void MainWindow::on_save_btn_clicked()
{
    save_database();

}

void MainWindow::on_remove_btn_clicked()
{
    remove_entry();

}




void MainWindow::on_actionNew_triggered()
{

    CreateNew *createDatabase ;
    createDatabase = new CreateNew();
    hide();
    save_database();

    createDatabase->show();


}
