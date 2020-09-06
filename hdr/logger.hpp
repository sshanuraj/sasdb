#ifndef LOGGER_HPP
#define LOGGER_HPP
#include "common_inc.hpp"
#include <fstream>

/*res -- > ERROR, LOG
 */ 
extern string getTime();

extern string createLogString(string res, string log);

extern void logToFile(string res, string log);

#endif
