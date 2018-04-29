#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/rahul/Desktop/rahul.JPG");
//    pix =pix.scaled(this->size(),Qt::IgnoreAspectRatio);

    int w = ui->label_pic->width();                     //Getting width and height of the original picture
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


    if(!openDatabaseconnection())
    {
        ui->label->setText("Database is not opened");
    }
    else
    {
         ui->label->setText("Database is opened");
    }

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    openDatabaseconnection();                  //Opening of Database onnection
    if(!mydb.isOpen())
    {
        qDebug()<<"Failed To Open Database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("select * from people where loginid = '"+username+"'and password = '"+password+"'");
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count == 1)
        {
            ui->label_state->setText("Username and password is correct");
            closeDatabaseconnection();               //In QT at a time only 1 database connection remain active
            this->hide();
            Userinfo userinfo;
            userinfo.setModal(true);
            userinfo.exec();
        }
        if(count > 1)
        {
            ui->label_state->setText("Username and password is duplicate");
        }
        if(count < 1)
        {
            ui->label_state->setText("Username and password is not present");
        }
    }
}



void MainWindow::on_pushButton_register_clicked()
{
    this->hide();
    Userinfo userinfo;
    userinfo.setModal(true);
    userinfo.exec();
}
