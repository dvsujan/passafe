#include "mainwindow.h"
#include <QApplication>
#include "login.h"
#include "new_entry.h"
#include "rand_gen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/images/Logo (2).png"));
    //MainWindow w;
    //w.show();
    Login login ;

    login.show();
    //new_entry w ;
    //w.show();




    return a.exec();
}
