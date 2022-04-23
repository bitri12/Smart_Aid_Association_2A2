#ifndef TRIDISPO_H
#define TRIDISPO_H

#include <QMainWindow>
#include "produit.h"
namespace Ui {
class TriDispo;
}

class TriDispo : public QMainWindow
{
    Q_OBJECT

public:
    explicit TriDispo(QWidget *parent = nullptr);
    ~TriDispo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TriDispo *ui;
    produit t;
};

#endif // TRIDISPO_H
