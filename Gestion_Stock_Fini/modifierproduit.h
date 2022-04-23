#ifndef MODIFIERPRODUIT_H
#define MODIFIERPRODUIT_H

#include <QMainWindow>
#include "menugestionstock.h"
#include "voirstock.h"
namespace Ui {
class modifierProduit;
}

class modifierProduit : public QMainWindow
{
    Q_OBJECT

public:
    explicit modifierProduit(QWidget *parent = nullptr);
    ~modifierProduit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::modifierProduit *ui;
};

#endif // MODIFIERPRODUIT_H
