#include<vector>
#include<string>
#include<iostream>
#include <time.h>
#include <stdlib.h>

class Words{
    public:
        void getRandomWord(std::vector<std::string>);
        bool checkCharacter(std::string);
        bool wordsSame();
        std::vector<std::string> gameWordList;
        std::string guessedCorrect;
    private:
		std::string word; 
};
