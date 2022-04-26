#ifndef PRODUIT_H
#define PRODUIT_H
#include <QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include<QTableView>
#include <QSqlTableModel>
#include<QString>
#include <QFile>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QImage>
#include <QPixmap>
#include <QByteArray>
class produit
{
    int id_produit, quantite,id_adherent,code_barre;
    QString type_produit, marque,libele;
    QImage photo;

public:
    //initialisation
    produit();
    produit(int,int,int,int,QString,QString,QString);
    //getters
    int getIdProduit();
    int getQuantite();
    int getIdAdherent();
    int getCodeBarre();
    QString getTypeProduit();
    QString getMarque();
    QString getLibele();
    //setters
    void setCodeBarre(int);
    void setIdProduit(int);
    void setQuantite(int);
    void setIdAdherent(int);
    void setTypeProduit(QString);
    void setMarque(QString);
    void setLibele(QString);
    //CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(produit);
    //METIER
    QSqlQueryModel * Tridispo();
    QSqlQueryModel * Trinondispo();
    QSqlQueryModel * triId();
    QSqlQueryModel * recherche(QString);
    // Suplément

    bool retirer(int,int);

};

#endif // PRODUIT_H
