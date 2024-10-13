#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Sprite.h"
#include "Transform.h"

class GameObject
{
public:
	Transform transform;
	short zIndex = 0; // переделать на ссылку на слой (tilemap*)
	Sprite* sprite = nullptr;

public:
	GameObject() {
		transform = {};
		transform.gameobject = this;
	}
	GameObject(int16_t x, int16_t y) : transform(x, y) {}
	GameObject(Sprite* sprite, int16_t x, int16_t y) : sprite(sprite), transform(x, y) {};
	void TransportTo() {
		transform.position = Vector2Int((short)rand() % 250-115, (short)rand() % 200-100);
	}
	void TransportTo(int16_t x, int16_t y) {
		transform.position = Vector2Int(x, y);
	}
	void SetParent() {
		
	}
};

#endif
