#ifndef DBSHELL_HPP
#define DBSHELL
#include "db.hpp"

class dbShell
{
	public:
		string dbCurrent;
		dbShell();	
		void setDbCurrent(string dbName);
		void startShell();
};

#endif 
