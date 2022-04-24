#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "familles.h"
#include "adherent.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QSqlTableModel>
#include <QTableView>
#include <QFileDialog>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include<QPrintDialog>
#include<QTextEdit>
#include<QDesktopServices>
#include<QPixmapCache>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adherent.h"
#include "smtp.h"
#include<QMessageBox>
#include <QtSql/QSqlError>
#include<QIntValidator>
#include <QCloseEvent>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include<QSystemTrayIcon>
#include <QPlainTextEdit>
#include"employee.h"
#include<QSystemTrayIcon>
#include <QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QPixmap>
#include<QtCore/QCoreApplication>
#include <QtSql/QSqlQuery>
#include <QDateTime>
#include <QtDebug>
#include <QAbstractButton>
#include <QAbstractItemView>
#include <QWidget>
#include <QMessageBox>
#include <QLineEdit>
#include <QDate>
#include <QImage>
#include <QIcon>
#include <QRadioButton>
#include <QDebug>
#include <QVariant>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQueryModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QFile>
#include <QFileDialog>
#include <historique1.h>
#include <QTextStream>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include"produit.h"
#include"arduino.h"
#include"exel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=a.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< a.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<a.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
       QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));



}

MainWindow::~MainWindow()
{
    delete ui;

}
// Familles
void MainWindow::on_pb_ajouter_2_clicked()
{

    int id_famille = ui->Le_id_1->text().toInt();
    QString nom=ui->le_nom_1->text();
    QString prenom=ui->le_prenom_1->text();
    int nbr = ui->le_nbr_1->text().toInt();
    int num = ui->le_tel_1->text().toInt();
    QString loca = ui->la_loca_1->text();
    Familles F(id_famille,nom,prenom,nbr,num,loca);
    bool test=F.ajouter();
    if (test)
    {
        ui->tableView_2->setModel(F.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Ajout effectué\n"),
                                 QMessageBox::Cancel);
         ui->Le_id_1->clear();
        ui->le_nom_1->clear();
        ui->le_prenom_1->clear();
          ui->le_nbr_1->clear();
         ui->le_tel_1->clear();
         ui->la_loca_1->clear();

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("Ajout non  effectué\n"),
                                 QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    Familles F;
        F.setid_famille(ui->Le_id_1->text().toUInt());
        F.setnom(ui->le_nom_1->text());
        F.setprenom(ui->le_prenom_1->text());
        F.setnbr(ui->le_nbr_1->text().toUInt());
        F.setnumero( ui->le_tel_1->text().toUInt());
        F.setloca(ui->la_loca_1->text());
        F.modifier(F);
         ui->tableView_2->setModel(F.afficher());
        bool test=F.modifier(F);
        if (test)
        {
            ui->tableView_2->setModel(F.afficher());
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

void MainWindow::on_pb_supp_2_clicked()
{ Familles F;
    int id_famille=ui->supp_2->text().toInt();
    bool test=F.supprimer(id_famille);

    if (test)


        {
         ui->tableView_2->setModel(F.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("suppression effectué\n"),
                                     QMessageBox::Cancel);
            ui->supp_2->clear();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                     QObject::tr("suppression non  effectué\n"),
                                     QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_12_clicked()
{
    QString findText;
          QString text = ui->lineEdit_3->text();
      Familles f;
      QTableView* table=ui->tableView_2;
          if (text.isEmpty()) {
              QMessageBox::information(this, tr("Empty Field"),
                  tr("Entrez une specialité a rechercher."));
              ui->tableView_2->setModel(f.afficher());
              return;
          } else {
              findText = text;
              f.recherche2(table,findText.toUInt());




  }
}

void MainWindow::on_TRI_2_clicked()
{
    Familles f;

  ui->tableView_2->setModel(f.tri());
}

void MainWindow::on_pushButton_14_clicked()
{
    Familles f;

  ui->tableView_2->setModel(f.trinbr());
}

void MainWindow::on_pushButton_16_clicked()
{
    QString filename=QFileDialog::getOpenFileName (
                this,
    tr("Open File"),
    "C:/Users/Mega-PC/Downloads/VID",
    "All files (*.*);;Text File (*.txt);;Music file(*.mp3)"
    ) ;
    QDesktopServices::openUrl(QUrl("file:///"+filename));
   // QMessageBox::information (this,tr("File Name"),filename);
}

void MainWindow::on_pushButton_17_clicked()
{

    QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png *.jpeg *.jpg *.bmp *.gif)"));
    if (QString::compare(filename,QString()) !=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image=image.scaledToWidth(ui->img_label_2->width(), Qt::SmoothTransformation);
                    ui->img_label_2->setPixmap(QPixmap::fromImage(image));
        }

     }
}

void MainWindow::on_pushButton_13_clicked()
{
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected);

}

void MainWindow::on_pdf_2_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tableView_2->model()->rowCount();
                    const int columnCount = ui->tableView_2->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des Familles </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView_2->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tableView_2->isColumnHidden(column)) {
                                QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table> </center>\n"
                        "</body>\n"
                        "</html>\n";

              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

               QPrinter printer (QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setPaperSize(QPrinter::A4);
              printer.setOutputFileName(fileName);

               QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    QString text ="client details :"+ ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),1)).toString()
           /* +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),2)).toString()
            +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),3)).toString()
            +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString()
            +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),5)).toString()
            +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),6)).toString()*/;
    //text="user data";
    using namespace qrcodegen;
      // Create the QR Code object
      QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );
      qint32 sz = qr.getSize();
      QImage im(sz,sz, QImage::Format_RGB32);
        QRgb black = qRgb(  0,  0,  0);
        QRgb white = qRgb(255,255,255);
      for (int y = 0; y < sz; y++)
        for (int x = 0; x < sz; x++)
          im.setPixel(x,y,qr.getModule(x, y) ? black : white );
      ui->qrCode_2->setPixmap( QPixmap::fromImage(im.scaled(256,256,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );
}

void MainWindow::on_pushButton_15_clicked()
{
    Familles F;
    ui->tableView_2->setModel(F.afficher());
}

void MainWindow::on_pushButton_19_clicked()
{
    QString message = ui->lineEdit2_2->text();
   ui->lineEdit1_2->setText(message);
}


void MainWindow::on_pushButton_20_clicked()
{
    QString message = ui->lineEdit3_2->text();
   ui->lineEdit1_2->setText(message);

}

void MainWindow::on_pb_ajouter_3_clicked()
{
    int id_adherent=ui->le_id_2->text().toInt();
QString nom=ui->le_nom_3->text();
QString prenom=ui->le_prenom_3->text();
QString mail=ui->le_email->text();
int tel=ui->le_tel_3->text().toInt();
QString adresse=ui->le_adresse->text();

Adherent A(id_adherent,nom,prenom,mail,tel,adresse);

bool test=A.ajouter();
if (test)
{
ui->tab_Adherent->setModel(A.afficher());

notification("adherent ajouté");
QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("ajout effectué\n"
                                     "click cancel to exit."), QMessageBox::Cancel);

}
else QMessageBox::critical(nullptr, QObject::tr("not ok"),
                       QObject::tr("Ajout non effectué.\n"
                                   "Click Cancel to exit."),QMessageBox::Cancel);

}
void MainWindow::notification(QString( name)){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Adhérents ",name,QSystemTrayIcon::Information,15000);

}
void MainWindow::clear(){
    ui->le_id_2->clear();
    ui->le_nom_3->clear();
    ui->le_prenom_3->clear();
    ui->le_email->clear();
    ui->le_tel_3->clear();
    ui->le_adresse->clear();
}

