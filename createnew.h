#ifndef CREATENEW_H
#define CREATENEW_H

#include <QWidget>
#include "passman.h"

namespace Ui {
class CreateNew;
}

class CreateNew : public QWidget
{
    Q_OBJECT

public:
    explicit CreateNew(QWidget *parent = 0);
    passman password_manager ;
    ~CreateNew();

private slots:
    void on_file_button_clicked();

    void on_create_button_clicked();

    QString create_path(QString str);


private:
    Ui::CreateNew *ui;
};

#endif // CREATENEW_H
