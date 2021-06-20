#include "common_db.hpp"
#include "utility.hpp"

void setTablePair(tablePair &tp, string colName, dtypes dtype)
{
	tp.dtype = dtype;
	tp.colName = colName;
}

qtypes parseInitQuery(string query)
{
	vector<string> split = strSplit(query, ' ');
	if (split[0] == "create")
	{
		return CREATE_TABLE;
	}
	else if (split[0] == "insert")
	{
		return INSERT;
	}
	else if (split[0] == "update")
	{
		return UPDATE;
	}
	else if (split[0] == "search")
	{
		return SEARCH;
	}
	else if (split[0] == "delete")
	{
		return DELETE;
	}
	else
	{
		return ERROR;
	}
}

dtypes getDataType(string dtype)
{
	if(dtype == "int")
		return INT;
	else if(dtype == "string")
		return STRING;
	else if(dtype == "date")
		return DATE;
	else if (dtype == "datetime")
		return DATETIME;
	else if (dtype == "float")
		return DOUBLE;
	else
		return NO_TYPE;
	
}

//create <tablename> col1 type1 col2 type2 .....
vector<tablePair> parseCreateQuery(string query)
{
	vector<tablePair> ret;
	vector<string> split = strSplit(query, ' ');

	if (split.size() == 1)
	{
		tablePair tp;
		setTablePair(tp, "", NO_TYPE);
		ret.push_back(tp);
		return ret;
	}
	tablePair tp;
	setTablePair(tp, split[1], DEFAULT_TYPE);
	ret.push_back(tp);
	for(int i = 2; i < split.size(); i = i+2)
	{
		tablePair tp;
		dtypes dtype = getDataType(split[i+1]);
		if(dtype == NO_TYPE)
		{
			ret[0].dtype = NO_TYPE;
			logToFile("ERR", "Wrong data type during CREATE encountered.");
			return ret;
		}
		setTablePair(tp, split[i], dtype);
		ret.push_back(tp);
	}
	return ret;
}

//insert in <table_name> col1val, col2val, col3val .....
insertCols parseInsertQuery(string query, map<string, Table> tables)
{
	insertCols ret;
	vector<string> split = strSplit(query, ' ');

	if(split.size() == 1)
	{
		logToFile("ERROR", "Syntax error in INSERT query.");
		ret.res = INSERT_FAIL;
		return ret;
	}
	
	if(split[1] != "in")
	{
		logToFile("ERROR", "Syntax error in INSERT query.");
		ret.res = INSERT_FAIL;
		return ret;
	}

	string tableName = split[2];
	if(tables.count(tableName) == 0)
	{
		logToFile("ERROR", "No table named '" + tableName + "' exists in DB.");
		ret.res = INSERT_FAIL;
		return ret;
	}

	Table table = tables[tableName];
	int lenColVals = split.size() - 3;
	if (lenColVals != table.cols.size())
	{
		logToFile("ERROR", "Not enough parameters listed.");
		ret.res = INSERT_FAIL;
		return ret;
	}


	tablePair tp;
	return ret;
}

deleteCols parseDeleteQuery(string query, map<string, Table> tables)
{
	deleteCols ret;
	//to be coded 
	return ret;
}

updateCols parseUpdateQuery(string query, map<string, Table> tables)
{
	updateCols ret;
	//to be coded
	return ret;
}

searchCols parseSearchQuery(string query, map<string, Table> tables)
{
	searchCols ret;
	//to be coded
	return ret;
}


