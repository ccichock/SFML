#include "Ball.hpp"
#include "EventManager.hpp"
#include "Wall.hpp"
#include "RedSquare.hpp"

#include<vector>

int main()
{
		
	std::unique_ptr<WindowAplication> window = std::make_unique<WindowAplication>();
	std::unique_ptr<EventManager> eventManager = std::make_unique<EventManager>();

	std::unique_ptr<Pad> pad = std::make_unique<Pad>();
	std::unique_ptr<Ball> ball = std::make_unique<Ball>(*eventManager);
	std::unique_ptr<Wall> walls = std::make_unique<Wall>();
	std::unique_ptr<SpecialSquare> specialSquare = std::make_unique<SpecialSquare>();
	

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
				if(eventManager->keyLeft()) pad->move(15);
				if(eventManager->keyRight()) pad->move(-15);
    	   	}
    	   	else break;
    	   	
    	}
		
		ball->move(*pad);
		auto isHitWall = ball->checkWallColision(*walls);
				
		if(specialSquare->createRedSquare() && isHitWall)
		{
			specialSquare->getRedSquare().emplace_back( RedSquare(-10,-10));
		}
		
		else if(specialSquare->createBlackSquare() && isHitWall)
		{
				specialSquare->getBlackSquare().emplace_back( BlackSquare(-10,-10));
		}
		else if(specialSquare->createWhiteSquare() && isHitWall)
		{
				specialSquare->getWhiteSquare().emplace_back( WhiteSquare(-10,-10));
		}
		
		specialSquare->fallDownRedSquare();
		specialSquare->fallDownBlackSquare();
		specialSquare->fallDownWhiteSquare();
		specialSquare->checkPadColiisionSquare(*pad);
		specialSquare->checkPadColiisionBlackSquare(*pad);
		specialSquare->checkPadColiisionWhiteSquare(*pad);
		
		
    	window->clear(Color::Blue);
		
		window->drawObject(ball->getBall());
		window->drawObject(pad->getPad());
		window->drawObject(walls->getWalls());
		window->drawObject(	specialSquare->getRedSquare());
		window->drawObject(	specialSquare->getBlackSquare());
		window->drawObject(	specialSquare->getWhiteSquare());
		window->drawObject(	specialSquare->getAmunnition());
		
		
		window->display();
	}
}
