#ifndef SECDIALOG_H
#define SECDIALOG_H

#include<QDialog>

namespace Ui{
class SecDeialog;
}

class SecDeialog : public QDialog{
        Q_OBJECT
public:
    explicit SecDeialog(QWidget *parent = 0);
    ~SecDeialog();

private:
    Ui::SecDeialog *ui;
};

#endif // SECDIALOG_H
