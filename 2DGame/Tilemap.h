#pragma once

#include "Sprite.h"

using namespace std;

struct TileBase {
	Sprite* sprite = nullptr;
};

class Tilemap
{
	int tileCount;
	Vector2Int worldOffset;
	Vector2Int size;
	Vector2Int* positions;
	TileBase* tileArray;
	short zIndex;


public:
	Grid* grid;

public:
	Tilemap(Vector2Int size = {256, 256}, short zIndex = 0) : size(size), zIndex(zIndex) {
		tileCount = size.x * size.y;
		worldOffset = { -size.x/2, -size.y/2 };
		positions = new Vector2Int[tileCount];
		tileArray = new TileBase[tileCount];

		for (int index = 0; index < tileCount; index++)
		{
			positions[index] = Vector2Int(index % size.x, index / size.x);
			tileArray[index] = TileBase();
		}

		grid = new Grid(16, 16); // TO DO 
	}

	// TO DO: Replace with TileBase
	void FillTileBounds(Sprite* sprite) {
		for (int index = 0; index < tileCount; index++)
		{
			tileArray[index].sprite = sprite;
		}
	}
	void SetTileSprite(Sprite* sprite, Vector2Int pos) {
		int index = pos.y * size.x + pos.x;
		if (index >= 0 && index < tileCount)
			tileArray[index].sprite = sprite;
	}

	TileBase* GetTile(int x, int y) {
		if (x - worldOffset.x >= size.x || x - worldOffset.x < 0)
			return nullptr;
		int index = (y - worldOffset.y) * size.x + x - worldOffset.x;
		if(index >= 0 && index < tileCount)
			return &tileArray[index];
		return nullptr;
	}

	Sprite* GetSprite(int x, int y) {
		TileBase* ptr = GetTile(x, y);
		if (ptr != nullptr)
			return ptr->sprite;
		return nullptr;
	}
};

