#pragma once
#include <libpq-fe.h>
#include <string>

class Database {
private:
    PGconn* conn;

public:
    Database(const std::string& connStr);
    ~Database();

    void execute(const std::string& query);
};
