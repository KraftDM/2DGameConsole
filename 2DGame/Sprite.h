#pragma once

#include "SpriteAtlas.h"

//#include <iostream>

class Sprite
{
public:
	const uint16_t id;
	const char* name;
	const bool transparent;
	Texture2D* texture;
	short place;

	Sprite(uint16_t id, SpriteAtlas* atlasPtr) : id(id), transparent(false), place(id) {
		Grid g = atlasPtr->grid;
		texture = new Texture2D(g.sizeX, g.sizeY);

		short col = place % (atlasPtr->texture->width / g.sizeX);
		short lin = place / (atlasPtr->texture->width / g.sizeX);
		texture->TextureDraw(atlasPtr->texture, -col * g.sizeX, -lin * g.sizeY);
	}
};

