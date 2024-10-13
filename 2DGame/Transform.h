#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Structures.h"
#include <vector>

class GameObject;

class Transform
{
	Transform* parent = nullptr;
	std::vector<Transform*> transform;

public:
	GameObject* gameobject;
	Vector2Int position = {0, 0};
	Vector2Int localposition = WorldToLocalPos();

	Transform() : transform () { }
	Transform(int16_t x, int16_t y) : position(x, y) {};
	Vector2Int WorldToLocalPos() {
		if(parent != nullptr)
			return parent->position - position;
		return position;
	}
	void SetParent(Transform& p, bool worldPositionStays = true) {
		parent = &p;
		p.transform.push_back(this);
	}
	Transform* GetChild(int index) {
		if(index < transform.size())
			return transform[index];
	}
	void Tanslate(Transform translation) {
		position += translation.position;
		for (Transform* child : transform)
		{
			child->Tanslate(translation);
		}
	}
};

#endif