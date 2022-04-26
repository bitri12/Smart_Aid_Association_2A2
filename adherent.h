#ifndef ADHERENT_H
#define ADHERENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>

class Adherent
{
    int id_adherent ;
    QString nom;
    QString prenom;
    QString mail;
    int tel;
    QString adresse;

public:
    Adherent();
    Adherent(int,QString,QString,QString,int,QString);

    QString getNom();
    QString getPrenom();
    QString getEmail();
    int getId();
    QString getAdresse();
    int getTel();

    void setNom(QString);
    void setPrenom(QString);
    void setEmail(QString);
    void setId(int);
    void setTel(int);
    void setAdresse(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(Adherent);
     QSqlQueryModel * tri();
     QSqlQueryModel * TriId();
     QSqlQueryModel * Trinom();
     QSqlQueryModel * Triprenom();
 void recherche(QTableView* table,int);
};

#endif // ADHERENT_H
