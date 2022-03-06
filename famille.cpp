#include "familles.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>

Familles::Familles()
{
id_famille=0;
nom=" ";
prenom="";
nbr=0;
numero=0;
loca=" ";
}
Familles::Familles(int id_famille ,QString nom,QString prenom,int nbr,int numero,QString loca)
{
    this->id_famille=id_famille; this->nom=nom; this->prenom=prenom;  this->numero=numero;this->nbr=nbr; this->loca=loca;
}
int Familles::getid_famille(){return id_famille;}
QString Familles::getnom(){return nom;}
QString Familles::getprenom(){return prenom;}
int Familles::getnumero(){return numero;}
int Familles::getnbr(){return nbr;}
QString Familles::getloca(){return loca;}
void Familles::setid_famille(int id_famille){this->id_famille=id_famille;}
void Familles :: setnom(QString nom){this->nom=nom;}
void Familles :: setprenom(QString prenom){this->prenom=prenom;}
void Familles::setnumero(int numero){this->numero=numero;}
void Familles::setnbr(int nbr){this->nbr=nbr;}
void Familles::setloca(QString loca){this->loca=loca;}



bool Familles::ajouter(){

    QSqlQuery query;
    QString id_string= QString::number(id_famille);
           query.prepare("INSERT INTO Familles  (id_famille, nom, prenom,nbr,numero,loca) "
                        "VALUES (:id, :forename, :surname,:nbr,:numero,:localisation)");
          query.bindValue(":id", id_string);
          query.bindValue(":forename", nom);
          query.bindValue(":surname", prenom);
          query.bindValue(":nbr", nbr);
          query.bindValue(":numero", numero);
          query.bindValue(":localisation", loca);
          query.exec();
          return query.exec();

}
bool Familles::supprimer(int id_famille)
{
    QSqlQuery query;
    QString id_string= QString::number(id_famille);
           query.prepare("DELETE from Familles where id_famille=:id_famille ");

          query.bindValue(":id_famille",id_string);

          query.exec();
           return query.exec();
}
QSqlQueryModel*Familles::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM familles");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbr"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("loca"));


       return model;
}
bool Familles::modifier(Familles f)
{
    QSqlQuery query;

       query.prepare("UPDATE familles SET NOM =:nom , PRENOM =:prenom , nbr =:nbr ,NUMERO =:numero,loca=:loca WHERE id_famille =:id_famille ");
       query.bindValue(":id_famille", f.getid_famille());
       query.bindValue(":nom", f.getnom());
       query.bindValue(":prenom",f.getprenom());
       query.bindValue(":nbr", f.getnbr());
       query.bindValue(":numero", f.getnumero());
       query.bindValue(":loca", f.getloca());
    return query.exec();
}
QSqlQueryModel *Familles::tri()
{
   QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery *q = new QSqlQuery();

    q->prepare("SELECT * FROM familles ORDER BY id_famille ");
    q->exec();
    model->setQuery(*q);
    return model;

}
void Familles::recherche2(QTableView* table,int spec){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from familles  where id_famille=:id_famille");
    query->bindValue(":id_famille",spec);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}



