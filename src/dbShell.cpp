#include "dbShell.hpp"

dbShell::dbShell()
{
	dbCurrent = "";
}

void dbShell::setDbCurrent(string dbName)
{
	dbCurrent = dbName;
	string log = "DB set to [" + dbName + "]";
	logToFile("LOG", log);
}

void dbShell::startShell()
{
	string query;
	DB dbnew("newDB", "shubham");
	//current purposes
	dbCurrent = "newDB";
	//
	cout << "-------------Welcome to SasDB------------" << endl;

	while(1)
	{
		cout << ">>> ";
		getline(cin, query);

		if (query == "exit")
		{
			break;
		}
		if(dbCurrent == "")
		{
			cout << "Not in any databse to run any command. Go into an existing database through 'enter <DB_NAME>'. Existing DBs : " << dbnew.getDbName() << "." << endl; 
		}
		else
		{
			if (query == "exit DB")
			{
				cout << "Exitting " + dbCurrent << endl;
				dbCurrent = "";
			}
			else if (query == "")
			{
				continue;
			}
			else
			{
				qtypes q = parseInitQuery(query);
				switch(q)
				{
					case CREATE_TABLE:
						if (dbnew.createTable(query))
						{
							cout << "Table created." << endl;
						}
						else
						{
							cout << "Error in CREATE syntax." << endl;
						}
						break;
					case INSERT:
						if (dbnew.insertInTable(query))
						{
							cout << "Values inserted in table." << endl;
						}
						else
						{
							cout << "Error in INSERT syntax." << endl;
						}
						break;
					case SEARCH:
						if (dbnew.searchTable(query))
						{
							cout << "Search Complete." << endl;
						}
						else
						{
							cout << "Error in SEARCH syntax." << endl;
						}
						break;
					case DELETE:
						if (dbnew.deleteFromTable(query))
						{
							cout << "Deleted in table." << endl;
						}
						else
						{
							cout << "Error in DELETE syntax." << endl;
						}
						break;
					case UPDATE:
						if (dbnew.updateTable(query))
						{
							cout << "Updated Table" << endl;
						}
						else
						{
							cout << "Error in UPDATE syntax." << endl;
						}
						break;
					default:
						cout << "Unrecognized query." << endl;
						break;
				}

			}
		
		}
	}
	return;
}

int main()
{
	dbShell dbs;
	dbs.startShell();
	return 0;
}
