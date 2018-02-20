#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <memory>

#include "WindowAplication.hpp"

enum State
{
	PLAY,
	PAUSE,
	GAME_OVER
};

class EventManager: public Event
{
	State gameState;
	int nrObject;

public:

	EventManager();

	Event& getEvent() { return *this; }

	void play();
	void setPause();
	void gameOver();
	State stateOfGame();

	bool close();
	bool newGame();
	bool pause();

	bool keyPressed();
	bool keyRight();
	bool keyLeft();

	~EventManager();
};

#endif