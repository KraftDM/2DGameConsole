#pragma once

#include "Tilemap.h"

class RenderTiles
{
public:
	static Texture2D* Render(Tilemap map, Bounds bounds);
};

