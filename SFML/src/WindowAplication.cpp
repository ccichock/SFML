#include "WindowAplication.hpp"

WindowAplication::WindowAplication() : RenderWindow(VideoMode(800,600), "App")
{
	setMouseCursorVisible(false);
	nrObject = 1;
}


WindowAplication::~WindowAplication() 
{
	std::cout<< "End of WindowAplication with: "<< --nrObject << " objects"<<std::endl;
}
