#pragma once

#include "Sprite.h"

class GameObject
{
public:
	Vector2Int position{ 0, 0 };
	short zIndex = 0;
	Sprite* sprite = nullptr;

public:
	GameObject() {};
	GameObject(int16_t x, int16_t y) : position(Vector2Int(x, y)) {}
	GameObject(Sprite* sprite, int16_t x, int16_t y) : sprite(sprite), position(Vector2Int(x, y)) {};
	void TransportTo() {
		position = Vector2Int((short)rand() % 250-115, (short)rand() % 200-100);
	}
	void TransportTo(int16_t x, int16_t y) {
		position = Vector2Int(x, y);
	}
};
