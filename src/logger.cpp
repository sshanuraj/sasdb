#include "logger.hpp"

string getTime()
{
	string time;
	time_t curtime; 
	time = ctime(&curtime);
	time[time.length() - 1] = '\0';
   	return time; 
}

string createLogString(string res, string log)
{
	string logString = "";
	string time = getTime();
	logString = time + " : [" + res + "] " + log;

	return logString;
}

void logToFile(string res, string log)
{
	ofstream file;
	file.open("../LOGS/db.log", ios_base::app);
	string logString = createLogString(res, log);
	file << logString << endl;
	file.close();
}
