#include "fileReader.h"

std::string FileReader::getData(const std::string fileName){

    std::ifstream in(fileName.c_str()); //new standard lets string standard be used

    std::string temp;

    while(getline(in, temp)){
        wholeData += temp;
        wholeData += '\n';
    }

    in.close();

    return wholeData;
}

std::vector<std::string> FileReader::getTokenData(const std::string fileName){

    std::ifstream in(fileName.c_str()); //new standard lets string standard be used

    std::string temp;

    while(in >> temp){
        wholeTokenisedData.push_back(temp);
    }

    in.close();

    return wholeTokenisedData;
}


