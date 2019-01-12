#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::setCombobox(QString query, QComboBox* combobox){
    combobox->setModel(sql.sqlQuery(query));
    combobox->setModelColumn(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start(){
    if(ks == 2){
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tabWidget->setTabEnabled(8, false);
        ui->pushButton_9->hide();
        ui->pushButton_12->hide();
    }

    setCombobox("select kampus_id, kampus_adi from kampusler", ui->comboBox);

    sql.tableModel = sql.sqlQueryEditable("select * from kampusler");
    ui->tableView->setModel(sql.tableModel);
    sql.tableModel->setTable("kampusler");
    setHeaders({"ID", "Kampüs Adı"});
    sql.tableModel->select();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    int row = sql.tableModel->rowCount();
    int col = sql.tableModel->columnCount();
    sql.tableModel->insertRows(row, 1);
    QModelIndex index = sql.tableModel->index(row, col);
    ui->tableView->setCurrentIndex(index);
    ui->tableView->edit(index);
}

void MainWindow::on_pushButton_12_clicked()
{
    int row = ui->tableView->currentIndex().row();
    sql.tableModel->removeRow(row);
    ui->tableView->hideRow(row);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(ks == 2){
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    switch (index) {
    case 0:
        sql.tableModel = sql.sqlQueryEditable("select * from kampusler");
        sql.tableModel->setTable("kampusler");
        setHeaders({ "ID", "Kampüs Adı"});
        break;
    case 1:
        sql.tableModel = sql.sqlQueryEditable("select * from fakulteler");
        sql.tableModel->setTable("fakulteler");
        sql.tableModel->setRelation(1, QSqlRelation("kampusler", "kampus_id", "kampus_adi"));
        setHeaders({ "ID", "Kampüs", "Fakülte Adı", "Fakülte Kodu"});
        break;
    case 2:
        sql.tableModel = sql.sqlQueryEditable("select * from bolumler");
        sql.tableModel->setTable("bolumler");
        sql.tableModel->setRelation(1, QSqlRelation("fakulteler", "fakulte_id", "fakulte_adi"));
        setHeaders({ "ID", "Fakülte", "Bölüm Adı", "Bölüm Kodu"});
        break;
    case 3:
        sql.tableModel = sql.sqlQueryEditable("select * from personeller");
        sql.tableModel->setTable("personeller");
        sql.tableModel->setRelation(2, QSqlRelation("bolumler", "bolum_id", "bolum_adi"));
        setHeaders({ "ID", "Personel No", "Bölüm", "Ad Soyad", "Ünvan"});
        break;
    case 4:
        sql.tableModel = sql.sqlQueryEditable("select * from salonlar");
        sql.tableModel->setTable("salonlar");
        sql.tableModel->setRelation(2, QSqlRelation("bolumler", "bolum_id", "bolum_adi"));
        setHeaders({ "ID", "Salon No", "Bölüm", "Salon Adı", "Kapasitesi"});
        break;
    case 5:
        sql.tableModel = sql.sqlQueryEditable("select * from dersler");
        sql.tableModel->setTable("dersler");
        sql.tableModel->setRelation(2, QSqlRelation("bolumler", "bolum_id", "bolum_adi"));
        sql.tableModel->setRelation(6, QSqlRelation("personeller", "p_id", "p_adi_soyadi"));
        setHeaders({ "ID", "Ders kodu", "Bölüm", "Ders Adı", "Dönem", "Süre(dk)", "Öğr. Görv.", "Öğrenci Sayısı"});
        break;
    case 6:
        if(ks == 2){
            ui->tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
        }
        sql.tableModel = sql.sqlQueryEditable("select * from sinavlar");
        sql.tableModel->setTable("sinavlar");
        sql.tableModel->setRelation(1, QSqlRelation("dersler", "ders_id", "ders_adi"));
        sql.tableModel->setRelation(3, QSqlRelation("salonlar", "salon_id", "salon_adi"));
        sql.tableModel->setRelation(6, QSqlRelation("personeller", "p_id", "p_adi_soyadi"));
        setHeaders({ "ID", "Ders", "Süre(dk)", "Salon", "Tarih", "Saat", "Gözetmen"});
        break;
    case 7:
        if(ks == 2){
            ui->tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
        }
        sql.tableModel = sql.sqlQueryEditable("select * from ders_salon");
        sql.tableModel->setTable("ders_salon");
        sql.tableModel->setRelation(2, QSqlRelation("salonlar", "salon_id", "salon_adi"));
        sql.tableModel->setRelation(1, QSqlRelation("dersler", "ders_id", "ders_adi"));
        setHeaders({ "ID", "Ders", "Salon", "Saat", "Gün"});
        break;
    case 8:
        sql.tableModel = sql.sqlQueryEditable("select * from users");
        sql.tableModel->setTable("users");
        sql.tableModel->setRelation(4, QSqlRelation("bolumler", "bolum_id", "bolum_adi"));
        setHeaders({ "Kullanıcı Adı", "Ad Soyad", "Parola", "Yetki Sev.", "Bölüm"});
        break;
    }
    sql.tableModel->select();
    ui->tableView->setModel(sql.tableModel);
    ui->tableView->show();
}

void MainWindow::setHeaders(QStringList headers){
    for(int i=0; i < headers.size(); i++){
        sql.tableModel->setHeaderData(i, Qt::Horizontal, tr(headers.at(i).toLocal8Bit().constData()));
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{//Fakülte sekmesinde kampüs combobox'u değiştiğinde çalışır
    if(ui->tabWidget->currentIndex() == 1){
        sql.tableModel->setFilter("fakulte_kampus=" + ui->comboBox->model()->data(ui->comboBox->model()->index(index,0)).toString());
        ui->tableView->setModel(sql.tableModel);
        ui->tableView->show();
    }
    MainWindow::setCombobox("select fakulte_id, fakulte_adi from fakulteler where fakulte_kampus=" + ui->comboBox->model()->data(ui->comboBox->model()->index(index,0)).toString(), ui->comboBox_3);
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{//Bölüm sekmesinde fakülte combobox'u değiştiğinde çalışır
    if(ui->tabWidget->currentIndex() == 2){
        sql.tableModel->setFilter("bolum_fakulte=" + ui->comboBox_3->model()->data(ui->comboBox_3->model()->index(index,0)).toString());
        ui->tableView->setModel(sql.tableModel);
        ui->tableView->show();
    }
    MainWindow::setCombobox("select bolum_id, bolum_adi from bolumler where bolum_fakulte=" + ui->comboBox_3->model()->data(ui->comboBox_3->model()->index(index,0)).toString(), ui->comboBox_2);
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    switch (ui->tabWidget->currentIndex()) {
    case 3:
        sql.tableModel->setFilter("p_bolum=" + ui->comboBox_2->model()->data(ui->comboBox_2->model()->index(index,0)).toString());
        break;
    case 4:
        sql.tableModel->setFilter("salon_bolum=" + ui->comboBox_2->model()->data(ui->comboBox_2->model()->index(index,0)).toString());
        break;
    case 8:
        sql.tableModel->setFilter("u_bolum=" + ui->comboBox_2->model()->data(ui->comboBox_2->model()->index(index,0)).toString());
        break;
    default:
        sql.tableModel->setFilter("ders_bolum=" + ui->comboBox_2->model()->data(ui->comboBox_2->model()->index(index,0)).toString());
        break;
    }
    ui->tableView->setModel(sql.tableModel);
    ui->tableView->show();
}
