#pragma once
#ifndef STRUCTURE_H
#define STRUCTURE_H

struct Vector2Short
{
public:
	short x;
	short y;
	Vector2Short(){}
	Vector2Short(short x, short y) : x(x), y(y) { }
	int Len() {
		return(int)x * y;
	}
};
struct Vector2Int
{

public:
	int16_t x = 0;
	int16_t y = 0;

	Vector2Int() {}
	Vector2Int(int16_t x, int16_t y) : x(x), y(y) { }

	void Trandform(int16_t dx, int16_t dy) {
		x += dx;
		y += dy;
	}
	int16_t Len() {
		return x * y;
	}
	int16_t Dist(Vector2Int point) {
		return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
	}

	bool operator !=(Vector2Int right) {
		return x != right.x && y != right.y;
	}
	bool operator ==(Vector2Int right) {
		return x == right.x && y == right.y;
	}
	void operator +=(Vector2Int right) {
		x += right.x;
		y += right.y;
	}
	void operator -=(Vector2Int right) {
		x -= right.x;
		y -= right.y;
	}
	Vector2Int operator -(Vector2Int right) {
		return Vector2Int(x - right.x, y - right.y);
	}
};

struct Bounds
{
public:
	Vector2Int min;
	Vector2Int max;

	Bounds(Vector2Int min = {0 ,0}, Vector2Int max = {0,0}) : min(min), max(max) {}
};


struct Region
{
public:
	Vector2Short first;
	Vector2Short second;

	Region(short x1, short y1, short x2, short y2) {
		first = Vector2Short(x1, y1);
		second = Vector2Short(x2, y2);
	}
};

#endif // !STRUCTURE_H
