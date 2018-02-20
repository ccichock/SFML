#ifndef WINDOW_APLICATION_H
#define WINDOW_APLICATION_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <algorithm>
#include <vector>
#include <iostream>
#include <tuple>

using namespace sf;


template<class toDraw>
struct draw_impl
{
	static void draw(const toDraw& object, RenderWindow& app)
	{
		app.draw(object);
	}
};

template <class T>
struct draw_impl<std::vector<T>>
{
	static void draw(const std::vector<T>& container, RenderWindow& app)
	{
		std::for_each(container.begin(), container.end(), [&app](auto & object)
		{
			app.draw(object);
		});
	}
};

class WindowAplication :public RenderWindow
{
	int nrObject;
public:

	WindowAplication();

	template<class toDraw>
	void drawObject(const toDraw& object)
	{
		draw_impl<toDraw>::draw(object, *this);
	}

	~WindowAplication();
};

#endif