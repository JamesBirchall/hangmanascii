#include "words.h"

void Words::getRandomWord(std::vector<std::string> words){
	srand(time(NULL));
	int randomNumber = rand() % words.size();

	word = words.at(randomNumber);
	
	for(int i = 0; i < word.size(); i++){
		guessedCorrect += '?';
	}
}

bool Words::checkCharacter(std::string character){
	bool foundCharacter = false;
	
	for(int i = 0; i <= word.size(); i++){
		if(character[0] == word[i]){
			guessedCorrect[i] = character[0];
			foundCharacter = true;
		}
	}
	
	return foundCharacter;
}

bool Words::wordsSame(){
	if(word == guessedCorrect){
		return true;
	}
	return false;
}
