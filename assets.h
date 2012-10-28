#ifndef ASSETS_H
#define ASSETS_H

#include <string>
#include <vector>
#include "fileReader.h"

class Assets{
	public:
		const std::string file0 = "assets/stage0";
		const std::string file1 = "assets/stage1";
		const std::string file2 = "assets/stage2";
		const std::string file3 = "assets/stage3";
		const std::string file4 = "assets/stage4";
		const std::string file5 = "assets/stage5";
		const std::string file6 = "assets/stage6";
		const std::string file7 = "assets/stage7";
		const std::string file8 = "assets/stage8";
		const std::string words = "assets/words";
		
		std::string hangmanStage0;
		std::string hangmanStage1;
		std::string hangmanStage2;
		std::string hangmanStage3;
		std::string hangmanStage4;
		std::string hangmanStage5;
		std::string hangmanStage6;
		std::string hangmanStage7;
		std::string hangmanStage8;
		std::vector<std::string> wordList;
		std::vector<std::string> stages;
		int currentStage;
		
		void loadAssets();
};

#endif