void MainWindow::on_annuler_clicked()
{
    clear();
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
                          QObject::tr(" Adhérent modifié .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
       }



       notification("Adhérent modifié");

    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectuée"),  QMessageBox::Cancel);

}

void MainWindow::on_pb_supprimer_clicked()
{ Adherent A;
    int id_adherent= ui->Le_id_supp->text().toInt();
    bool test=A.supprimer(id_adherent);
    if (test)
    {

        notification("Adhérent supprimé");
        ui->tab_Adherent->setModel(A.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("suppression effectué\n"
                                             "click cancel to exit."), QMessageBox::Cancel);

    }
    else QMessageBox::critical(nullptr, QObject::tr("not ok"),
                               QObject::tr("suppression non effectué.\n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);
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
void MainWindow::refresh(){
    Adherent A;
    ui->tab_Adherent->setModel(A.afficher());
}

void MainWindow::on_refresh_clicked()
{
     refresh();
}



void MainWindow::on_trier_clicked()
{
    Adherent A;
    if (ui->radioButton_id->isChecked()) ui->tab_Adherent->setModel(A.TriId());
   if (ui->radioButton_nom->isChecked()) ui->tab_Adherent->setModel(A.Trinom());
   if (ui->radioButton_prenom->isChecked()) ui->tab_Adherent->setModel(A.Triprenom());
}



void MainWindow::on_pdf_3_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tab_Adherent->model()->rowCount();
                    const int columnCount = ui->tab_Adherent->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des Adherents </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tab_Adherent->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_Adherent->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tab_Adherent->isColumnHidden(column)) {
                                QString data = ui->tab_Adherent->model()->data(ui->tab_Adherent->model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table> </center>\n"
                        "</body>\n"
                        "</html>\n";

              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

               QPrinter printer (QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setPaperSize(QPrinter::A4);
              printer.setOutputFileName(fileName);

               QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);
}

void MainWindow::on_quitter_2_clicked()
{

    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the  page? ", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "Answer 'NO' Button is clicked";
    }
}

void MainWindow::on_pushButton_21_clicked()
{

    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the  page? ", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "Answer 'NO' Button is clicked";
    }
}

void MainWindow::on_pushButton_2_clicked()
{

    bool test=true;


    int ID =ui->ID2->text().toInt();
    if(ID<=0 || ID>100){test=false;
    QMessageBox::critical(nullptr, QObject::tr("Ajouter ID"),QObject::tr("ID vide ou invalide! \n Click Ok to close."),QMessageBox::Ok);
    }
     int CIN =ui->CIN2->text().toInt();
     if(CIN<=0 || CIN>100){test=false;
     QMessageBox::critical(nullptr, QObject::tr("Ajouter CIN"),QObject::tr("CIN vide ou invalide! \n Click Ok to close."),QMessageBox::Ok);
     }
     QString Nom =ui->Nom2->text();
     if(Nom==""){test=false;
     QMessageBox::critical(nullptr, QObject::tr("Ajouter Nom"),QObject::tr("Nom vide! \n Click Ok to close."),QMessageBox::Ok);
     }
     QString Prenom =ui->Prenom2->text();
     if(Prenom==""){test=false;
     QMessageBox::critical(nullptr, QObject::tr("Ajouter Prenom"),QObject::tr("Prenom vide! \n Click Ok to close."),QMessageBox::Ok);
     }
     QString Email =ui->Email2->text();
     QString Poste =ui->Poste2->text();
     if(Poste==""){test=false;
     QMessageBox::critical(nullptr, QObject::tr("Ajouter Poste"),QObject::tr("Poste vide! \n Click Ok to close."),QMessageBox::Ok);
     }
     QDate date_naissance = ui->date1->date();
     QDate date_recrutement = ui->date2->date();
     QString Sexe = ui->Sexe2->currentText();
     //QImage img = ui->Image->setPixmap(QPixmap::fromImage(img));


     Employee tmpEmployee(ID,CIN,Nom,Prenom,Email,Poste,Sexe,date_naissance,date_recrutement);
         test=tmpEmployee.AddEmployer();

     if (test)
     { ui->tab_Employee->setModel(tmpEmployee.afficher());

         QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Ajout effectué\n"
                                    "Click concel to exit."), QMessageBox::Cancel);

       notification("Employee ajouté");}

         else
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                 QObject::tr("Ajout non effectué\n"
                                             "Click concel to exit."), QMessageBox::Cancel);
     foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                  le->clear();}
             QFile file("C:/Users/joujo/Documents/crud/Historique/historique.txt");
             if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                 return;
             QTextStream cout(&file);
             QString message2="\n employe a ete ajouté  ";
             cout << message2;



     //QString img = ui->Image;
}

