#ifndef WALL_H
#define WALL_H

#include <vector>

#include <SFML/Graphics.hpp>

using namespace sf;

struct Squere : public RectangleShape
{
	Squere(int x_, int y_) : x(x_), y(y_), width(40), height(40)
	{
		setSize(Vector2f(width, height));
		setFillColor(Color::Cyan);
		setOrigin(x, y);
	}

	int x;
	int y;
	int width;
	int height;
};


class Wall
{
	std::vector<Squere> wallContainer;
	int nrWalls;
	int xStart;
	int yStart;
	int wallSpace;

	int nrObject;
public:

	Wall();
	void createWalls();
	void setPosition(Squere& wall, int& x, int& y);

	std::vector<Squere>& getWalls();

	~Wall();
};

inline std::vector<Squere>& Wall::getWalls() { return wallContainer; }

#endif