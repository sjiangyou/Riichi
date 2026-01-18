#include <string>
#include <array>

#include "Player.h"

Player::Player(std::string playerName, int initialScore){
    name = playerName;
    score = initialScore;
}

int Player::getScore(){
    return score;
}

std::array<std::string, 13> Player::getHand(){
    return hand;
}

std::string Player::getDrawnTile(){
    return drawnTile;
}

void Player::draw(std::string tile){
    drawnTile = tile;
}

void Player::addToHand(std::string tile){
    for(int i = 0; i < 13; i++){
        if(hand[i] == ""){
            hand[i] = tile;
            break;
        }
    }
}

void Player::arrangeHand(){
    std::string suitOrder = "mpsz";
    std::array<std::string, 13> arrangedHand = {};
    int index = 0;
    for(char suit : suitOrder){
        for(int num = 1; num <= 9; num++){
            if(suit == 'z' && num > 7){
                break;
            }
            std::string tile = std::to_string(num) + suit;
            for(int i = 0; i < 13; i++){
                if(hand[i] == tile){
                    arrangedHand[index] = tile;
                    index++;
                }
            }
        }
    }
    hand = arrangedHand;
}

std::string Player::discard(int handIndex){
    std::string discardedTile;
    // Tsumogiri
    if(handIndex == 13){
        discardedTile = drawnTile;
        drawnTile = "";
        return discardedTile;
    }
    // Tedashi
    discardedTile = hand[handIndex];
    hand[handIndex] = "";
    addToHand(drawnTile);
    arrangeHand();
    drawnTile = "";
    return discardedTile;
}
