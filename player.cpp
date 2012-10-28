#include "player.h"

std::string Player::getCharacter(){
    std::string temp;
    std::cin >> temp;
    return temp;
}

void Player::printString(std::string output){
    std::cout << output << std::endl;
}
