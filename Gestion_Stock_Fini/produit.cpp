#include "produit.h"
//initialisation
produit::produit()
{
    int id_produit = 0;
    int quantite = 0;
    int id_adherent = 0;
    int code_barre = 0;
    QString type_produit = " ";
    QString marque = " ";
    QString libele = " ";
}

produit::produit(int id_produit,int code_barre,int quantite,int id_adherent,QString type_produit,QString marque,QString libele) {
    this->id_produit = id_produit;
    this->quantite = quantite;
    this->id_adherent = id_adherent;
    this->type_produit = type_produit;
    this->marque = marque;
    this->libele = libele;
    this->code_barre = code_barre;
}
//getters
int produit::getCodeBarre(){
    return code_barre;
}

int produit::getIdAdherent() {
    return id_adherent;
}

int produit::getIdProduit(){
    return id_produit;
}
int produit::getQuantite(){
    return quantite;
}



QString produit::getLibele(){
    return libele;
}
QString produit::getMarque(){
    return marque;
}

QString produit::getTypeProduit() {
    return type_produit;
}

//Setters
void produit::setCodeBarre(int code_barre){
    this->code_barre = code_barre;
}

void produit::setIdAdherent(int id_adherent){
    this->id_adherent = id_adherent;
}
void produit::setIdProduit(int id_produit){
    this->id_produit = id_produit;
}

void produit::setLibele(QString l){
    libele = l;
}

void produit::setMarque(QString m){
    marque = m;
}

void produit::setQuantite(int quantite){
    this->quantite = quantite;
}
void produit::setTypeProduit(QString t){
    type_produit = t;
}
//CRUD

bool produit::ajouter() {
    QSqlQuery query;
    QString id_produit_convertit= QString::number(id_produit);
    QString id_adherent_convertit= QString::number(id_adherent);
    QString quantite_convertit= QString::number(quantite);
    QString code_barre_convertit= QString::number(code_barre);
    query.prepare("INSERT INTO produit(id_produit, id_adherent, quantite, code_barre, type_produit, marque,libele) VALUES (:id_produit, :id_adherent, :quantite, :code_barre, :type_produit, :marque, :libele)");
    query.bindValue(":id_produit", id_produit_convertit);
    query.bindValue(":id_adherent", id_adherent_convertit);
    query.bindValue(":quantite", quantite_convertit);
    query.bindValue(":code_barre", code_barre_convertit);
    query.bindValue(":type_produit", type_produit);
    query.bindValue(":marque", marque);
    query.bindValue(":libele", libele);
    return query.exec();
}
bool produit::supprimer(int id_produit)
{
    QSqlQuery query;
    QString id_produit_convertit = QString::number(id_produit);
    query.prepare("DELETE FROM produit WHERE id_produit=:id_produit");
    query.bindValue(":id_produit", id_produit_convertit);
    return query.exec();
}
QSqlQueryModel* produit::afficher()
{
    QSqlQueryModel* model= new QSqlQueryModel();
          model->setQuery("SELECT * FROM produit");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_produit"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("libele"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("code_barre"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_adherent"));
    return model;
}
bool produit::modifier(produit p)
{

    QSqlQuery edit;
    edit.prepare("update produit set id_produit = :id_produit, type_produit = :type_produit, marque = :marque, libele = :libele, code_barre = :code_barre, id_adherent = :id_adherent, quantite = :quantite WHERE id_produit = :id_produit");
    edit.bindValue(":id_adherent",p.getIdAdherent());
    edit.bindValue(":id_produit",p.getIdProduit());
    edit.bindValue(":type_produit",p.getTypeProduit());
    edit.bindValue(":marque",p.getMarque());
    edit.bindValue(":libele",p.getLibele());
    edit.bindValue(":code_barre",p.getCodeBarre());
    edit.bindValue(":quantite",p.getQuantite());
    return edit.exec();
}
//Metier

QSqlQueryModel * produit::Tridispo() {
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM produit WHERE quantite > 0");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("libele"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("code_barre"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_adherent"));
    return model;
}
QSqlQueryModel * produit::Trinondispo() {
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM produit WHERE quantite = 0");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("libele"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("code_barre"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_adherent"));
    return model;
}

QSqlQueryModel * produit::recherche(QString re) {
    QSqlQueryModel * model=new QSqlQueryModel();

    //id_pr, nom, prix, qr_code, stock, image, date_impo, description

    model->setQuery("SELECT * FROM produit WHERE ID_PRODUIT LIKE '"+re+"%' OR MARQUE LIKE '"+re+"%' OR LIBELE LIKE '"+re+"%' OR CODE_BARRE LIKE '"+re+"%'");
    // model->setQuery("SELECT * FROM reclamation WHERE numrec LIKE '"+recherche+"%' OR titre LIKE '"+recherche+"%' OR type LIKE '"+recherche+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("libele"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("code_barre"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_adherent"));
    return model;
}

bool produit::retirer(int id_produit, int Quantite) {
        QSqlQuery edit;
        QString id_produit_convertit= QString::number(id_produit);
        QString quantite_convertit= QString::number(Quantite);
        edit.prepare("update produit set quantite = :quantite WHERE id_produit = :id_produit");
        edit.bindValue(":quantite", quantite_convertit);
        edit.bindValue(":id_produit", id_produit_convertit);
    return edit.exec();
}
