#include "login.h"
#include "ui_login.h"
#include"familles.h"
#include<QMessageBox>
#include"mainwindow.h"
#include"connection.h"


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}



void Login::on_Create_clicked()
{
    Familles  F;
     F.USERNAME=ui->username->text();
     F.PASSWORD=ui->password->text();

     F.login();


     //mainwindow = new MainWindow(this);
       // mainwindow->show();
     ui->username->clear();
     ui->password->clear();
     if(F.USERNAME == "mohamed" && F.PASSWORD =="mohamed" )
     {
         QMessageBox::critical(nullptr, QObject::tr("Deux comtes similaires "),
                               QObject::tr("Ce compte Existe deja.\n"
                                           "créer une nouvelle compte."), QMessageBox::Cancel);

     }
     else
          QMessageBox::information(this,"ACCOUNT","creation successful");
}


void Login::on_singin_clicked()
{
Familles F;
F.USERNAME=ui->username->text();
    F.PASSWORD=ui->password->text();
 if(F.USERNAME == "mohamed" && F.PASSWORD =="mohamed" )

{
QMessageBox::information(this,"username","username et password correct");
mainwindow = new MainWindow(this);

   mainwindow->show();

}
else

{
     QMessageBox::warning(this,"username","username ou password incorrect");
}

}

void Login::on_pushButton_clicked()
{
    Familles F;
     F.USERNAME=ui->username->text();
     F.PASSWORD=ui->password->text();
  if(F.USERNAME == "mohamed" && F.PASSWORD =="mohamed" )

 {
 QMessageBox::information(this,"username","username et password correct");
 mainwindow = new MainWindow(this);
 close();
    mainwindow->show();

 }
 else

 {
      QMessageBox::warning(this,"username","username ou password incorrect");
 }
}
