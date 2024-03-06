#ifndef ARTISTE_H
#define ARTISTE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlError>

class artiste
{
private:
    int id;
    QString nom;
    QString prenom;
    QString nationalite;
    int contact;
    QString sexe;
public:

    artiste();
    artiste(int id, QString nom, QString prenom, QString nationalite, int contact, QString sexe);


    void setId(int id);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setNationalite(QString nationalite);
    void setContact(int contact);
    void setSexe(QString sexe);

    int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getNationalite() const;
    int getContact() const;
    QString getSexe() const;

    QSqlQueryModel* GETALL();
    bool DELETEE(int id);
    bool ADD();
    bool artisteExists(int id);
    bool UPDATE();
};

#endif // ARTISTE_H
