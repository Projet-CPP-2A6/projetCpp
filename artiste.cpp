#include "artiste.h"

artiste::artiste()
{
}
artiste::artiste(int id, QString nom, QString prenom, QString nationalite, int contact, QString sexe)
{
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->nationalite = nationalite;
    this->contact = contact;
    this->sexe = sexe;
}

bool artiste::UPDATE()
{
    QSqlQuery query;
    query.prepare("UPDATE artiste SET nom=:nom, prenom=:prenom, nationalite=:nationalite, contact=:contact, sexe=:sexe WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":nationalite", nationalite);
    query.bindValue(":contact", contact);
    query.bindValue(":sexe", sexe);
    return query.exec();
}
bool artiste::ADD()
{
    QSqlQuery query;
    query.prepare("INSERT INTO artiste (id, nom, prenom, nationalite, contact, sexe) "
                  "VALUES (:id, :nom, :prenom, :nationalite, :contact, :sexe)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":nationalite", nationalite);
    query.bindValue(":contact", contact);
    query.bindValue(":sexe", sexe);
    return query.exec();
}

bool artiste::DELETEE(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM artiste WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel* artiste::GETALL()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom, prenom, nationalite, contact, sexe FROM artiste");
    if (model->lastError().isValid()) {
        qDebug() << "Error in SQL Query: " << model->lastError().text();
        return nullptr;
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nationalite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("contact"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
    return model;
}
bool artiste::artisteExists(int id)
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT id FROM artiste WHERE id=:id");
    checkQuery.bindValue(":id", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "Error checking if artiste exists:" << checkQuery.lastError();
    }
    return exists;
}

void artiste::setId(int id)
{
    this->id = id;
}

void artiste::setNom(QString nom)
{
    this->nom = nom;
}

void artiste::setPrenom(QString prenom)
{
    this->prenom = prenom;
}

void artiste::setNationalite(QString nationalite)
{
    this->nationalite = nationalite;
}

void artiste::setContact(int contact)
{
    this->contact = contact;
}

void artiste::setSexe(QString sexe)
{
    this->sexe = sexe;
}

int artiste::getId() const
{
    return id;
}

QString artiste::getNom() const
{
    return nom;
}

QString artiste::getPrenom() const
{
    return prenom;
}

QString artiste::getNationalite() const
{
    return nationalite;
}

int artiste::getContact() const
{
    return contact;
}

QString artiste::getSexe() const
{
    return sexe;
}
