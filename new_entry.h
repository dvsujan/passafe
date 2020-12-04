#ifndef NEW_ENTRY_H
#define NEW_ENTRY_H

#include <QWidget>
#include "passman.h"
namespace Ui {
class new_entry;
}

class new_entry : public QWidget
{
    Q_OBJECT

public:
    explicit new_entry(QWidget *parent = 0);
    void set_passs(QString str);
    passman password_manager ;


    ~new_entry();

private slots:
    void on_pushButton_clicked();

    void on_add_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::new_entry *ui;
};

#endif // NEW_ENTRY_H
