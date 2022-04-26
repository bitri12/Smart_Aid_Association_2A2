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

Adherent A;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));

  ui->tab_Adherent->setModel(A.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh(){
    ui->tab_Adherent->setModel(A.afficher());
}
void MainWindow::on_refresh_clicked()
{
    refresh();
}
bool MainWindow::controlSaisie(){


    if (
            !(ui->le_nom->text().contains(QRegExp("^[A-Za-z]+$"))) ||
            !(ui->le_prenom->text().contains(QRegExp("^[A-Za-z]+$"))) ||
            !(ui->le_email->text().contains(QRegExp("^[A-Za-z]+$"))) ||
            !(ui->le_adresse->text().contains(QRegExp("^[A-Za-z]+$"))) ||
            ui->le_id->text().isEmpty() ||
            ui->le_id->text().toInt() == 0 ||
            ui->le_tel->text().isEmpty() ||
            ui->le_tel->text().toInt() == 0 )
        return 0;
    else
        return 1;
}
void MainWindow::notification(QString( name)){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Adhérents ",name,QSystemTrayIcon::Information,15000);

}
void MainWindow::clear(){
    ui->le_id->clear();
    ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->le_email->clear();
    ui->le_tel->clear();
    ui->le_adresse->clear();
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

 notification("adherent ajouté");
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

void MainWindow::on_pdf_clicked()
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
                            "<center> <H1>Liste des Adhérents </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

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

void MainWindow::on_annuler_clicked()
{
    clear();
}


void MainWindow::on_send_mail_clicked()
{
    smtp = new Smtp("departement.adherents@gmail.com" , "Projetcpp2022", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->message_mail->toPlainText();

    smtp->sendMail("THA 2022",ui->a_mail->text(),ui->objet_mail->text(),msg);

    QMessageBox::information(nullptr, QObject::tr("SENT"),
                             QObject::tr("Email Sended Successfully.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_trier_clicked()
{
    if (ui->radioButton_id->isChecked()) ui->tab_Adherent->setModel(A.TriId());
   if (ui->radioButton_nom->isChecked()) ui->tab_Adherent->setModel(A.Trinom());
   if (ui->radioButton_prenom->isChecked()) ui->tab_Adherent->setModel(A.Triprenom());
}



void MainWindow::on_quitter_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the  page? ", QMessageBox::Yes| QMessageBox::No);
        if(reply == QMessageBox::Yes){
            QApplication::quit();
        }else{
            qDebug() << "Answer 'NO' Button is clicked";
        }
}

void MainWindow::on_quitter2_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the  page? ", QMessageBox::Yes| QMessageBox::No);
        if(reply == QMessageBox::Yes){
            QApplication::quit();
        }else{
            qDebug() << "Answer 'NO' Button is clicked";
        }
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the  page? ", QMessageBox::Yes| QMessageBox::No);
        if(reply == QMessageBox::Yes){
            QApplication::quit();
        }else{
            qDebug() << "Answer 'NO' Button is clicked";
        }
}
