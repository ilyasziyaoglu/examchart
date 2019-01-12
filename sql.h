#ifndef SQL_H
#define SQL_H
#include <QtSql>


class Sql
{
public:
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QSqlQueryModel* queryModel = new QSqlQueryModel();
    QSqlRelationalTableModel* tableModel = new QSqlRelationalTableModel();

    int ks; //kullanici seviyesi.

    void connect();
    QSqlQueryModel* sqlQuery(QString sqlStatement);
    QSqlRelationalTableModel* sqlQueryEditable(QString sqlStatement);
};

#endif // SQL_H
