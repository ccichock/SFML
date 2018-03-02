#include "InterfaceSquare.hpp"

struct BlackSquare: public RectangleShape
{
		BlackSquare(int x_,int y_) : y(y_), width(20), height(20),speed(-1)
	{
		setSize(Vector2f(width, height));
		setFillColor(Color::White);
		x = -(rand() %600); 
		setOrigin(x, y);
	
	}
	
	int x;
	int y;
	int width;
	int height;
	float speed;
	
};

/*class BlackSquare:public InterfaceSquare
{
		std::vector<BlackSquare> blackSquares;
		
	public:
	std::vector<BlackSquare>& getBlackSquare()
	{
		return blackSquares;
	}
	
};*/
