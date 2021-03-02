#ifndef _LOGGER_
#define _LOGGER_

#include <string>
#include <stdio.h>
#include <time.h>
#include <fstream>

const std::string currentDateTime();
bool checkFileExist(const std::string& filename);
void createFileIfNotExists(const std::string& filename);
void writeToLog(const std::string& filename, std::string content);

#endif