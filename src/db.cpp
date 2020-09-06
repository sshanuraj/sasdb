#include "db.hpp"

using namespace std;

DB::DB(string name, string uname)
{
	dbName = name;
	user_name = uname; 
	string log = "DB " + dbName + " Initialized, Parameters Set by User: " + uname;
	logToFile("LOG", log);
}

bool DB::createTable(string query)
{
	//tname, query : "create table tb : uid int PK, name string, dob date"
	//parse query
	vector<tablePair> cRet = parseCreateQuery(query);
	
	if(cRet[0].dtype == NO_TYPE)
	{
		logToFile("ERROR", "Syntax error in query.");
		return false;
	}

	Table table;
	table.tname = cRet[0].colName;
	
	if (tables.count(table.tname) == 0)
	{
		string log = "Table '" + table.tname + "' already exists in the database.";
		logToFile("ERROR", log);
		return false;
	}
	
	INT_COL intCols[20];
	STR_COL strCols[20];
	DOUB_COL doubCols[20];
	DATE_COL dateCols[20];
	DT_COL dtCols[20];
	int ic = 0, sc = 0, dc = 0, dtc = 0, dac = 0;

	for (int i = 1; i < cRet.size(); i++)
	{
		switch(cRet[i].dtype)
		{
			case INT:
				table.insGroup.intCols[cRet[i].colName] = intCols[ic++];
				break;
			case STRING:
				table.insGroup.strCols[cRet[i].colName] = strCols[sc++];
				break;
			case DOUBLE:
				table.insGroup.doubCols[cRet[i].colName] = doubCols[dc++];
				break;
			case DATE:
				table.insGroup.dateCols[cRet[i].colName] = dateCols[dac++];
				break;
			case DATETIME:
				table.insGroup.dtCols[cRet[i].colName] = dtCols[dtc++];
				break;
		}	
		table.cols[cRet[i].colName] = cRet[i].dtype;
	}
	tables[table.tname] = table;
	logToFile("LOG", "Table has been created.");
	return true;
}

bool DB::insertInTable(string query)
{	
	insertCols iRet = parseInsertQuery(query, tables);

	if(iRet.res == INSERT_FAIL)
	{
		logToFile("ERROR", "Insert fail occured due to syntax error.");
		return false;
	}

	
	return true;
}

bool DB::deleteFromTable(string query)
{
	deleteCols dRet = parseDeleteQuery(query, tables);
	
	if(dRet.res == DELETE_FAIL)
	{
		logToFile("ERROR", "Delete fail occured due to syntax error.");
		return false;
	}
	return true;
}

bool DB::updateTable(string query)
{
	updateCols uRet = parseUpdateQuery(query, tables);
	
	if(uRet.res == UPDATE_FAIL)
	{
		logToFile("ERROR", "Update fail occured due to syntax error.");
		return false;
	}

	return true;
}

bool DB::searchTable(string query)
{
	searchCols sRet = parseSearchQuery(query, tables);

	if(sRet.res == QUERY_FAIL)
	{
		logToFile("ERROR", "Query fail due to syntax error.");
		return false;
	}
	return true;
}

string DB::getDbName()
{
	return dbName;
}

