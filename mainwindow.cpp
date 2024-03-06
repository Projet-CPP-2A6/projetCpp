#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#define file_tx "^[A-Za-z ]+$"
#define file_ex "^[0-9]+$"
#include <QtLocation>
#include <QSqlRecord>
#include <QResource>
#include <iostream>
#include <QRegularExpression>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::controlSaisie()
{

    if (ui->sexe_r->currentText().isEmpty() ||
        ui->contact_r->text().isEmpty() ||
        ui->nationalite_r->text().isEmpty() ||
        ui->Id_r->text().isEmpty() ||
        ui->nom_r->text().isEmpty() ||
        ui->prenom_r->text().isEmpty()
    )
    {
        return false;
    }

    QRegularExpression contactRegex("[0-9]+");
    if (!contactRegex.match(ui->contact_r->text()).hasMatch()) {
        return false;
    }

    QRegularExpression nomRegex("^[^0-9]+$");
    if (!nomRegex.match(ui->nom_r->text()).hasMatch()) {
        return false;
    }

    QRegularExpression prenomRegex("^[^0-9]+$");
    if (!prenomRegex.match(ui->prenom_r->text()).hasMatch()) {
        return false;
    }

    QRegularExpression nationaliteRegex("^[^0-9]+$");
    if (!nationaliteRegex.match(ui->nationalite_r->text()).hasMatch()) {
        return false;
    }

    return true;
}

void MainWindow::on_add_r_clicked()
{
    QMessageBox msgBox;
    if (controlSaisie())
    {
        QString id = ui->Id_r->text();

        if (art.artisteExists(id.toInt()))
        {
            msgBox.setText("Artiste with ID " + id + " already exists.");
        }
        else
        {
            art.setId(id.toInt());
            art.setNom(ui->nom_r->text());
            art.setPrenom(ui->prenom_r->text());
            art.setNationalite(ui->nationalite_r->text());
            art.setContact(ui->contact_r->text().toInt());
            art.setSexe(ui->sexe_r->currentText());
            bool test = art.ADD();
            if (test) {
                msgBox.setText("Added successfully.");
                ui->stackedWidget->setCurrentIndex(1);
            } else
                msgBox.setText("!! Addition failed !!");
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
            QObject::tr("Please fill all fields correctly.\n"), QMessageBox::Cancel);
    }

    ui->tableArtiste->setModel(art.GETALL());
    msgBox.exec();
}

void MainWindow::on_update_r_clicked()
{
    {

        QMessageBox msgBox;


        if (controlSaisie())
        {
            bool ok;
            int id = ui->Id_r->text().toInt(&ok);

            if (ok)
            {
                if (art.artisteExists(id))
                {

                    art.setId(id);
                    art.setNom(ui->nom_r->text());
                    art.setPrenom(ui->prenom_r->text());
                    art.setNationalite(ui->nationalite_r->text());
                    art.setContact(ui->contact_r->text().toInt());
                    art.setSexe(ui->sexe_r->currentText());

                     ui->tableArtiste->setModel(art.GETALL());

                     bool test = art.UPDATE();

                     if (test)
                     {
                        msgBox.setText("Modification successful.");
                        ui->stackedWidget->setCurrentIndex(1);
                     }
                     else
                     {
                        msgBox.setText("!! Modification failed !!");
                     }
                }
                else
                {

                    msgBox.setText("Artiste with numero " + QString::number(id) + " does not exist.\nCannot modify.");
                }
            }
            else
            {

                msgBox.setText("Veuillez entrer un id de l'artiste valide.");
            }
        }
        else
        {

            msgBox.setText("Veuillez remplir tous les champs.");
        }
        msgBox.exec();
        ui->tableArtiste->setModel(art.GETALL());
    }
}

void MainWindow::on_delete_r_clicked()
{

    int id = ui->artistesup->text().toInt();


    QMessageBox msgBox;
    if (art.artisteExists(id))
    {

        bool test = art.DELETEE(id);


        if (test)
        {
            msgBox.setText("Suppression réussie.");
            ui->tableArtiste->setModel(art.GETALL());
        }
        else
        {
            msgBox.setText("!! La suppression a échoué !!");
        }


        msgBox.exec();
    }
    else
    {

        QMessageBox::warning(this, "Artiste non trouvée", "L'artiste avec l " + QString::number(id) + " n'existe pas.\nImpossible de supprimer.");
    }
}

void MainWindow::on_next_r_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableArtiste->setModel(art.GETALL());
}

void MainWindow::on_tableArtiste_activated(const QModelIndex &index)
{
    ui->tableArtiste->setModel(art.GETALL());

}

void MainWindow::on_back_r_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
