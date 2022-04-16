#include "mainwindow.h"
#include "Employee.h"
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








MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    ui->tab_Employee->setModel(tmpEmployee.afficher());
    ui->tab_Employee->setModel(tmpEmployee.afficher());
    mSystemTrayIcon = new QSystemTrayIcon(this);
   mSystemTrayIcon->setIcon(QIcon(":/myappico.png.png"));
    mSystemTrayIcon->setVisible(true);
   //camera
    mCamera = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    mLayout = new QVBoxLayout;
    mOptionMenu = new QMenu("Option", this);
    mAllumerAction = new QAction("Allumer", this);
    mEteindreAction = new QAction("Eteindre", this);
    mCapturerAction = new QAction("Capturer", this);

    mOptionMenu->addActions({mAllumerAction, mEteindreAction, mCapturerAction});
    ui->optionPushButton->setMenu(mOptionMenu);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);

    connect(mAllumerAction, &QAction::triggered, [&](){
     mCamera->start();
    });
    connect(mEteindreAction, &QAction::triggered, [&](){
     mCamera->stop();
    });

    connect(mCapturerAction, &QAction::triggered, [&](){
      auto filename = QFileDialog::getOpenFileName(this, "Capturer", "/" , "Image (*.jpg;* .jpeg");
      if (filename.isEmpty()){return;}

      mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
      QImageEncoderSettings imageEncoderSettings;
      imageEncoderSettings .setCodec("image/jpeg");
      imageEncoderSettings .setResolution(1600, 1200);
      mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
      mCamera->setCaptureMode(QCamera::CaptureStillImage);
      mCamera->start();
      mCamera->searchAndLock();
      mCameraImageCapture->capture(filename);
      mCamera->unlock();

    });


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    /*QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "C:/",
                                                    tr("Images (*.png *.xpm *.jpg)"));

    QPixmap pix(fileName);
    int w = ui->Image->width();
    int h = ui->Image->height();
    ui->Image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->Image->show();*/

    QFileDialog dialog(this);
            dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
            dialog.setViewMode(QFileDialog::Detail);
            QString fileName =QFileDialog::getOpenFileName(this, tr("Open Images"), "C:/Users/joujo/Documents/crud", tr("Image Files (*.png *.jpg *.bmp)"));
            if (!fileName.isEmpty())
            {
                QImage img(fileName);
                    ui->Image->setPixmap(QPixmap::fromImage(img));
            }

    
}

void MainWindow::on_pb_supp_clicked()
{int ID=ui->le_supp->text().toInt();
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


          mSystemTrayIcon->showMessage(tr("Notification"),
                                       tr("Employee ajouté"));}

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


void MainWindow::on_pushButton_4_clicked()
{
    Employee tmpEmployee;
    ui->tab_Employee->setModel(tmpEmployee.afficher());
     MainWindow aa;
     aa.show();
}



void MainWindow::on_pb_modifier_clicked()

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
         QFile file("C:/Users/joujo/Documents/crud/Historique/historique.txt");
         if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
             return;
         QTextStream cout(&file);
         QString message2="\n employe Modifié  ";
         cout << message2;
 msgBox.exec();
 MainWindow aa;
 aa.show();

}


void MainWindow::on_pushButton_5_clicked()
{
    this -> close();
}
void MainWindow::on_Recherche_employee_clicked()
{

    int ID=ui->id->text().toInt();
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
void MainWindow::on_recherche_CIN_clicked()
{

    int CIN=ui->cin->text().toInt();
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
//HISTORIQUE

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

void MainWindow::on_pushButtonHisto_clicked()
{
    QString searchString = ui->historique->text();
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


