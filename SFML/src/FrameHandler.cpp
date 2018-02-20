#include "FrameHandler.hpp"


FrameHandler::FrameHandler(int frame_) : frame(frame_) 
{
	clock = std::make_unique<Clock>();
	timeStart = std::make_unique<Time>();
	now = std::make_unique<Time>();

	*timeStart = clock->getElapsedTime();
	//frame = 3;
}

FrameHandler::~FrameHandler() {}