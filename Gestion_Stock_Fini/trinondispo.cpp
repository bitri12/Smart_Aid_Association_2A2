#include "trinondispo.h"
#include "ui_trinondispo.h"
TriNonDispo::TriNonDispo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TriNonDispo)
{
    ui->setupUi(this);
    ui->tableView->setModel(t.Trinondispo());
}

TriNonDispo::~TriNonDispo()
{
    delete ui;
}

void TriNonDispo::on_pushButton_clicked()
{
    this->close();
}

