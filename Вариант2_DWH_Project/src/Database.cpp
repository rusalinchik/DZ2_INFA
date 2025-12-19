#include "Database.h"
#include <iostream>

Database::Database(const std::string& connStr) {
    conn = PQconnectdb(connStr.c_str());
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << PQerrorMessage(conn);
        PQfinish(conn);
        exit(1);
    }
}

Database::~Database() {
    PQfinish(conn);
}

void Database::execute(const std::string& query) {
    PGresult* res = PQexec(conn, query.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << PQerrorMessage(conn);
    }
    PQclear(res);
}
