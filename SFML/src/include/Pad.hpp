#ifndef PAD_HPP
#define PAD_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

using namespace sf;

class Pad
{
	RectangleShape pad;
	int x;
	int y;
	int width;
	int height;

	int nrObject;

public:

	Pad();

	void move(int speed)
	{
		if(x + speed < 0 && x + speed > -800 + width) x += speed;
		pad.setOrigin(x, y);
	}

	RectangleShape& getPad();

	int xPos() { return x; }
	int yPos() { return y; }
	int getWidth() { return width; }
	int getHeight() { return height; }

	~Pad();
};

inline RectangleShape& Pad::getPad() { return pad; }

#endif

