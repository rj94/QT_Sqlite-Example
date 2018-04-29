#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql>
#include <QMainWindow>
#include <QDebug>
#include <QFileInfo>
#include "userinfo.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    void closeDatabaseconnection()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool openDatabaseconnection()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("/home/rahul/Test.db");

        if(!mydb.open())
        {
            qDebug()<<"Database is not opened";
            return false;
        }
        else
        {
             qDebug()<<"Database is opened";
             return true;
        }
    }


public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_register_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
