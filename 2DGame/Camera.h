#pragma once

#include "GameObject.h"
#include "RenderTiles.h"

class Camera
{
public:
	Vector2Int position{0, 0};
	int32_t height = 100;
	int32_t width = 100;

	int32_t colMax = 0;
	int32_t tileColOffset = 0;
	int32_t lineMax = 0;
	int32_t tileLineOffset = 0;

private:
	Texture2D* view = new Texture2D(width, height);

	Grid* grid;

public:
	Camera(uint32_t width, uint32_t height) : width(width), height(height) {
		grid = new Grid(16, 16);
		colMax  = width  / grid->sizeX;
		tileColOffset = colMax / 2;
		lineMax = height / grid->sizeY;
		tileLineOffset = lineMax / 2;
	};

	Bounds GetViewGridPosBounds(Grid* grid, Vector2Int offset = {0 ,0 }) {
		Bounds res = Bounds();
		res.min.x = position.x / grid->sizeX - tileColOffset;
		res.min.y = position.y / grid->sizeY - tileLineOffset;

		res.max.x = position.x / grid->sizeX + tileColOffset;
		res.max.y = position.y / grid->sizeY + tileLineOffset;

		return res;
	}

	void RenderTileMap(Tilemap &map) {
		Bounds b = GetViewGridPosBounds(map.grid);
		Texture2D* render = RenderTiles::Render(map, b);
		view->TextureDraw(render, - position.x % map.grid->sizeX, -position.y % map.grid->sizeX);
		delete(render);
	}

	Vector2Int GetWorldPosition(Vector2Int cell) {

	}

	Texture2D* GetRender() {
		return view;
	}

	void DrawObjAtPos(GameObject obj) {
		if (obj.sprite == nullptr)
			return;
		view->TextureDraw(obj.sprite->texture, width/2 + obj.position.x - position.x, height/2 + obj.position.y - position.y);
	}
	void Clear() {
		view->Clear(15);
	}

	~Camera() {};

};

