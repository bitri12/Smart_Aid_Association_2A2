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
#include "arduino.h"

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();


    void on_pb_supp_clicked();

    void on_pushButton_clicked();

    void on_TRI_clicked();




    void on_pushButton_2_clicked();

    void on_pdf_clicked();

    void on_pushButton_3_clicked();
   bool controlSaisie();

   void on_pushButton_4_clicked();


   void on_pushButton_5_clicked();

   void on_pushButton_6_clicked();

   void on_pushButton_7_clicked();

   void on_pushButton_8_clicked();

   void on_pushButton_9_clicked();


   void on_pushButton_10_clicked();

   void on_pushButton_11_clicked();

   void on_pushButton_12_clicked();

   void on_pushButton_13_clicked();
void update_label();

private:
    Ui::MainWindow *ui;
    Familles F;
    Arduino a ;
    QByteArray data;
};

#endif // MAINWINDOW_H
