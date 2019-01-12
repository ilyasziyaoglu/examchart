#include "sql.h"

void Sql::connect(){
    db.setHostName("127.0.0.1");
    db.setDatabaseName("sinavProgrami");
    db.setUserName("akcan");
    db.setPassword("akcan123");
    if(db.open()){
        qDebug("Connected!");
    }
    else{
        qDebug("Connection Failed!");
    }
}

QSqlQueryModel* Sql::sqlQuery(QString sqlStatement){
    QSqlQueryModel* queryModel = new QSqlQueryModel();
    QSqlQuery query(db);
    if(!query.exec(sqlStatement))
    {
        qDebug(query.lastError().text().toLatin1());
    }
    else
    {
        queryModel->setQuery(query);
        return queryModel;
    }
    return queryModel;
}

QSqlRelationalTableModel* Sql::sqlQueryEditable(QString sqlStatement){
    QSqlQuery query(db);
    if(!query.exec(sqlStatement))
    {
        qDebug(query.lastError().text().toLatin1());
    }
    else
    {
        return tableModel;
    }
    return tableModel;
}
