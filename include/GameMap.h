#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "MapCell.h"
#include "Enemy.h"

class GameMap
{
    public:
        GameMap();
        virtual ~GameMap();

        MapCell *PlayerCell;
        MapCell *EnemyCell;

        MapCell cells[15][10];

        void drawIntro();
        void drawVictory();

        bool gameContinue;

        void draw();
        bool setPlayerCell(int px, int py);

        Enemy enemigo;


    protected:
        void loadMapFromFile();
        void moveEnemy();
        void gameOver();

    private:
};

#endif // GAMEMAP_H
