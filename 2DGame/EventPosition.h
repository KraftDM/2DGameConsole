#pragma once
#include "Structures.h"

#define FAR 0
#define CLOSE 1
#define ATPOSITION 3

template <typename T>
class EventPosition : public IEvent {
private:
	Vector2Int* pos1;
	Vector2Int* pos2;
	uint16_t dist;
	const int type;
	T* obj;
	using mFuncPointer = void (T::*)();
	mFuncPointer fCall; //= &Object::f

public:
	EventPosition(Vector2Int* first, Vector2Int* second, int type, T* object, void (T::* func)(), uint16_t distant) : pos1(first), pos2(second), type(type) {
		obj = object;
		fCall = func;
		dist = distant;
	}

	bool Check() override {
		if (type == ATPOSITION)
			return pos1 == pos2;
		if (type == CLOSE)
			return pos1->Dist(*pos2) < dist;
		if (type == FAR)
			return pos1->Dist(*pos2) > dist;
	}

	void Activate() {
		(obj->*fCall)();
	}
	~EventPosition() { }
};