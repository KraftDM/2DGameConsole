#include "PickableObject.h"
#include "Game.h"
#include "Resources.h"
#include "EventPosition.h"

PickableObject::PickableObject() {
	sprite = new Sprite(141, &Resources::atlases[0]);
	 
	//TO DO Добавить констурктор обьект - обьект, обьект - позиция
	EventPosition<PickableObject>* i = new EventPosition<PickableObject>(&position, &Game::player->position, CLOSE, this, &GameObject::TransportTo, 10);
	//ivent = i;
	Game::PushEvent(i);
}
