#include "voirstock.h"
#include "ui_voirstock.h"
#include "excel.h"
#include <QFileDialog>

VoirStock::VoirStock(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VoirStock)
{
    ui->setupUi(this);
    ui->tableView->setModel(a.afficher());
}

VoirStock::~VoirStock()
{
    delete ui;
}

void VoirStock::on_pushButton_clicked()
{
    menuGestionStock *gestionStock;
    gestionStock = new menuGestionStock();
    gestionStock->show();
    this->close();
}


void VoirStock::on_pushButton_8_clicked()
{
    ajouterProduit *ajout;
    ajout = new ajouterProduit();
    ajout->show();
    this->close();
}


void VoirStock::on_pushButton_2_clicked()
{
    DeleteProduit *D;
    D = new DeleteProduit();
    D->show();
    this->close();
}


void VoirStock::on_pushButton_9_clicked()
{
    modifierProduit *P;
    P = new modifierProduit();
    P->show();
    this->close();
}


void VoirStock::on_pushButton_5_clicked()
{
    statistique *stat;
    stat = new statistique();
    stat->show();
    this->close();
}


void VoirStock::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                            tr("Excel Files (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "produit", ui->tableView);

            //colums to export
            obj.addField(0, "ID_PRODUIT", "char(20)");
            obj.addField(1, "MARQUE", "char(20)");
            obj.addField(2, "LIBELE", "char(20)");
            obj.addField(3, "CODE_BARRE", "char(50)");
            obj.addField(4, "QUANTITE", "char(20)");
            obj.addField(5, "ID_ADHERENT", "char(20)");
            obj.addField(6, "TYPE_PRODUIT", "char(20)");




            int retVal = obj.export2Excel();
            if( retVal > 0)
            {
                QString text = "Archivé avec success!";
                QString titre = "Archivage complete!";

            }
}


void VoirStock::on_pushButton_7_clicked()
{
    QString re = ui->lineEdit->text();
        ui->tableView->setModel(a.recherche(re));
}


void VoirStock::on_pushButton_6_clicked()
{
    TriDispo *triDispo;
    triDispo = new TriDispo();
    triDispo->show();
}


void VoirStock::on_pushButton_4_clicked()
{
    TriNonDispo *triNonDispo;
    triNonDispo = new TriNonDispo();
    triNonDispo->show();
}


void VoirStock::on_pushButton_10_clicked()
{

}


void VoirStock::on_pushButton_11_clicked()
{
    arduinoWindow *ard;
    ard = new arduinoWindow();
    ard->show();
}

