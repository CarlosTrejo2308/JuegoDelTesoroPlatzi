#include <iostream>
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"

using namespace std;

int main()
{
    GameMap Map;
    Player hero;

    Map.drawIntro();

    while ( Map.gameContinue ) {
        Map.draw();
        hero.CallInput();

        if ( !Map.setPlayerCell(hero.x, hero.y) ) {
            hero.resetToSafePosition();
        }
    }

    return 0;
}
