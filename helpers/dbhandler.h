#pragma once

#include <cstring>
#include <sqlite3.h>
#include <string>
#include <iostream>
using namespace std;

class DBHandler{
private:
    sqlite3  *db;
    char     *zErrMsg;
    int       rc;
    char     *sql;

    string    DB_path;
    string    DB_file_name;

    int      abrirDB();
    bool     fecharDB();
    string   getAbsolutePath()const{return DB_path + DB_file_name;};
    bool     tabelaExiste(const string tabelaNome);
    bool     criarTabela(const string tabela);

//    rc = sqlite3_open("tests/test.db", &db);
public:
    DBHandler(const string p = ".data/", const string n = "sa.db"):
    db(nullptr),
    zErrMsg(nullptr),
    rc(-1),
    DB_path(p),
    DB_file_name(n){
        rc = abrirDB();
        if( rc ) {
            cout << sqlite3_errmsg(db);
        } else {
            cout << "Opened database successfully." << endl;
        }
    };
    ~DBHandler(){fecharDB();};

    bool inserirDados(const string tableName, 
                      const string properties, 
                      const string values);

    bool recuperarDados(const string item, const string tabelaNome);
};  
