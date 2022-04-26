#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QMainWindow>
#include "menugestionstock.h"
#include "voirstock.h"
#include <QtCharts>

namespace Ui {
class statistique;
}

class statistique : public QMainWindow
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::statistique *ui;
};

#endif // STATISTIQUE_H
