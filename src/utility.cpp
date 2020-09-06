#include "utility.hpp"

vector<string> strSplit(string query, char dl)
{
	vector<string> ret;
	string app = "";
	for(int i = 0; i < query.length(); i++)
	{
		if(query[i] == dl)
		{
			if (app != "" && app != " ")
				ret.push_back(app);
			app = "";
		}
		if(i == query.length() - 1)
		{
			app = app + query[i];
			if(app != "" && app != " ")
				ret.push_back(app);
		}
		app = app + query[i];
	}
	return ret;
}

string getFirstWord(string query)
{
	string ret = "";
	for(int i = 0; i < query.length(); i++)
	{
		if(query[i] == ' ')
		{
			break;
		}
		ret = ret + query[i];
	}
	return ret;
}
