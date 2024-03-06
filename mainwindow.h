#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "artiste.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    bool  controlSaisie();
    void on_add_r_clicked();

    void on_next_r_clicked();

    void on_tableArtiste_activated(const QModelIndex &index);

    void on_back_r_clicked();

    void on_delete_r_clicked();

    void on_update_r_clicked();

private:
    Ui::MainWindow *ui;
    artiste art;
};
#endif // MAINWINDOW_H
