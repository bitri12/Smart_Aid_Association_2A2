#include "ajouterproduit.h"
#include "ui_ajouterproduit.h"
ajouterProduit::ajouterProduit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ajouterProduit)
{
    ui->setupUi(this);
}

ajouterProduit::~ajouterProduit()
{
    delete ui;
}

void ajouterProduit::on_pushButton_3_clicked()
{
    VoirStock *voirStock;
    voirStock = new VoirStock();
    voirStock->show();
    this->close();
}


void ajouterProduit::on_pushButton_clicked()
{
    menuGestionStock *gestionStock;
    gestionStock = new menuGestionStock();
    gestionStock->show();
    this->close();
}


void ajouterProduit::on_pushButton_8_clicked()
{
    int id_produit = ui->lineEdit->text().toInt();
    int quantite = ui->lineEdit_3->text().toInt();
    int code_barre = ui->lineEdit_6->text().toInt();
    QString type_produit = ui->lineEdit_5->text();
    QString marque = ui->lineEdit_2->text();
    QString libele = ui->lineEdit_4->text();
    int id_adherent= ui->lineEdit_7->text().toInt();
    produit P(id_produit,code_barre,quantite,id_adherent,type_produit, marque, libele);
    bool test = P.ajouter();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                         QObject::tr("Ajout effectué\n"),
                                         QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                         QObject::tr("Ajout non  effectué\n"),
                                         QMessageBox::Cancel);
    }
}

