#include "Enemy.h"

Enemy::Enemy()
{
    x = 8;
    y = 3;
    nivel = 0;
    track = 0;

}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::mover() {
    switch (track) {
    case 0:
        y = 3;
        break;
    case 1:
        y = 4;
        break;
    case 2:
        y = 5;
        break;
    case 3:
        y = 4;
        track = -1;
        break;
    default:
        y = 3;
        track = -1;
        break;
    }
    track++;
}
