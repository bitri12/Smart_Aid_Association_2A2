#include "deleteproduit.h"
#include "ui_deleteproduit.h"
#include <QSqlError>

DeleteProduit::DeleteProduit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteProduit)
{
    ui->setupUi(this);
}

DeleteProduit::~DeleteProduit()
{
    delete ui;
}

void DeleteProduit::on_pushButton_3_clicked()
{
    VoirStock *voirStock;
    voirStock = new VoirStock();
    voirStock->show();
    this->close();
}


void DeleteProduit::on_pushButton_clicked()
{
    menuGestionStock *gestionStock;
    gestionStock = new menuGestionStock();
    gestionStock->show();
    this->close();
}


void DeleteProduit::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_2->text().toInt();
    bool test = d.supprimer(id);
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Done"),QMessageBox::Cancel);
    } else {
        QMessageBox::information(nullptr,QObject::tr("Not OK"),QObject::tr("not done"),QMessageBox::Cancel);
    }
}


void DeleteProduit::on_pushButton_4_clicked()
{
    int id = ui->lineEdit_3->text().toInt();
    int qty = ui->lineEdit->text().toInt();
    bool test = d.retirer(id,qty);
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Done"),QMessageBox::Cancel);
    } else {
        QMessageBox::information(nullptr,QObject::tr("Not OK"),QObject::tr("not done"),QMessageBox::Cancel);
    }
}

