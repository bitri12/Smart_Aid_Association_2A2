#ifndef MENUGESTIONSTOCK_H
#define MENUGESTIONSTOCK_H

#include <QMainWindow>
#include "voirstock.h"
QT_BEGIN_NAMESPACE
namespace Ui { class menuGestionStock; }
QT_END_NAMESPACE

class menuGestionStock : public QMainWindow
{
    Q_OBJECT

public:
    menuGestionStock(QWidget *parent = nullptr);
    ~menuGestionStock();
private slots:
    void on_voirStockButton_clicked();

private:
    Ui::menuGestionStock *ui;
};
#endif // MENUGESTIONSTOCK_H
