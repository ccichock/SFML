#ifndef TIME_HANDLER_H
#define TIME_HANDLER_H

#include <memory>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

using namespace sf;

class FrameHandler
{
	std::unique_ptr<Clock> clock;
	std::unique_ptr<Time> timeStart;
	std::unique_ptr<Time> now;
	int frame;
	int time;

public:

	FrameHandler(int frame_);

	void measureTime();
	bool isNextFrame();
	void resetTime();

	~FrameHandler();
};



inline void FrameHandler::measureTime()
{
	*now = clock->getElapsedTime();
	time = now->asMilliseconds() - timeStart->asMilliseconds();
}

inline bool FrameHandler::isNextFrame() { return time >= frame; }

inline void FrameHandler::resetTime()
{
	clock->restart();
	*timeStart = clock->getElapsedTime();
	*now = clock->getElapsedTime();
}


#endif