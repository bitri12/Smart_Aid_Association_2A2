#include "Employee.h"

Employee::Employee(){
    ID=0;
    CIN=0;
    Nom="";
    Prenom="";
    Poste="";
    Email="";
    Sexe="";
    //img="";

}

Employee::Employee(int ID,int CIN, QString Nom, QString Prenom, QString Poste, QString Email, QString Sexe,  QDate date_naissance, QDate date_recrutement)
{

    this->ID = ID;
    this->CIN =CIN;
    this->Nom = Nom;
    this->Prenom = Prenom;
    this->Poste = Poste;
    this->Email = Email;
    this->Sexe = Sexe;
    this->date_naissance = date_naissance;
    this->date_recrutement = date_recrutement;
    this->img = img;

}
int Employee::get_ID(){
    return this->ID;
}

int Employee::get_CIN(){
    return this->CIN;
}

QString Employee::get_Nom(){
    return this->Nom;
}

QString Employee::get_Prenom(){
    return this->Prenom;
}


QString Employee::get_Poste(){
    return this->Poste;
}

QString Employee::get_Email(){
    return this->Email;
}


QString Employee::get_Sexe(){
    return this->Sexe;
}


QDate Employee::get_date_naissance(){
    return this->date_naissance;
}
QDate Employee::get_date_recrutement(){
    return this->date_recrutement;
}
QImage Employee::getImage()
{
    return this->img;
}


void Employee::set_ID(int ID){
    this->ID = ID;
}
void Employee::set_CIN(int CIN){
    this->CIN = CIN;
}
void Employee::set_Nom(QString Nom){
    this->Nom = Nom;
}
void Employee::set_Prenom(QString Prenom){
    this->Prenom = Prenom;
}
void Employee::set_Poste(QString Poste){
    this->Poste = Poste;
}
void Employee::set_Email(QString Email){
    this->Email = Email;
}

void Employee::set_Sexe(QString Sexe){
    this->Sexe = Sexe;
}

void Employee::set_date_naissance(QDate date_naissance){
    this->date_naissance = date_naissance;
}
void Employee::set_date_recrutement(QDate date_recrutement){
    this->date_recrutement = date_recrutement;
}
void Employee::setImage(QImage img)
{
    this->img = img;
}

bool Employee::AddEmployer()
{
   QSqlQuery query;
   QString res= QString::number(ID);
   QString res1= QString::number(CIN);
   query.prepare("INSERT INTO PERSONNEL(ID,CIN,Nom,Prenom,Poste,Email,Sexe,date_naissance,date_recrutement,img) VALUES (:ID,:CIN,:Nom,:Prenom,:Poste,:Email,:Sexe,:date_naissance,:date_recrutement,:img)");
  query.bindValue(":ID",res);
  query.bindValue(":CIN",res1);
  query.bindValue(":Nom",Nom);
  query.bindValue(":Prenom",Prenom);
  query.bindValue(":Poste",Poste);
  query.bindValue(":Email",Email);
  query.bindValue(":Sexe",Sexe);
  query.bindValue(":date_naissance",date_naissance);
  query.bindValue(":date_recrutement",date_recrutement);
  query.bindValue(":img",img);
  return query.exec();

}

bool Employee::EditEmployer()
{
    QSqlQuery query;
    query.prepare("UPDATE PERSONNEL SET ID= :ID, CIN = :CIN, Nom = :Nom, Prenom = :Prenom, Poste = :Poste, Email = :Email,  Sexe = :Sexe, date_naissance = :date_naissance, date_recrutement = :date_recrutement, img = :img where ID =:ID ");
    QString res= QString::number(ID);
    QString res1= QString::number(CIN);
    query.bindValue(":ID",res);
    query.bindValue(":CIN",res1);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Prenom",Prenom);
    query.bindValue(":Poste",Poste);
    query.bindValue(":Email",Email);
    query.bindValue(":Sexe",Sexe);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":date_recrutement",date_recrutement);
    query.bindValue(":img",img);
    if(query.exec()){
        return true;
    }else{
         qDebug()<< "erreur de modification de l'Employer du a:" <<query.lastError().text();
         return false;
    }
}

bool Employee::DeleteEmployer(int ID)
{
    QSqlQuery query;
        QString res=QString::number(ID);
        query.prepare("DELETE FROM PERSONNEL where ID=:ID");
        query.bindValue(":ID",res);
        return query.exec();
}

QSqlQueryModel * Employee::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from PERSONNEL ");
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"CIN");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"Prenom");
     model->setHeaderData(4,Qt::Horizontal,"Poste");
     model->setHeaderData(5,Qt::Horizontal,"Email");
     model->setHeaderData(7,Qt::Horizontal,"date_naissance");
     model->setHeaderData(8,Qt::Horizontal,"date_recrutement");
     model->setHeaderData(9,Qt::Horizontal,"img");
    return model ;
}

QSqlQueryModel * Employee::Recherche_par_ID(int ID)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString code=QString::number(ID);
    model->setQuery("select * from PERSONNEL where ID="+code);
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"CIN");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"Prenom");
     model->setHeaderData(4,Qt::Horizontal,"Poste");
     model->setHeaderData(5,Qt::Horizontal,"Email");
     model->setHeaderData(6,Qt::Horizontal,"Sexe");
     model->setHeaderData(7,Qt::Horizontal,"date_naissance");
     model->setHeaderData(8,Qt::Horizontal,"date_recrutement");
     model->setHeaderData(9,Qt::Horizontal,"img");
     return model ;
}

QSqlQueryModel * Employee::Recherche_par_CIN(int CIN)
{   QSqlQueryModel *model = new QSqlQueryModel();
    QString code=QString::number(CIN);
    model->setQuery("select * from PERSONNEL where CIN="+code);
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"CIN");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"Prenom");
     model->setHeaderData(4,Qt::Horizontal,"Poste");
     model->setHeaderData(5,Qt::Horizontal,"Email");
     model->setHeaderData(6,Qt::Horizontal,"Sexe");
     model->setHeaderData(7,Qt::Horizontal,"date_naissance");
     model->setHeaderData(8,Qt::Horizontal,"date_recrutement");
     model->setHeaderData(9,Qt::Horizontal,"img");
     return model ;
}




