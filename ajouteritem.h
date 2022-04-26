#ifndef AJOUTERITEM_H
#define AJOUTERITEM_H

#include <QMainWindow>

namespace Ui {
class AjouterItem;
}

class AjouterItem : public QMainWindow
{
    Q_OBJECT

public:
    explicit AjouterItem(QWidget *parent = nullptr);
    ~AjouterItem();

private:
    Ui::AjouterItem *ui;
};

#endif // AJOUTERITEM_H
