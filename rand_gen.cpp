#include "rand_gen.h"
#include "ui_rand_gen.h"
#include<iostream>
#include<QString>
#include<QClipboard>
#include "new_entry.h"
#include<QRandomGenerator>

static int rand_len;
static QString f_pass ;
QString passWord;



QString GetRandomString(int length)
{
   const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+{}:';<.,>/?");
   const int randomStringLength = length;

   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = rand() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}

rand_gen::rand_gen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rand_gen)
{
    ui->setupUi(this);
    this->setWindowTitle("Generate Password");


}

rand_gen::~rand_gen()
{
     delete ui;
}



void rand_gen::on_pushButton_clicked()
{
    QString clip_text = ui->generated_pass->text();
    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(clip_text);

}



void rand_gen::on_cancle_button_clicked()
{

    close();



}

void rand_gen::on_horizontalSlider_sliderMoved(int position)
{
    rand_len = position;
    f_pass = GetRandomString(rand_len);
    QString s = QString::number(position);
    ui->pass_len->setText(s);
    ui->generated_pass->setText(f_pass);


}


void rand_gen::on_ok_button_clicked()
{
    passWord = f_pass ;
    close();


}
