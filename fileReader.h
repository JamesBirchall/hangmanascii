#ifndef FILEREADER_H
#define FILEREADER_H

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

class FileReader{
    public:
        std::string getData(const std::string);
        std::vector<std::string> getTokenData(const std::string);
    private:
        std::string wholeData;
        std::vector<std::string> wholeTokenisedData;
};

#endif
