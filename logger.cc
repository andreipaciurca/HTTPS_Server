#include "logger.h"

// Get current date/time, format is YYYY-MM-DD
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

    return buf;
}

bool checkFileExist(const std::string& filename){
    return !!std::ifstream(filename.c_str());
}

void createFileIfNotExists(const std::string& filename){
   std::ofstream o(filename);
   o.close();
}

void writeToLog(const std::string& filename, std::string content){
    if(!checkFileExist(filename)){
        createFileIfNotExists(filename);
    }else{
        std::ofstream o(filename, std::ofstream::out | std::ofstream::app);
        o<<content<<std::endl;
        o.close();
    }
}