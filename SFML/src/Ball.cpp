#include "Ball.hpp"
#include <cstdlib>


Ball::Ball(EventManager& eventManager_) : eventManager(eventManager_), radius(15)
{
	int frameTimeInMilisecond = 3;
	frameHandler = std::make_unique<FrameHandler>(frameTimeInMilisecond);

	ball = std::make_unique<CircleShape>(radius);
	xBallSpeed = -1;
	yBallSpeed = -1;
	this->start();
	ball->setFillColor(Color::Green);

	nrObject = 1;
}

void Ball::start() 
{
	xAxisMove = -100;
	yAxisMove = -300; 
	ball->setOrigin(xAxisMove, yAxisMove);
}


bool Ball::checkWallColision(Wall& wallref)
{
	std::vector<Squere>& walls = wallref.getWalls();
	
	auto toRemove = std::find_if(walls.begin(), walls.end(), [this](auto & wall)
	{	
		if(this->hitUpWallEdge(wall))
		{
			yBallSpeed = -yBallSpeed;
			return true;
		}
		else if(this->hitDownWallEdge(wall)) 
		{
			yBallSpeed = -yBallSpeed;
			return true;
		}
		else if(this->hitRightWallEdge(wall)) 
		{ 
			xBallSpeed = -xBallSpeed; 
			return true;
		}
		else if(this->hitLeftWallEdge(wall)) 
		{ 
			xBallSpeed = -xBallSpeed; 
			return true;
		}	
		else return false;
	});

	if(toRemove != walls.end()) 
	{
		wallref.getWalls().erase(toRemove);	
		return true;
	}
	else return false;

}
bool Ball::hitLeftPadEdge(Pad& padref)
{
	return xAxisMove - 2 * radius <= padref.xPos() &&
		xAxisMove - 2 * radius >= padref.xPos() + xBallSpeed &&
		yAxisMove + yBallSpeed >= padref.yPos() - padref.getHeight()&&
		yAxisMove + yBallSpeed - 2 * radius <= padref.yPos();
}

bool Ball::hitRightPadEdge(Pad& padref)
{
	return xAxisMove >= padref.xPos() -padref.getWidth() &&
		xAxisMove <= padref.xPos() - padref.getWidth() + xBallSpeed &&
		yAxisMove + yBallSpeed >= padref.yPos() - padref.getHeight() &&
		yAxisMove + yBallSpeed - 2 * radius <= padref.yPos();
}

bool Ball::hitUpPadEdge(Pad& padref)
{ 
	return yAxisMove + 2 * yBallSpeed - 2 * radius < padref.yPos() && yAxisMove - padref.getHeight() > padref.yPos() &&
 		xAxisMove - 1.5 * radius < padref.xPos() && xAxisMove + 0.5 * radius > padref.xPos() - padref.getWidth();
}

bool Ball::hitDownPadEdge(Pad& padref)
{ 
	return yAxisMove >= padref.yPos() - padref.getHeight() - yBallSpeed && 
		yAxisMove <= padref.yPos() - padref.getHeight() &&
		xAxisMove + xBallSpeed - 2 * radius <= padref.xPos() &&	
		xAxisMove + xBallSpeed >= padref.xPos() - padref.getWidth();
}

bool Ball::hitLeftWallEdge(const Squere& wall)
{
	return xAxisMove - 2 * radius <= wall.x &&
		xAxisMove - 2 * radius >= wall.x + xBallSpeed &&
		yAxisMove + yBallSpeed >= wall.y - wall.height &&
		yAxisMove + yBallSpeed - 2 * radius <= wall.y;
}


bool Ball::hitRightWallEdge(const Squere& wall)
{ 
	return xAxisMove >= wall.x - wall.width &&
		xAxisMove <= wall.x - wall.width + xBallSpeed &&
		yAxisMove + yBallSpeed >= wall.y - wall.height &&
		yAxisMove + yBallSpeed - 2 * radius <= wall.y;
}


bool Ball::hitUpWallEdge(const Squere& wall)
{ 
	return yAxisMove - 2 * radius >= wall.y &&
		yAxisMove - 2 * radius < wall.y - yBallSpeed &&
		xAxisMove + xBallSpeed - 2 * radius < wall.x &&	
		xAxisMove + xBallSpeed > wall.x - wall.width;
}


bool Ball::hitDownWallEdge(const Squere& wall)
{ 
	return yAxisMove >= wall.y - wall.height - yBallSpeed && 
		yAxisMove <= wall.y - wall.height &&
		xAxisMove + xBallSpeed - 2 * radius <= wall.x &&	
		xAxisMove + xBallSpeed >= wall.x - wall.width;
}

bool Ball::hitPad(Pad& pad)
{
		if(this->hitUpPadEdge(pad))
		{
			yBallSpeed = yBallSpeed;
			return true;
		}
		else if(this->hitDownPadEdge(pad)) 
		{
			yBallSpeed = -yBallSpeed;
			return true;
		}
		else if(this->hitRightPadEdge(pad)) 
		{ 
			xBallSpeed = -xBallSpeed; 
			yBallSpeed = -yBallSpeed;
			return true;
		}
		else if(this->hitLeftPadEdge(pad)) 
		{ 
			xBallSpeed = -xBallSpeed; 
			yBallSpeed = -yBallSpeed;
			return true;
		}	
		else return false;
}
Ball::~Ball()
{
	std::cout<< "End of Ball with: "<< --nrObject << " objects"<<std::endl;
}
