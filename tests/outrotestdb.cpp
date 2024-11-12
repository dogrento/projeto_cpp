#include <iostream>
using namespace std;

#include "../helpers/dbhandler.h"

int main(){
    string path = "test.db";
   /* Create SQL statement */
    string sql = "CREATE TABLE UNIVERSIDADE("  \
        "ID INT PRIMARY KEY     NOT NULL," \
        "NAME           TEXT    NOT NULL );";

    cout << "criando dbhandler." << endl;
    DBHandler db(path);

    cout << "criando tabela." << endl;
    db.criarTabela(sql);

    if(db.tabelaExiste("DISC")){
        cout << "Tabela existe." << endl;
    }else{
        cout << "Tabela n existe." << endl;
    }

    cout << "inserindo na tabela" << endl;
    db.inserirDados("UNIVERSIDADE", "ID,NAME", "2, 'Outra universidade federal'");

    cout << "recuperando na tabela" << endl;
    db.recuperarDados("*", "UNIVERSIDADE");


    return 0;
}