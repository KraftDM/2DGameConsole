#include "Resources.h"

/*
map<short, map<short, map<short, Cell*>>> Level::cells = {};

Cell::Cell() : collizion(false), visible(true)
{
    
}

bool Level::AddCell(int z, int y, int x, Cell* cell){
    if(z >=0 && z < zCount)
        cells[z][y][x] = cell;
    else {
        // do WARNING
    }
    return 0;
}

bool Level::GetCellColizion(int z, Vector2Short xy)
{
    if (cells[z].find(xy.Y) != cells[z].end()) {
        if(cells[z][xy.Y].find(xy.X) != cells[z][xy.Y].end())
            return cells[z][xy.Y][xy.X]->collizion;
    }
    return true;
}
*/