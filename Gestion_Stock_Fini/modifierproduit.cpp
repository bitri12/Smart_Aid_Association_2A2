#include "modifierproduit.h"
#include "ui_modifierproduit.h"

modifierProduit::modifierProduit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::modifierProduit)
{
    ui->setupUi(this);
}

modifierProduit::~modifierProduit()
{
    delete ui;
}

void modifierProduit::on_pushButton_clicked()
{
    menuGestionStock *gestionStock;
    gestionStock = new menuGestionStock();
    gestionStock->show();
    this->close();
}


void modifierProduit::on_pushButton_3_clicked()
{
    VoirStock *voirStock;
    voirStock = new VoirStock();
    voirStock->show();
    this->close();
}


void modifierProduit::on_pushButton_8_clicked()
{
    produit p;
    p.setCodeBarre(ui->lineEdit_6->text().toInt());
    p.setIdAdherent(ui->lineEdit_8->text().toInt());
    p.setIdProduit(ui->lineEdit->text().toInt());
    p.setLibele(ui->lineEdit_4->text());
    p.setMarque(ui->lineEdit_2->text());
    p.setQuantite(ui->lineEdit_3->text().toInt());
    p.setTypeProduit(ui->lineEdit_5->text());
    p.modifier(p);
    bool test=p.modifier(p);
        if (test)
        {
               QMessageBox::information(nullptr, QObject::tr("ok"),
                                        QObject::tr("modification effectuée\n"),
                                        QMessageBox::Cancel);}
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                     QObject::tr("modification non effectuée\n"),
                                     QMessageBox::Cancel);
        }
}

