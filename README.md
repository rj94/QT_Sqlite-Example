# QT_Sqlite-Example
This is simple QT program with Sqlite3.We make use of connection to database,closing of database.Adding new info into the database,Deleteing,updating and loading into tableview following opeation are performed.

Key points:
1.Installation of Sqlite3 into ubuntu
command to install-> sudo apt-get install sqlite3 libsqlite3-dev

2.Create a database
command -> sqlite3 Test.db

3.Create Table
command ->CREATE TABLE people ( 
	post_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, 
	name TEXT NOT NULL, 
	age TEXT NOT NULL, 
	loginid INTEGER NOT NULL,
	password INTEGER NOT NULL );
  
  # loginid and paasword are used in the program to login 
  
4.Adding info into the Table

#refer below link for info on sqlite
https://www.sitepoint.com/getting-started-sqlite3-basic-commands/
#https://www.sqlite.org/index.html

#Open Database connection
    bool openDatabaseconnection()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("/home/rahul/Test.db");
    }
    
 #close Database Connection
    void closeDatabaseconnection()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
   
 #insertion query
     QSqlQuery qry;
    qry.prepare("INSERT INTO PEOPLE (username,age,loginid,password) values    ('"+name+"','"+age+"','"+loginid+"','"+password+"')");
    qry.exec()
    
  #update Query
        QSqlQuery qry;
    qry.prepare("UPDATE PEOPLE set username ='"+name+"',age= '"+age+"',loginid ='"+loginid+"',password ='"+password+"'where username='"+name+"'");
    qry.exec()
    
  #Delete Query
        QSqlQuery qry;
    qry.prepare("UPDATE PEOPLE set username ='"+name+"',age= '"+age+"',loginid ='"+loginid+"',password ='"+password+"'where username='"+name+"'");
    if(qry.exec())
    
#loading into tableview

    QSqlQueryModel *modal = new QSqlQueryModel();
    conn.openDatabaseconnection();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * FROM People where 1");
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

  
 
