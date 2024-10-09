#pragma once
#include "IEvent.h"
#include "Character.h"

#include <list>

class Game {

public:
	static Player* player;

private:
	static list<IEvent*> events;

public:
	Game(){
		
	}

	void Run();
	static void PushEvent(IEvent* event);

private:
	void Draw();

private:
	void ListenEvents() {
		for (auto event : events) {
			event->Listen();
		}
	}
};

