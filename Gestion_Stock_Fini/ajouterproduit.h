#ifndef AJOUTERPRODUIT_H
#define AJOUTERPRODUIT_H

#include <QMainWindow>
#include "voirstock.h"
#include "menugestionstock.h"
#include "produit.h"
#include <QMessageBox>
#include <QSqlError>

namespace Ui {
class ajouterProduit;
}

class ajouterProduit : public QMainWindow
{
    Q_OBJECT

public:
    explicit ajouterProduit(QWidget *parent = nullptr);
    ~ajouterProduit();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::ajouterProduit *ui;
};

#endif // AJOUTERPRODUIT_H
