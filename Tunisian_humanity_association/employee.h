#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include<QtCore/QCoreApplication>
#include <QtSql/QSqlQuery>
#include <QDateTime>
#include <QtDebug>
#include <QDate>
#include <QImage>
#include <QDebug>
#include <QVariant>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QAbstractButton>
#include <QPixmap>
#include <QByteArray>

using namespace std;


class Employee

{
private:

    int ID, CIN;
    QString Nom, Prenom, Poste, Email, Sexe ;
    QDate date_naissance, date_recrutement;
    QImage img;

public:
    Employee();
    Employee(int,int,QString,QString,QString,QString,QString,QDate,QDate);
    int get_ID();
    int get_CIN();
    QString get_Nom();
    QString get_Prenom();
    QString get_Poste();
    QString get_Email();
    QString get_Sexe();
    QDate get_date_naissance();
    QDate get_date_recrutement();
    QImage getImage();
    void set_ID(int ID);
    void set_CIN(int CIN);
    void set_Nom(QString Nom);
    void set_Prenom(QString Prenom);
    void set_Poste(QString Poste);
    void set_Email(QString Email);
    void set_Sexe(QString Sexe);
    void set_date_naissance(QDate date_naissance);
    void set_date_recrutement(QDate date_recrutement);
    void setImage( QImage img);
    bool AddEmployer();
    bool EditEmployer();
    bool DeleteEmployer(int);
    QSqlQueryModel *afficher();
    QSqlQueryModel *Recherche_par_ID(int);
    QSqlQueryModel *Recherche_par_CIN(int);


};

#endif // EMPLOYEE_H
