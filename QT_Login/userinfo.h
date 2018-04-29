#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class Userinfo;
}

class Userinfo : public QDialog
{
    Q_OBJECT

public:
    explicit Userinfo(QWidget *parent = 0);
    ~Userinfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_load_clicked();

private:
    Ui::Userinfo *ui;
};

#endif // USERINFO_H
