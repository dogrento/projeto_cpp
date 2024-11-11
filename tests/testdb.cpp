#include <iostream>
using namespace std;
#include <sqlite3.h> 

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;

   rc = sqlite3_open("tests/test.db", &db);

   if( rc ) {
    //   fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        cout << sqlite3_errmsg(db);
      return(0);
   } else {
    //   fprintf(stderr, "Opened database successfully\n");
        cout << "Opened database successfully." << endl;
   }
   sqlite3_close(db);
}