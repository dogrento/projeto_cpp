#include <iostream>
using namespace std;
#include <sqlite3.h> 

// typedef int (*sqlite3_callback)(
//    void*,    /* Data provided in the 4th argument of sqlite3_exec() */
//    int,      /* The number of columns in row */
//    char**,   /* An array of strings representing fields in the row */
//    char**    /* An array of strings representing column names */
// );

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

/* CREATE TABLE FUNC */
void createTable(sqlite3* db){
   string sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

};

bool tabelaExiste(sqlite3* db, const std::string& nomeTabela) {
    std::string sql = "SELECT name FROM sqlite_master WHERE type='table' AND name='" + nomeTabela + "';";
    sqlite3_stmt* stmt;
    bool existe = false;

    // Prepara a consulta
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        // Verifica se há algum resultado
        existe = (sqlite3_step(stmt) == SQLITE_ROW);
        sqlite3_finalize(stmt);  // Libera o statement
    } else {
        std::cerr << "Erro ao verificar tabela: " << sqlite3_errmsg(db) << std::endl;
    }

    return existe;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   string sql;

   rc = sqlite3_open("tests/test.db", &db);

   if( rc ) {
        cout << sqlite3_errmsg(db);
      return(0);
   } else {
        cout << "Opened database successfully." << endl;
   }

      /* Create SQL statement */
   sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

   if(!tabelaExiste(db, "COMPANY")){
      cout << "Criando tabela."<< endl;
      rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

   }else{
      cout << "Inserindo dados na tabela."<< endl;
         /* Create SQL statement */
      sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
            "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
            "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
            "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
            "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";
      cout << "tabela existe."<< endl;

      rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
   }
      /* Create SQL statement */
   sql = "SELECT NAME from COMPANY";
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

   /* Execute SQL statement */
   
   // if( rc != SQLITE_OK ){
   //    fprintf(stderr, "SQL error: %s\n", zErrMsg);
   //    sqlite3_free(zErrMsg);
   // } else {
   //    fprintf(stdout, "Records created successfully\n");
   // }

   sqlite3_close(db);
}