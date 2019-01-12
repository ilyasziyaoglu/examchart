#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sql.h"

#include <QMainWindow>
#include <QComboBox>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Sql sql;
    int ks;

    void start();
    void setCombobox(QString query, QComboBox* combobox);
    void setHeaders(QStringList headers);

private slots:

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
