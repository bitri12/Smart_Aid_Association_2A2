#ifndef DELETEPRODUIT_H
#define DELETEPRODUIT_H

#include <QMainWindow>
#include "menugestionstock.h"
#include "produit.h"
#include <QMessageBox>
#include "voirstock.h"

namespace Ui {
class DeleteProduit;
}

class DeleteProduit : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteProduit(QWidget *parent = nullptr);
    ~DeleteProduit();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::DeleteProduit *ui;
    produit d;
};

#endif // DELETEPRODUIT_H
