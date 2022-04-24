#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"familles.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QDebug>
#include<QTextEdit>
#include "qrcodegen.hpp"
#include <QTextStream>
#include<QPixmap>
#include "smtp.h"
#include <QDialog>
#include"arduino.h"
#include"produit.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QStringList>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_2_clicked();

    void on_pushButton_6_clicked();

    void on_pb_supp_2_clicked();

    void on_pushButton_12_clicked();

    void on_TRI_2_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_13_clicked();

    void on_pdf_2_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pb_ajouter_3_clicked();
    void notification(QString);

    void on_annuler_clicked();
    void clear();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_rech_clicked();

    void on_refresh_clicked();
    void refresh();


    void on_trier_clicked();



    void on_pdf_3_clicked();

    void on_quitter_2_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_2_clicked();

    void on_pb_modifier_2_clicked();



    void on_pb_supp_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButtonHisto_2_clicked();

    void ouvriremploye();





    void on_PDF_clicked();

    void on_pushButton_clicked();

    void on_Recherche_employee_2_clicked();

    void on_recherche_CIN_2_clicked();





    void on_pushButton_5_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_modifier_3_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_22_clicked();

    void on_imageo_clicked();

    void on_suppo_clicked();

    void on_trio_clicked();

    void on_pushButton_9_clicked();

    void on_rechercho_clicked();

    void on_rechercho_2_clicked();


    void on_exel_clicked();

private:
    Ui::MainWindow *ui;
    Arduino a;
    QByteArray data;



};
#endif // MAINWINDOW_H
