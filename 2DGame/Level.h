#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <map>

using namespace std;

/*
struct Cell {
    bool collizion;
    bool visible;
    vector<Sprite*> sprites = {};
    Cell();

    void AddSprite(Sprite* sprite) {
        sprites.push_back(sprite);
    }
};

class Level{
    private:

    public:
    int zCount;

    public:
    static map<short, map<short, map<short, Cell*>>> cells;

    public:
    Level() : zCount(1) {};
    void LoadLevel();
    bool AddCell(int z, int y, int x, Cell* cell); // MAKE PRIVATE LATER
    static bool GetCellColizion(int z, Vector2Short xy);
    ~Level() {
        //delete[] &cells;
    }
};
*/
#endif