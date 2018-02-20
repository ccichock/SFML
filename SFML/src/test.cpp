#include "Ball.hpp"
#include "EventManager.hpp"
#include "Wall.hpp"

int main()
{
	std::unique_ptr<WindowAplication> window = std::make_unique<WindowAplication>();
	std::unique_ptr<EventManager> eventManager = std::make_unique<EventManager>();

	std::unique_ptr<Pad> pad = std::make_unique<Pad>();
	std::unique_ptr<Ball> ball = std::make_unique<Ball>(*eventManager);
	std::unique_ptr<Wall> walls = std::make_unique<Wall>();

	while(window->isOpen())
	{
		while(window->pollEvent(eventManager->getEvent()))
		{
			if(eventManager->close())
			{
				window->close();
			}
    	   	else if (eventManager->newGame())
			{
    	   		eventManager->play();
    	   		ball->start();
    	   	}
    	   	else if (eventManager->pause())
			{
				if(eventManager->stateOfGame() != State::PLAY) eventManager->play();
				else if(eventManager->stateOfGame() != State::PAUSE) eventManager->setPause();
    	   	}
    	   	else if (eventManager->keyPressed())
			{
				if(eventManager->keyLeft()) pad->move(10);
				if(eventManager->keyRight()) pad->move(-10);
    	   	}
    	   	else break;
    	}

    	window->clear(Color::Blue);

		ball->move(*pad);
		ball->checkWallColision(*walls);

		window->drawObject(ball->getBall());
		window->drawObject(pad->getPad());
		window->drawObject(walls->getWalls());

		window->display();
	}
}