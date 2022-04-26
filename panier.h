#ifndef PANIER_H
#define PANIER_H
#include <QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include<QTableView>
#include <QSqlTableModel>
#include<QString>

class panier
{
    int id_panier;
public:
    panier();
    panier(int);
    int getIdPanier();
    void setIdPanier();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(panier);
};

#endif // PANIER_H
