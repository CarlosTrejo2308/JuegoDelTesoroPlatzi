#include "MapCell.h"

MapCell::MapCell()
{
    id = ' ';
}

MapCell::~MapCell()
{
    //dtor
}

bool MapCell::isBlocked() {
    if( id == '1' ) {
        return true;
    }
    else {
        return false;
    }
}
