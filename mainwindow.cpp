#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adherent.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QCloseEvent>
#include <QPushButton>
#include <QLineEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_tel->setValidator(new QIntValidator(0, 9999999, this));

  ui->tab_Adherent->setModel(A.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id_adherent=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString mail=ui->le_email->text();
    int tel=ui->le_tel->text().toInt();
     QString adresse=ui->le_adresse->text();

    Adherent A(id_adherent,nom,prenom,mail,tel,adresse);

    bool test=A.ajouter();
    if (test)
    {
       ui->tab_Adherent->setModel(A.afficher());


        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("ajout effectué\n"
                                             "click cancel to exit."), QMessageBox::Cancel);

    }
    else QMessageBox::critical(nullptr, QObject::tr("not ok"),
                               QObject::tr("Ajout non effectué.\n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);
}






void MainWindow::on_pb_supprimer_clicked()
{
    int id_adherent= ui->Le_id_supp->text().toInt();
    bool test=A.supprimer(id_adherent);
    if (test)
    {
        ui->tab_Adherent->setModel(A.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("suppression effectué\n"
                                             "click cancel to exit."), QMessageBox::Cancel);

    }
    else QMessageBox::critical(nullptr, QObject::tr("not ok"),
                               QObject::tr("suppression non effectué.\n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{



      int id_adherent = ui->modif_id->text().toInt();
      QString nom = ui->modif_nom->text();
      QString prenom =ui->modif_prenom->text();
      QString mail =ui->modif_email->text();
      int tel = ui->modif_tel->text().toInt();
      QString adresse =ui->modif_adresse->text();

     Adherent A(id_adherent,nom,prenom,mail,tel,adresse);

     bool test=A.modifier(A);
     if (test)
          {  ui->tab_Adherent->setModel(A.afficher());
          QMessageBox::information(nullptr, QObject::tr("modifier"),
                            QObject::tr(" client modifié .\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
         }




      QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectuée"),  QMessageBox::Cancel);
}



void MainWindow::on_pb_rech_clicked()
{

        QString findText;
              QString text = ui->rechercher->text();
          Adherent A ;
          QTableView* table=ui->tab_Adherent;
              if (text.isEmpty()) {
                  QMessageBox::information(this, tr("Empty Field"),
                      tr("Entrez une specialité a rechercher."));
                  ui->tab_Adherent->setModel(A.afficher());
                  return;
              } else {
                  findText = text;
                  A.recherche(table,findText.toUInt());


      }
    }



void MainWindow::on_pb_tri_clicked()
{
      ui->tab_Adherent->setModel(A.tri());

}
