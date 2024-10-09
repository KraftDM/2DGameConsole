#include "RenderTiles.h"

Texture2D* RenderTiles::Render(Tilemap map, Bounds bounds) {

	int gX = map.grid->sizeX;
	int gY = map.grid->sizeY;
	int col = bounds.max.x - bounds.min.x;
	int lin = bounds.max.y - bounds.min.y;
	Texture2D* canvas = new Texture2D(gX * col, gY * lin);

	for (int y = bounds.min.y, yN = 0; y < bounds.max.y; y++, yN++) {
		for (int x = bounds.min.x, xN = 0; x < bounds.max.x; x++, xN++) {
			Sprite* s = map.GetSprite(x, y);
			if (s != nullptr) {
				canvas->TextureDraw(s->texture, xN * gX, yN * gY);
			}
		}
	}
	return canvas;
}