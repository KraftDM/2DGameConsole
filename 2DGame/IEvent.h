#pragma once

#define PRESED 0
#define CLICK 1

#include "Inputs.h"

class IEvent
{
  public:
	IEvent() {};
	virtual bool Check() = 0;
	virtual void Activate() = 0;
	void Listen() {
		if (Check()) {
			Activate();
		}
	}
};

template <typename T>
class EventInput : public IEvent {
  private:
	const int key;
	const int type;
	T* obj;
	using mFuncPointer = void (T::*)();
	mFuncPointer fCall; //= &Object::f

  public:
	EventInput(int key, int type, T* object, void (T::* func)()) : key(key), type(type) {
		Inputs::SetKey(key);
		obj = object;
		fCall = func;
	}
		
	bool Check() override {
		if (type == CLICK)
			return Inputs::isClick(key);
		else
			return Inputs::isPresed(key);
	}

	void Activate() {
		(obj->*fCall)();
	}
	~EventInput() { }
};


