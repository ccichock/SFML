#include "EventManager.hpp"


EventManager::EventManager()
{
	gameState = PLAY;
	nrObject = 1;
}

void EventManager::play() { gameState = PLAY; }
void EventManager::setPause() { gameState = PAUSE; }
void EventManager::gameOver() { gameState = GAME_OVER; }
State EventManager::stateOfGame() { return gameState; }

bool EventManager::close()
{
	return type == Event::Closed || 
	((type == Event::KeyPressed) && (key.code == Keyboard::Escape));
}

bool EventManager::newGame()
{ 
	return ((this->stateOfGame() == State::GAME_OVER) &&
	(type == Event::KeyPressed));
}

bool EventManager::pause() { return (type == Event::KeyPressed) && (key.code == Keyboard::P); }
bool EventManager::keyPressed() { return (type == Event::KeyPressed); }
bool EventManager::keyRight() { return key.code == Keyboard::Right; }
bool EventManager::keyLeft() { return key.code == Keyboard::Left; }

EventManager::~EventManager() 
{
	std::cout<< "End of EventManager with: "<< --nrObject << " objects"<<std::endl;
}