#ifndef DB_HPP
#define DB_HPP
#include "logger.hpp"
#include "utility.hpp"
#include "common_db.hpp"
using namespace std;

/*
 * db -- > insert, create, delete, search, update for tables, multiple tables,
 * users -- > create, delete, security
 * cols in table -- > uid, name, age, dob  --- > map for int, double, string, dateTime 
 */


class DB
{
	public:
		string dbName;
		string user_name;
		map<string, Table> tables;
		DB(string dbName, string uname); //constructor
		/*insert a row into table */
		bool insertInTable(string query);
		/*delete from table */
		bool deleteFromTable(string query);
		bool createTable(string query);
		bool updateTable(string query);
		bool searchTable(string query);
		string getDbName();
};
#endif
