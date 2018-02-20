#include "Ball.hpp"


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


void Ball::checkWallColision(Wall& wallref)
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

	if(toRemove != walls.end()) wallref.getWalls().erase(toRemove);
}


bool Ball::hitLeftWallEdge(const Squere& wall)
{
	return xAxisMove - 2 * radius <= wall.x &&
		xAxisMove - 2 * radius > wall.x + xBallSpeed &&
		yAxisMove + yBallSpeed > wall.y - wall.height &&
		yAxisMove + yBallSpeed - 2 * radius < wall.y;
}


bool Ball::hitRightWallEdge(const Squere& wall)
{ 
	return xAxisMove >= wall.x - wall.width &&
		xAxisMove < wall.x - wall.width + xBallSpeed &&
		yAxisMove + yBallSpeed > wall.y - wall.height &&
		yAxisMove + yBallSpeed - 2 * radius < wall.y;
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
	return yAxisMove > wall.y - wall.height - yBallSpeed && 
		yAxisMove <= wall.y - wall.height &&
		xAxisMove + xBallSpeed - 2 * radius < wall.x &&	
		xAxisMove + xBallSpeed > wall.x - wall.width;
}


Ball::~Ball()
{
	std::cout<< "End of Ball with: "<< --nrObject << " objects"<<std::endl;
}