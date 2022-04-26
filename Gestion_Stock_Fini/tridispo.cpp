#include "tridispo.h"
#include "ui_tridispo.h"

TriDispo::TriDispo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TriDispo)
{
    ui->setupUi(this);
    ui->tableView->setModel(t.Tridispo());

}

TriDispo::~TriDispo()
{
    delete ui;
}

void TriDispo::on_pushButton_clicked()
{
    this->close();
}

