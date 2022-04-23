#ifndef ARDUINOWINDOW_H
#define ARDUINOWINDOW_H

#include <QDialog>
#include "produit.h"
namespace Ui {
class arduinoWindow;
}

class arduinoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit arduinoWindow(QWidget *parent = nullptr);
    ~arduinoWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::arduinoWindow *ui;
    produit d;
};

#endif // ARDUINOWINDOW_H
