#include "userinfo.h"
#include "ui_userinfo.h"
#include <QMessageBox>
Userinfo::Userinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userinfo)
{
    ui->setupUi(this);
    MainWindow conn;
    if(!conn.openDatabaseconnection())
    {
        ui->label_sec_state->setText("Database is not opened");
    }
    else
    {
         ui->label_sec_state->setText("Database is opened");
    }
}

Userinfo::~Userinfo()
{
    delete ui;
}

void Userinfo::on_pushButton_clicked()
{
    MainWindow conn;
    QString name,age,loginid,password;
    name = ui->lineEdit_name->text();
    age  = ui->lineEdit_age->text();
    loginid = ui->lineEdit_id->text();
    password = ui->lineEdit_pass->text();

    conn.openDatabaseconnection();                  //Opening of Database onnection

    if(!conn.openDatabaseconnection())
    {
        qDebug()<<"Failed To Open Database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("INSERT INTO PEOPLE (username,age,loginid,password) values ('"+name+"','"+age+"','"+loginid+"','"+password+"')");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("SAVE"),tr("SAVED"));
        conn.closeDatabaseconnection();
    }
    else
    {
         QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

void Userinfo::on_pushButton_edit_clicked()
{
    MainWindow conn;
    QString name,age,loginid,password;
    name = ui->lineEdit_name->text();
    age  = ui->lineEdit_age->text();
    loginid = ui->lineEdit_id->text();
    password = ui->lineEdit_pass->text();

    conn.openDatabaseconnection();                  //Opening of Database onnection

    if(!conn.openDatabaseconnection())
    {
        qDebug()<<"Failed To Open Database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("UPDATE PEOPLE set username ='"+name+"',age= '"+age+"',loginid ='"+loginid+"',password ='"+password+"'where username='"+name+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("EDIT"),tr("Updated"));
        conn.closeDatabaseconnection();
    }
    else
    {
         QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

void Userinfo::on_pushButton_delete_clicked()
{
    MainWindow conn;
    QString name,age,loginid,password;
    name = ui->lineEdit_name->text();
    age  = ui->lineEdit_age->text();
    loginid = ui->lineEdit_id->text();
    password = ui->lineEdit_pass->text();

    conn.openDatabaseconnection();                  //Opening of Database onnection

    if(!conn.openDatabaseconnection())
    {
        qDebug()<<"Failed To Open Database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("DELETE FROM PEOPLE where username='"+name+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("DELETE"),tr("DELETED"));
        conn.closeDatabaseconnection();
    }
    else
    {
         QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

void Userinfo::on_pushButton_load_clicked()
{
    MainWindow conn;
    QSqlQueryModel *modal = new QSqlQueryModel();
    conn.openDatabaseconnection();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * FROM People where 1");
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.closeDatabaseconnection();
    qDebug()<<(modal->rowCount());
}
