#pragma once

#include "Sprite.h"

using namespace std;

struct TileBase {
	Sprite* sprite = nullptr;
};

class Tilemap
{
	int tileCount;
	Vector2Int worldOffset {-10, -8};
	Vector2Int* positions;
	TileBase* tileArray;
	short zIndex;

public:
	Grid* grid;

public:
	Tilemap(Vector2Int size = {20, 16}, short zIndex = 0) : zIndex(zIndex) {
		tileCount = size.x * size.y;
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
		int i = 0;
		while (i < tileCount) {
			if (positions[i] == pos) {
				tileArray[i].sprite = sprite;
				return;
			}
			i++;
		}
	}

	TileBase* GetTile(int x, int y) {
		int i = 0;
		while (i < tileCount) {
			if(positions[i++] == Vector2Int(x - worldOffset.x, y - worldOffset.y))
				return &tileArray[i - 1];
		}
		return nullptr;
	}

	Sprite* GetSprite(int x, int y) {
		TileBase* ptr = GetTile(x, y);
		if (ptr != nullptr)
			return ptr->sprite;
		return nullptr;
	}
};

