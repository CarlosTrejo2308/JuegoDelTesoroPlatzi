#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
    x = 1;
    y = 1;
}

Player::~Player()
{
    //dtor
}

void Player::CallInput() {
    char userInput = ' ';

    cin >> userInput;
    lx = x;
    ly = y;

    switch(userInput) {
        case 'w':
            x--;
            break;
        case 's':
            x++;
            break;
        case 'a':
            y--;
            break;
        case 'd':
            y++;
            break;

    }
}

void Player::resetToSafePosition() {
    x = lx;
    y = ly;
}