void MainWindow::on_pb_modifier_2_clicked()
{
    int ID=ui->ID2->text().toInt();
   int CIN=ui->CIN2->text().toInt();
QString Nom=ui->Nom2->text();
QString Prenom=ui->Prenom2->text();
QString Email=ui->Email2->text();
QString Poste=ui->Poste2->text();

QDate date_naissance = ui->date1->date();
QDate date_recrutement = ui->date2->date();
QString Sexe=ui->Sexe2->currentText();


 Employee tmpEmployee(ID,CIN,Nom,Prenom,Poste,Email,Sexe,date_naissance,date_recrutement);
 bool test=tmpEmployee.EditEmployer();
 QMessageBox msgBox;
 if(test)
 {
     msgBox.setText("Modification avec succes.");
       ui->tab_Employee->setModel(tmpEmployee.afficher());

 }
 else
     msgBox.setText("Echec de Modification.");
 foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
              le->clear();}
         QFile file("C:/Users/USER/Desktop/Tunisian_humanity_association/Historique/historique.txt");
         if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
             return;
         QTextStream cout(&file);
         QString message2="\n employe Modifié  ";
         cout << message2;
 msgBox.exec();
 MainWindow aa;
 aa.show();
}




void MainWindow::on_pb_supp_3_clicked()
{
    Employee tmpEmployee ;
    int ID=ui->le_supp_2->text().toInt();
        bool test=tmpEmployee.DeleteEmployer(ID);


        if(test){

            //refresh
            ui->tab_Employee->setModel(tmpEmployee.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("Suppression effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("Suppression non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                     le->clear();}
                QFile file("C:/Users/joujo/Documents/crud/Historique/historique.txt");
                if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                    return;
                QTextStream cout(&file);
                QString message2="\n employe a ete supprimé  ";
                cout << message2;

        MainWindow aa;
        aa.show();

}

void MainWindow::on_pushButton_4_clicked()
{
    Employee tmpEmployee;
    ui->tab_Employee->setModel(tmpEmployee.afficher());
     MainWindow aa;
     aa.show();
}

void MainWindow::on_pushButtonHisto_2_clicked()
{
    QString searchString = ui->historique_2->text();
       QTextDocument *document = ui->texthistor->document();
      ouvriremploye();
       bool found = false;

       document->undo();

       if (searchString.isEmpty()) {
           QMessageBox::information(this, tr("Empty Search Field"),
                                    tr("The search field is empty. "
                                       "Please enter a word and click Find."));
       } else {
           QTextCursor highlightCursor(document);
           QTextCursor cursor(document);

           cursor.beginEditBlock();


           QTextCharFormat plainFormat(highlightCursor.charFormat());
           QTextCharFormat colorFormat = plainFormat;
           colorFormat.setForeground(Qt::red);

           while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
               highlightCursor = document->find(searchString, highlightCursor,
                                                QTextDocument::FindWholeWords);

               if (!highlightCursor.isNull()) {
                   found = true;
                   highlightCursor.movePosition(QTextCursor::WordRight,
                                                QTextCursor::KeepAnchor);
                   highlightCursor.mergeCharFormat(colorFormat);

               }
           }


           cursor.endEditBlock();

       }

}
void MainWindow::ouvriremploye()
{
    QFile file ("C:/Users/joujo/Documents/crud/Historique/historique.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
   ui->texthistor->setText(in.readAll());

}

void MainWindow::on_PDF_clicked()
{

    QSqlDatabase db;
                QTableView tab_Employee;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM PERSONNEL ");
                 qry.exec();
                 Modal->setQuery(qry);
                 tab_Employee.setModel(Modal);

                 db.close();

                 QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = tab_Employee.model()->rowCount();
                 const int columnCount =  tab_Employee.model()->columnCount();

                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                         "<img src='C:/Users/joujo/Documents/crud/logo2.png' height='120' width='120'/>"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des employes")
                    <<"<br>"

                    <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCount; column++)
                     if (!tab_Employee.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(tab_Employee.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!tab_Employee.isColumnHidden(column)) {
                             QString data = tab_Employee.model()->data(tab_Employee.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                         <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                     out << "<thead><tr bgcolor=#f0f0f0>";

                         out <<  "</table>\n"

                     "</body>\n"
                     "</html>\n";

                 QTextDocument *document = new QTextDocument();
                 document->setHtml(strStream);

                 QPrinter printer;
                 QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                 if (dialog->exec() == QDialog::Accepted) {

                     document->print(&printer);
                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/employee.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                 delete document;
}

void MainWindow::on_pushButton_clicked()
{

    QFileDialog dialog(this);
            dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
            dialog.setViewMode(QFileDialog::Detail);
            QString fileName =QFileDialog::getOpenFileName(this, tr("Open Images"), "C:/Users/USER/Desktop/Tunisian_humanity_association", tr("Image Files (*.png *.jpg *.bmp)"));
            if (!fileName.isEmpty())
            {
                QImage img(fileName);
                    ui->Image->setPixmap(QPixmap::fromImage(img));
            }
}

void MainWindow::on_Recherche_employee_2_clicked()
{ Employee tmpEmployee ;
    int ID=ui->ID2->text().toInt();
    bool test=tmpEmployee.Recherche_par_ID(ID);
    if(test)
    {
        ui->tab_Employee->setModel(tmpEmployee.Recherche_par_ID(ID));//refresh

        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("ID non trouvé!\n"
                                "Click Ok to close."), QMessageBox::Ok);

}

void MainWindow::on_recherche_CIN_2_clicked()
{Employee tmpEmployee ;
    int CIN=ui->CIN2->text().toInt();
    bool test=tmpEmployee.Recherche_par_CIN(CIN);
    if(test)
    {
        ui->tab_Employee->setModel(tmpEmployee.Recherche_par_CIN(CIN));//refresh

        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("CIN non trouvé!\n"
                                "Click Ok to close."), QMessageBox::Ok);
}




void MainWindow::on_pushButton_5_clicked()
{

    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the  page? ", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "Answer 'NO' Button is clicked";
    }
}



void MainWindow::on_pushButton_7_clicked()
{
     a.write_to_arduino("1");
}



void MainWindow::on_pushButton_47_clicked()
{produit p;

     int id_produit = ui->lineEdit_o1->text().toInt();
    int quantite = ui->lineEdit_o_2->text().toInt();
    int code_barre = ui->lineEdit_o_3->text().toInt();
    QString type_produit = ui->lineEdit_o_4->text();
    QString marque = ui->lineEdit_o_5->text();
    QString libele = ui->lineEdit_o_6->text();
    produit P(int id_produit,int code_barre,int quantite,int id_adherent,QString type_produit,QString marque,QString libele);
    bool test = p.ajouter1();
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



void MainWindow::on_imageo_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png *.jpeg *.jpg *.bmp *.gif)"));
    if (QString::compare(filename,QString()) !=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image=image.scaledToWidth(ui->image_labelo->width(), Qt::SmoothTransformation);
                    ui->image_labelo->setPixmap(QPixmap::fromImage(image));
        }

     }
}



void MainWindow::on_suppo_clicked()
{produit p;
    int id_produit=ui->supp_3o->text().toInt();
    bool test=p.supprimer1(id_produit);

    if (test)


        {
         ui->tableView1->setModel(p.afficher1());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("suppression effectué\n"),
                                     QMessageBox::Cancel);
            ui->supp_3o->clear();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                     QObject::tr("suppression non  effectué\n"),
                                     QMessageBox::Cancel);
        }
}



