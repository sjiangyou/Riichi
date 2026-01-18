#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <array>

class Player{
    std::string name;
    int score;
    std::array<std::string, 13> hand = {};
    std::string drawnTile;

public:
    Player(std::string playerName, int initialScore);
    int getScore();
    std::array<std::string, 13> getHand();
    std::string getDrawnTile();
    void draw(std::string tile);
    void addToHand(std::string tile);
    void arrangeHand();
    std::string discard(int handIndex);
};

#endif 
