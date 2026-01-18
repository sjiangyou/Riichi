#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

#include "Wall.h"

Wall::Wall(){
    wall = WALL_START;
}

std::array<std::string, 136> Wall::getWall(){
    return wall;
}

void Wall::shuffle(){
    std::srand(std::time(nullptr));

    for(int i = 0; i < 136; i++){
        int r = std::rand() % 136;
        std::string temp = wall[i];
        wall[i] = wall[r];
        wall[r] = temp;
    }
}

std::string Wall::drawTile(){
    if(currentTileIndex >= 136){
        return "No more tiles in the wall";
    }
    std::string tile = wall[currentTileIndex];
    currentTileIndex++;
    return tile;
}

bool Wall::isEmpty(){
    return currentTileIndex >= 136 - 14; // Leave 14 tiles for dead wall
}
