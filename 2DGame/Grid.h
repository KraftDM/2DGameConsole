#pragma once
#include <iostream>
#include "Structures.h"

class Grid
{
public:
	uint8_t sizeX;
	uint8_t sizeY;

	Grid(uint8_t x, uint8_t y) : sizeX(x), sizeY(y) {}

	Region GetWorldPosition(uint8_t x, uint8_t y) {
		return Region(x * sizeX, y * sizeY, (x+1) * sizeX, (y+1) * sizeY);
	}
};

