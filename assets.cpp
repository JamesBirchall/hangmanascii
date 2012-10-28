#include "assets.h"

void Assets::loadAssets(){
	FileReader reader0;
	FileReader reader1;
	FileReader reader2;
	FileReader reader3;
	FileReader reader4;
	FileReader reader5;
	FileReader reader6;
	FileReader reader7;
	FileReader reader8;
	FileReader reader9;
	
	hangmanStage0 = reader0.getData(file0);
	hangmanStage1 = reader1.getData(file1);
	hangmanStage2 = reader2.getData(file2);
	hangmanStage3 = reader3.getData(file3);
	hangmanStage4 = reader4.getData(file4);
	hangmanStage5 = reader5.getData(file5);
	hangmanStage6 = reader6.getData(file6);
	hangmanStage7 = reader7.getData(file7);
	hangmanStage8 = reader8.getData(file8);
	
	wordList = reader9.getTokenData(words);
	
	stages.push_back(hangmanStage0);
	stages.push_back(hangmanStage1);
	stages.push_back(hangmanStage2);
	stages.push_back(hangmanStage3);
	stages.push_back(hangmanStage4);
	stages.push_back(hangmanStage5);
	stages.push_back(hangmanStage6);
	stages.push_back(hangmanStage7);
	stages.push_back(hangmanStage8);
	
	currentStage = 0;
}
