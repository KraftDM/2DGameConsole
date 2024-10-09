#pragma once

#include "GameObject.h"

#include <iostream>

class Character : public GameObject
{
	
	public:
	int hp;
	int zLevel = 0;

	Character();

	void Move(Vector2Int delta) {
		//bool colizion = Level::GetCellColizion(zLevel, position + delta);
		//if (!colizion)
		position += delta;
	}

	void MoveUp() {
		Move(Vector2Int(0, -1));
	}
	void MoveDown() {
		Move(Vector2Int(0, 1));
	}
	void MoveRight() {
		Move(Vector2Int(1, 0));
	}
	void MoveLeft() {
		Move(Vector2Int(-1, 0));
	}
};

class Player : public Character{
	
public:
	int lvl;

public:
	Player();
};