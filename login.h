#ifndef LOGIN_H
#define LOGIN_H

#include "mainwindow.h"

#include <QSqlQueryModel>
#include <QMessageBox>
#include <QMainWindow>
#include <QDebug>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow w;
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
