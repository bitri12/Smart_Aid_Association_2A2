#ifndef FAMILLES_H
#define FAMILLES_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>



class Familles
{
public:
    Familles();
    Familles(int ,QString,QString,int,int,QString);
    int getid_famille();
    QString getnom();
    QString getprenom();
    int getnbr();
    int getnumero();
    QString getloca();
    void setid_famille(int);
    void setnom(QString);
    void setprenom(QString);
    void setnbr(int);
    void setnumero(int);
    void setloca(QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(Familles f);
    QSqlQueryModel* tri();
    QSqlQueryModel* trinbr();
  void recherche2(QTableView* table,int);
  bool login();
  QString USERNAME;
  QString PASSWORD;



private:
    int id_famille;
    QString nom;
    QString prenom;
    int nbr;
    int numero;
    QString loca;


};

#endif // FAMILLES_H
