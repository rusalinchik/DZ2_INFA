#include "Database.h"
#include "ETLProcessor.h"

int main() {
    Database db("host=localhost dbname=dwh user=postgres password=1234");
    ETLProcessor::loadSales(db);
    return 0;
}