void MainWindow::on_rechercho_clicked()
{
    QString findText;
          QString text = ui->lineEdito->text();
      produit p;
      QTableView* table=ui->tableView1;
          if (text.isEmpty()) {
              QMessageBox::information(this, tr("Empty Field"),
                  tr("Entrez une specialité a rechercher."));
              ui->tableView1->setModel(p.afficher1());
              return;
          } else {
              findText = text;
              p.recherche1(table,findText.toUInt());
}
}

void MainWindow::on_rechercho_2_clicked()
{produit p;
     ui->tableView1->setModel(p.afficher1());
}

void MainWindow::on_pushButton_11_clicked()
{

   produit p;
        p.setIdProduit(ui->lineEdit_o1->text().toUInt());
        p.setQuantite(ui->lineEdit_o_2->text().toUInt());
        p.setLibele(ui->lineEdit_o_3->text());
        p.setMarque(ui->lineEdit_o_4->text());
        p.setTypeProduit( ui->lineEdit_o_5->text());
        p.setCodeBarre(ui->lineEdit_o_6->text().toUInt());
        p.modifier(p);
         ui->tableView1->setModel(p.afficher1());
        bool test=p.modifier(p);
        if (test)
        {
            ui->tableView1->setModel(p.afficher1());
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
/*
void MainWindow::on_pushButton_22_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT libele,quantite FROM produit");
    query.exec();
    QPieSeries *series = new QPieSeries();
   while(query.next()){
        series->append(query.value(0).toString(), query.value(1).toInt());
    }
    //series->append("test 1", 80);
    //series->append("test 2", 100);
    series->setLabelsVisible(true);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Stock des Produits");

    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);
}*/

void MainWindow::on_exel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                            tr("Excel Files (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "produit", ui->tableView1);

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
