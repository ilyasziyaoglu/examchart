#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    w.sql.connect();
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString uname = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
    QSqlQueryModel* model = w.sql.sqlQuery("select * from users where u_name='" + uname + "' and u_pass='" + pass + "'");
    if(model->rowCount() == 0){
        QMessageBox::warning(this, "Giriş Mesajı", "Kullanıcı adı veya parola yanlış!");
    }
    else{
        w.ks = model->record(0).value(3).toInt();
        w.start();
        w.show();
        this->hide();
    }
}
