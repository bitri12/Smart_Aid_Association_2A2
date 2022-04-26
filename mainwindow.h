#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <adherent.h>
#include "smtp.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void refresh();
void notification(QString);
bool controlSaisie();
void clear();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();



    void on_pb_modifier_clicked();

    void on_pb_rech_clicked();

//    void on_pb_tri_clicked();

    void on_pdf_clicked();

    void on_annuler_clicked();

    void on_send_mail_clicked();

    //void on_send_mail_2_clicked();

    //void on_send_mail_pressed();

    void on_trier_clicked();

    void on_refresh_clicked();

    void on_quitter_clicked();

    void on_quitter2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Adherent A;
    QStringList files;
    Smtp* smtp;
    QString msg;
    QString mail;
};
#endif // MAINWINDOW_H
