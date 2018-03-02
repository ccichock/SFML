#ifndef BALL_HPP
#define BALL_HPP

#include "Pad.hpp"
#include "Wall.hpp"
#include "EventManager.hpp"
#include "FrameHandler.hpp"

using namespace sf;

class Ball
{
	EventManager& eventManager;

	std::unique_ptr<FrameHandler> frameHandler;

	int radius;
	std::unique_ptr<CircleShape> ball;

	float xAxisMove;
	float yAxisMove;
	float xBallSpeed;
	float yBallSpeed;

	int nrObject;

public:

	Ball(EventManager& eventManager_);
	~Ball();

	void start();

	CircleShape& getBall();

	void move(Pad& pad);
	bool checkWallColision(Wall& wallref);

private:

	bool hitLeftWallEdge(const Squere& wall);
	bool hitRightWallEdge(const Squere& wall);
	bool hitUpWallEdge(const Squere& wall);
	bool hitDownWallEdge(const Squere& wall);
	
	bool hitLeftPadEdge(Pad&padref);
	bool hitRightPadEdge(Pad&padref);
	bool hitUpPadEdge(Pad&padref);
	bool hitDownPadEdge(Pad&padref);
	
	bool hitBottomEdge();
	bool hitLeftOrRightEdge();
	bool hitTopEdge();
	bool hitPad(Pad& pad);
};

inline CircleShape& Ball::getBall() { return *ball; }

inline void Ball::move(Pad& pad)
{
	frameHandler->measureTime();

	if(eventManager.stateOfGame() == State::PLAY && frameHandler->isNextFrame())
	{
		frameHandler->resetTime();

		if( this->hitLeftOrRightEdge() ) xBallSpeed = -xBallSpeed;
		else if( this->hitTopEdge() ) yBallSpeed = -yBallSpeed;
		else if( this->hitPad(pad) ) yBallSpeed = -yBallSpeed;
		else if( this->hitBottomEdge() ) 
		{
			eventManager.gameOver();
		}

		xAxisMove += xBallSpeed;
		yAxisMove += yBallSpeed;
		ball->setOrigin(xAxisMove, yAxisMove);
	}
}

inline bool Ball::hitBottomEdge() { return yAxisMove - 2 * radius < -600; }
inline bool Ball::hitLeftOrRightEdge() { return xAxisMove + xBallSpeed > 0 || xAxisMove + xBallSpeed - 2 * radius < -800; }
inline bool Ball::hitTopEdge() { return  yAxisMove + yBallSpeed > 0; }
bool hitPad(Pad& pad);


#endif

