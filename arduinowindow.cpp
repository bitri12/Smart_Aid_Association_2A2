#include "arduinowindow.h"
#include "ui_arduinowindow.h"
#include "arduino.h"
#include <QMessageBox>
arduinoWindow::arduinoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arduinoWindow)
{
    ui->setupUi(this);
}

arduinoWindow::~arduinoWindow()
{
    delete ui;
}

void arduinoWindow::on_pushButton_clicked()
{
    Arduino A;
    int id = ui->lineEdit->text().toInt();

    QByteArray data = A.read_from_arduino();
    int qty = data.toInt();
    bool test = d.retirer(id,qty);
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Done"),QMessageBox::Cancel);
        QByteArray quantity;
        quantity.setNum(qty);
        A.write_to_arduino(quantity);
    } else {
        QMessageBox::information(nullptr,QObject::tr("Not OK"),QObject::tr("not done"),QMessageBox::Cancel);
    }
}


void arduinoWindow::on_pushButton_2_clicked()
{
    this->close();
}

