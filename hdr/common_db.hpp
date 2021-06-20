#ifndef COMMON_DB_HPP
#define COMMON_DB_HPP

#include "common_inc.hpp"
#include "logger.hpp"

#define INSERT_FAIL 0
#define INSERT_SUCCESS 1
#define CREATE_FAIL 0
#define CREATE_SUCCESS 1
#define QUERY_SUCCESS 1
#define QUERY_FAIL 0
#define UPDATE_FAIL 0
#define UPDATE_SUCCESS 1
#define DELETE_FAIL 0
#define DELETE_SUCCESS 1

//query, delimiter

enum qtypes
{
	CREATE_TABLE = 0,
	INSERT,
	SEARCH,
	DELETE,
	UPDATE,
	CREATE_DB,
	CREATE_USER,
	ERROR
};

enum dtypes
{
	INT = 0,
	STRING,
	DOUBLE,
	DATE,  //DD-MM-YYYY
	DATETIME, // HH:MM:SS DD-MM-YYYY
	NO_TYPE,
	DEFAULT_TYPE
};

struct DT_COL
{
	vector<string> dt_col;
};

struct DATE_COL
{
	vector<string> date_col;
};

struct INT_COL
{
	vector<int> int_col;
};

struct DOUB_COL
{
	vector<float> float_col;
};

struct STR_COL
{
	vector<string> str_col;
};

struct tablePair
{
	string colName;
	dtypes dtype;
};

struct insertCols
{
	int res;
	vector<string> qColNames;	
};

struct deleteCols
{
	int res;
	vector <string> dColNames;
};

struct updateCols
{
	int res;
	vector<string> uColNames;
};

struct searchCols
{
	int res;
	vector<string> qColNames;
};


struct InsertGroup
{
	map<string, STR_COL> strCols;
	map<string, DATE_COL> dateCols;
	map<string, INT_COL> intCols;
	map<string, DT_COL> dtCols;
	map<string, DOUB_COL> doubCols;
};

struct Table
{
	string tname;
	map<string, dtypes> cols;
	map<string, string> pKey;
	InsertGroup insGroup;
};

qtypes parseInitQuery(string query);

dtypes getType(string query);

void setTablePair(tablePair &tp, string colName, dtypes dtype);

vector<tablePair> parseCreateQuery(string query);

insertCols parseInsertQuery(string query, map<string, Table> tables);

deleteCols parseDeleteQuery(string query, map<string, Table> tables);

updateCols parseUpdateQuery(string query, map<string, Table> tables);

searchCols parseSearchQuery(string query, map<string, Table> tables);


#endif
