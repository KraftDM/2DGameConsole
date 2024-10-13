#pragma once

#include "GameObject.h"
#include <iostream>

class Character : public GameObject
{
public:
	int hp;

	Character();

	void Move(Transform delta) {
		transform.Tanslate(delta);
	}

	void MoveUp() {
		Move(Transform(0, -1));
	}
	void MoveDown() {
		Move(Transform(0, 1));
	}
	void MoveRight() {
		Move(Transform(1, 0));
	}
	void MoveLeft() {
		Move(Transform(-1, 0));
	}
};

class Player : public Character{
	
public:
	int lvl;

public:
	Player();
};