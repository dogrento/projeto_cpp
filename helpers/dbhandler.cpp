#include "dbhandler.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

DBHandler::DBHandler(const string p):
db(nullptr),
zErrMsg(nullptr),
rc(-1)
{
    setPath(p);
    rc = abrirDB();
    if( rc ) {
        cout << sqlite3_errmsg(db);
    } else {
        cout << "Opened database successfully." << endl;
   }
}

DBHandler::DBHandler():
db(nullptr),
zErrMsg(nullptr),
rc(-1),
sql(nullptr),
DBpath("")
{}

void DBHandler::setPath(const string p){
    DBpath = p;
}

int DBHandler::abrirDB(){
    return sqlite3_open(DBpath.c_str(), &db);
}

bool DBHandler::fecharDB(){
    cout << "Fechando DB." << endl;
    return sqlite3_close(db);
}

bool DBHandler::tabelaExiste(string tabelaNome){
    std::string query = "SELECT name FROM sqlite_master WHERE type='table' AND name='" + tabelaNome + "';";
    sqlite3_stmt* stmt;
    bool existe = false;

    // Prepara a consulta
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        // Verifica se há algum resultado
        existe = (sqlite3_step(stmt) == SQLITE_ROW);
        sqlite3_finalize(stmt);  // Libera o statement
    } else {
        std::cerr << "Erro ao verificar tabela: " << sqlite3_errmsg(db) << std::endl;
    }

    return existe;
    // return false;
}

bool DBHandler::criarTabela(const string tabela){
    rc = sqlite3_exec(db, tabela.c_str(), callback, 0, &zErrMsg); 
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return false;
    } else {
      fprintf(stdout, "Table created successfully\n");
      return true;
    }
}

bool DBHandler::inserirDados(
    const string tableName, 
    const string properties, 
    const string values)
{
    string insertStr = "INSERT INTO " + tableName + '(' + properties + ')' + '\n'
                        + "VALUES " + "(" + values + ");";
    /* Execute SQL statement */
    rc = sqlite3_exec(db, insertStr.c_str(), callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return false;
    } else {
      fprintf(stdout, "Records created successfully\n");
      return true;
    }
}

bool DBHandler::recuperarDados(const string item, const string tabelaNome){
    const char* data = "Callback function called";
    string recStr = "SELECT " + item + "from " + tabelaNome;

    /* Execute SQL statement */
    rc = sqlite3_exec(db, recStr.c_str(), callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return false;
    } else {
      fprintf(stdout, "Records created successfully\n");
      return true;
    }
}