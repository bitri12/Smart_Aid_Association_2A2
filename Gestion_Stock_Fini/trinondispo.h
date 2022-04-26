#ifndef TRINONDISPO_H
#define TRINONDISPO_H

#include <QMainWindow>
#include "produit.h"
namespace Ui {
class TriNonDispo;
}

class TriNonDispo : public QMainWindow
{
    Q_OBJECT

public:
    explicit TriNonDispo(QWidget *parent = nullptr);
    ~TriNonDispo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TriNonDispo *ui;
    produit t;
};

#endif // TRINONDISPO_H
