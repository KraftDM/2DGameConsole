#pragma once
#include "Texture2D.h"
#include "Grid.h"

class SpriteAtlas
{
public:
	const uint16_t id;
	Texture2D* texture;
	Grid grid;

	SpriteAtlas (int id, Texture2D* texture, Grid grid) : id(id), texture(texture), grid(grid) {}
};

