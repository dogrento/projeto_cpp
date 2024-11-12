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

   string    DBpath;

//    rc = sqlite3_open("tests/test.db", &db);
public:
    DBHandler(const string p);
    DBHandler();
    ~DBHandler(){fecharDB();};

    void     setPath(const string p);
    string   getPath()const              {return DBpath;};

    int      abrirDB();
    bool     fecharDB();
    bool     tabelaExiste(string tabelaNome);
    bool     criarTabela(const string tabela);
    bool     inserirDados(const string tableName, 
                          const string properties, 
                          const string values);

    bool     recuperarDados(const string item, const string tabelaNome);

};