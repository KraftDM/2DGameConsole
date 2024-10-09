#include "Game.h"

list<IEvent*> Game::events = {};
Player* Game::player = nullptr;

void Game::Run()
{
	Draw();
	ListenEvents();
}

void Game::Draw()
{
	
}

void Game::PushEvent(IEvent* event)
{
	events.push_back(event);
}
