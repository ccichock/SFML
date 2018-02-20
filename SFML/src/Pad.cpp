#include "Pad.hpp"

#include <iostream>

Pad::Pad() : pad(Vector2f(120,20))
{
	x = -400;
	y = -550;
	width = 120;
	height = 20;
	pad.setOrigin(x, y);
	pad.setFillColor(Color::White);

	nrObject = 1;
}


Pad::~Pad()
{
	std::cout<< "End of Pad with: "<< --nrObject << " objects"<<std::endl;
}