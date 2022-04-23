#include "statistique.h"
#include "ui_statistique.h"
#include <QSqlQuery>
statistique::statistique(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
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
}

statistique::~statistique()
{
    delete ui;
}

void statistique::on_pushButton_clicked()
{
    menuGestionStock *gestionStock;
    gestionStock = new menuGestionStock();
    gestionStock->show();
    this->close();
}


void statistique::on_pushButton_3_clicked()
{
    VoirStock *voirStock;
    voirStock = new VoirStock();
    voirStock->show();
    this->close();
}

