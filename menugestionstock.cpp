#include "menugestionstock.h"
#include "ui_menugestionstock.h"

menuGestionStock::menuGestionStock(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menuGestionStock)
{
    ui->setupUi(this);
}

menuGestionStock::~menuGestionStock()
{
    delete ui;
}


void menuGestionStock::on_voirStockButton_clicked()
{
    VoirStock *voirStock;
    voirStock = new VoirStock();
    voirStock->show();
    this->close();
}




