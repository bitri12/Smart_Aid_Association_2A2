#include "adherent.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include<QTableView>
#include <QSqlTableModel>
Adherent::Adherent()
{
    id_adherent=0;
    nom=" ";
    prenom=" ";
    mail=" ";
    tel=0;
    adresse=" ";

}

Adherent::Adherent(int id_adherent,QString nom,QString prenom,QString mail,int tel,QString adresse)
{
    this->id_adherent=id_adherent;
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->tel=tel;
    this->adresse=adresse;
}



int Adherent::getId(){return id_adherent;}
QString Adherent::getNom(){return nom;}
QString Adherent::getPrenom(){return prenom;}
QString Adherent::getEmail(){return mail;}
int Adherent::getTel(){return tel;}
QString Adherent::getAdresse(){return adresse;}

void Adherent::setId(int id_adherent){this->id_adherent=id_adherent;}
void Adherent::setNom(QString){this->nom=nom;}
void Adherent::setPrenom(QString){this->prenom=prenom;}
void Adherent::setEmail(QString){this->mail=mail;}
void Adherent::setTel(int id_adherent){this->id_adherent=id_adherent;}
void Adherent::setAdresse(QString){this->adresse=adresse;}


bool Adherent::ajouter()
{
    QSqlQuery query;
QString res= QString::number(id_adherent);
QString res1= QString::number(tel);
query.prepare("INSERT INTO adherent (id_adherent, nom, prenom, mail, tel, adresse) "
                       "VALUES (:id_adherent, :nom, :prenom, :mail, :tel, :adresse)");
         query.bindValue(":id_adherent", res);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":mail", mail);
          query.bindValue(":tel", res1);
          query.bindValue(":adresse", adresse);

        return query.exec();

}
bool Adherent::supprimer(int id_adherent )
{
    QSqlQuery query;
    query.prepare("Delete from Adherent where id_adherent=:id_adherent");
         query.bindValue(0, id_adherent);


        return query.exec();
}

QSqlQueryModel* Adherent::afficher()
{


    QSqlQueryModel* model= new QSqlQueryModel();
          model->setQuery("SELECT * FROM adherent");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_adherent"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));

    return model;
   }
bool Adherent::modifier( Adherent A)
{

    QSqlQuery edit;


                      edit.prepare("update ADHERENT set NOM = :nom, PRENOM = :prenom,MAIL = :mail,TEL = :tel,ADRESSE = :adresse WHERE ID_ADHERENT = :id_adherent");

                      edit.bindValue(":id_adherent",A.getId());
                      edit.bindValue(":nom",A.getNom());
                      edit.bindValue(":prenom",A.getPrenom());
                      edit.bindValue(":mail",A.getEmail());
                      edit.bindValue(":tel",A.getTel());
                      edit.bindValue(":adresse",A.getAdresse());
                      return    edit.exec();
}

QSqlQueryModel *Adherent::tri()
{

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * FROM  Adherent ORDER BY id_adherent ");
    q->exec();
    model->setQuery(*q);
    return model;
}

QSqlQueryModel * Adherent::TriId()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from adherent ORDER BY id_adherent");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ADHERENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));

    return model;
}

QSqlQueryModel * Adherent::Trinom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from adherent ORDER BY nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ADHERENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));

    return model;
}

QSqlQueryModel * Adherent::Triprenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Adherent ORDER BY prenom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ADHERENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));

    return model;
}
void Adherent::recherche(QTableView* table,int res){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from Adherent  where id_adherent=:id_adherent");
    query->bindValue(":id_adherent",res);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}



