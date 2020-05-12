#include "GameMap.h"
#include <iostream>
#include <fstream>

using namespace std;

GameMap::GameMap()
{
    PlayerCell = NULL;
    EnemyCell = NULL;
    loadMapFromFile();
    gameContinue = true;
}

GameMap::~GameMap()
{
    //dtor
}
void GameMap::draw() {
    for( int i = 0; i < 15; i++ ) {
        for( int j = 0; j < 10; j++ ) {
            cout << cells[i][j].id;
        }
        cout << endl;
    }
}

void GameMap::moveEnemy() {
    enemigo.mover();

    if( EnemyCell != NULL ) {
        EnemyCell->id = ' ';
    }

    EnemyCell = &cells[enemigo.x][enemigo.y];
    EnemyCell->id = 'E';

    if ( PlayerCell == EnemyCell ) {
        gameContinue = false;
        gameOver();
    }

}

void GameMap::gameOver() {
    string line;
    ifstream myFile("gameover.txt");
    int row = 0;

    if ( myFile.is_open() ) {
        while ( getline( myFile, line ) ) {
            cout << line << endl;
        }
    }

    else {
        cout << "ERROR: Gameover couldn't be loaded" << endl;
    }
}

bool GameMap::setPlayerCell( int px, int py ) {
    moveEnemy();

    if ( cells[px][py].id == 'E' ) {
        gameContinue = false;
        gameOver();
        return true;
    }

    if ( cells[px][py].isBlocked() ) {
        return false;
    }

    if( PlayerCell != NULL ) {
        PlayerCell->id = ' ';
    }

    if ( cells[px][py].id  == '$' ) {
        gameContinue = false;
        drawVictory();
        return true;
    }

    PlayerCell = &cells[px][py];
    PlayerCell->id = 'H';
    return true;

}

void GameMap::drawVictory() {
    string line;
    ifstream myFile("vicotry.txt");
    int row = 0;

    if ( myFile.is_open() ) {
        while ( getline( myFile, line ) ) {
            cout << line << endl;
        }
    }

    else {
        cout << "ERROR: Victory couldn't be loaded" << endl;
    }
}
void GameMap::drawIntro() {
    string line;
    ifstream myFile("intro.txt");
    int row = 0;

    if ( myFile.is_open() ) {
        while ( getline( myFile, line ) ) {
            cout << line << endl;
        }

        cin >> line;
    }

    else {
        cout << "ERROR: Intro couldn't be loaded" << endl;
    }
}

void GameMap::loadMapFromFile() {
    string line;
    ifstream myFile("map.txt");
    int row = 0;

    if ( myFile.is_open() ) {
        while ( getline( myFile, line ) ) {
            for ( int p = 0; p < line.length(); p++ ) {
                if ( line[p] == '0' ) {
                    cells[row][p].id = ' ';
                }
                else {
                    cells[row][p].id = line[p];
                }

            }
            row++;
        }
    }

    else {
        cout << "ERROR: Map file couldn't be loaded" << endl;
    }
}
