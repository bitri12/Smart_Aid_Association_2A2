#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include<mainwindow.h>
#include"connection.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_Create_clicked();


    void on_singin_clicked();

private:
    Ui::Login *ui;
      MainWindow *mainwindow;
};

#endif // LOGIN_H
