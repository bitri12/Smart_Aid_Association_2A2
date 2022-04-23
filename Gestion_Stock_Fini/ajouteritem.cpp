#include "ajouteritem.h"
#include "ui_ajouteritem.h"

AjouterItem::AjouterItem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AjouterItem)
{
    ui->setupUi(this);
}

AjouterItem::~AjouterItem()
{
    delete ui;
}
