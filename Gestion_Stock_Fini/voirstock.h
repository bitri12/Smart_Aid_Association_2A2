#ifndef VOIRSTOCK_H
#define VOIRSTOCK_H

#include <QMainWindow>
#include "menugestionstock.h"
#include "ajouterproduit.h"
#include "deleteproduit.h"
#include "modifierproduit.h"
#include "statistique.h"
#include "tridispo.h"
#include "trinondispo.h"
#include "arduinowindow.h"
namespace Ui {
class VoirStock;
}

class VoirStock : public QMainWindow
{
    Q_OBJECT

public:
    explicit VoirStock(QWidget *parent = nullptr);
    ~VoirStock();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::VoirStock *ui;
    produit a;
};

#endif // VOIRSTOCK_H
