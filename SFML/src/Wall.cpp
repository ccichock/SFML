#include "Wall.hpp"

#include <iostream>


Wall::Wall() : nrWalls(36)
{
	xStart = -100;
	yStart = -100;
	wallSpace = 10;

	createWalls();

	nrObject = 1;
}


void Wall::createWalls()
{
	int x = xStart;
	int y = yStart;

	for(int wallIndex = 0; wallIndex < nrWalls; wallIndex++)
	{
		Squere wall(x, y);
	//	std::cout << random <<' ';
		this->setPosition(wall, x, y);
		wallContainer.push_back(wall);
	}
}

void Wall::setPosition(Squere& wall, int& x, int& y)
{
	x -= wall.width + wallSpace;
	if(x == xStart - 12 * (wall.width + wallSpace) ) 
	{
		x = xStart;
		y -= 50;
	}
}

Wall::~Wall()
{
	std::cout<< "End of Wall with: "<< --nrObject << " objects"<<std::endl;
}
