// Hangman.cpp

#include <string>
#include <vector>

#include "player.h"
#include "fileReader.h"
#include "assets.h"
#include "words.h"

int main(){

	Player player1;
	bool gameOver = false;
	int guesses = 0;
    
	player1.printString("Welcome to ASCII hangman!\n");
	player1.printString("This version brought to you by James Birchall\n");
	player1.printString("Smee Studios 2012\n");
    
	Assets assets;	
	assets.loadAssets();	//loads the stages and words

	// activate words class to choose random word & setup ready for display
	Words words;
	words.getRandomWord(assets.wordList);

	//enter game class - which handles game loop (draw, input, update cycle)

	while(!gameOver){
		player1.printString(assets.stages.at(assets.currentStage));
		
		std::cout << words.guessedCorrect << std::endl;
		
		player1.printString("Please enter a character");
		
		std::string guess = player1.getCharacter();
		
		bool guessCorrect = words.checkCharacter(guess);
		
	
		if(!guessCorrect){
			player1.printString("\n\nToo bad, closer to the noose you go...");
			assets.currentStage++;
			guesses++;
			if(8 == guesses){
				gameOver = true;
				std::cout << assets.hangmanStage8 << std::endl;
				std::cout << "Game Over, better luck next time!" << std::endl;
			}
		}

		if(guessCorrect && words.wordsSame()){
			gameOver = true;
			std::cout << "Congratulations you win!" << std::endl;
		}		
		

	}


    
    /**std::vector<std::string>::iterator it;
    it = assets.wordList.begin();
    while(it != assets.wordList.end()){
		std::cout << it[0] << std::endl;
		it++;
	}**/
    
    return 0;
}

