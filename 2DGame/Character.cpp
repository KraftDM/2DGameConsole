#include "Character.h"
#include "Game.h"
#include "Resources.h"

Character::Character() : hp(10)
{
	sprite = nullptr;
}

Player::Player() : lvl(10) {
	
	sprite = new Sprite(30, &Resources::atlases[0]);

	EventInput<Player>* upE = new EventInput<Player>(0x57, PRESED, this, &Character::MoveUp); // KEY: W
	Game::PushEvent(upE);

	EventInput<Player>* rightE = new EventInput<Player>(0x44, PRESED, this, &Character::MoveRight); // KEY: D
	Game::PushEvent(rightE);

	EventInput<Player>* leftE = new EventInput<Player>(0x41, PRESED, this, &Character::MoveLeft); // KEY: A
	Game::PushEvent(leftE);

	EventInput<Player>* downE = new EventInput<Player>(0x53, PRESED, this, &Character::MoveDown); // KEY: S
	Game::PushEvent(downE);	
}

