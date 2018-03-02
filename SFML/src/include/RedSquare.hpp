#include "InterfaceSquare.hpp"

#include <vector>

struct RedSquare: public RectangleShape
{
	RedSquare(int x_,int y_) : y(y_), width(30), height(30),speed(-1)
	{
		setSize(Vector2f(width, height));
		setFillColor(Color::Red);
		x = -(rand() %600); 
		setOrigin(x, y);
	
	}
	
	int x;
	int y;
	int width;
	int height;
	float speed;
	
};

struct Amunnition: public RectangleShape
{
	Amunnition(int x_,int y_) : width(20), height(20),speed(-1)
	{
		setSize(Vector2f(width, height));
		setFillColor(Color::Green);
		x =-500; 
		y= -500;
	
		setOrigin(x, y);
	
	}
	
    int x;
	int y;
	int width;
	int height;
	float speed;
	
};


struct WhiteSquare: public RectangleShape
{
	WhiteSquare(int x_,int y_) : y(y_), width(30), height(30),speed(-1)
	{
		setSize(Vector2f(width, height));
		setFillColor(Color::White);
	//	x = -(rand() %600); 
		x = -(rand() %600+2); 
		setOrigin(x, y);
	
	}
	
	int x;
	int y;
	int width;
	int height;
	float speed;
	
};

struct BlackSquare: public RectangleShape
{
	BlackSquare(int x_,int y_) : y(y_), width(30), height(30),speed(-1)
	{
		setSize(Vector2f(width, height));
		setFillColor(Color::Black);
		x = -(rand() %600+1); 
		setOrigin(x, y);
		
	}
	
	int x;
	int y;
	int width;
	int height;
	float speed;
	
};

#include "FrameHandler.hpp"
#include "Pad.hpp"

class SpecialSquare
{		
	int xWallSpeed;
	int yWallSpeed; 
	int random;
	bool addRedSquere = true;
	bool addBlackSquere = true;
	bool whereAdd = true;
	int squareSpace = 10;
	int xStart=-650;
    int yStart= -550;
    int a =0;
	
	std::unique_ptr<FrameHandler> frameHandler= std::make_unique<FrameHandler>(3);
	std::unique_ptr<FrameHandler> frameHandler2= std::make_unique<FrameHandler>(10000);
	std::unique_ptr<FrameHandler> frameHandler4= std::make_unique<FrameHandler>(10000);
	std::unique_ptr<FrameHandler> frameHandler6= std::make_unique<FrameHandler>(10000);
	std::unique_ptr<FrameHandler> frameHandler3= std::make_unique<FrameHandler>(3);
	std::unique_ptr<FrameHandler> frameHandler5= std::make_unique<FrameHandler>(3);
	std::vector<RedSquare> redSquares;
	std::vector<BlackSquare> blackSquares;
	std::vector<WhiteSquare> whiteSquares;
	std::vector<Amunnition> amunition;
	
	public:
		int Update(int &x_)
		{
			xStart -= x_;
			x_ -= 20;
			std::cout << "update: " << x_ << std::endl;
			std::cout << "update - start: " << xStart<< std::endl;
			return xStart;
		}
	void setOrigin()
	{
		int x = Update(a);
		int y = yStart;
	//	std::cout << "x: " << x <<'\n';
		Amunnition amun(x, y);
	//	amun->setOrigin(x,y);
		this->setPosition(amun, x, y);
		amunition.push_back(amun);
		
	//	std::cout << "amunition size: " << amunition.size() <<'\n';
		
	}
	
	setPosition(Amunnition& whitesquare, int& x, int& y)
	{
		x = Update(a) + squareSpace;
		
		
	/*	if(x == xStart - 12 * (whitesquare.width + squareSpace) ) 
		{
			x = xStart;
			y -= 50;
		}*/
	}
	
		bool createRedSquare()
		{
			random = rand() % 100;
			return random % 4 == 0;
		}
		
		bool createBlackSquare()
		{
			random = rand() % 100;
			return random % 10 == 0;
		}
		
		bool createWhiteSquare()
		{
			random = rand() % 100;
			return random % 5 == 0;
		}
	
		std::vector<Amunnition>& getAmunnition()
	{
		return amunition;
	}
		
	std::vector<RedSquare>& getRedSquare()
	{
		return redSquares;
	}
	
	std::vector<BlackSquare>& getBlackSquare()
	{
		return blackSquares;
	}
	
	std::vector<WhiteSquare>& getWhiteSquare()
	{
		return whiteSquares;
	}
	
	void fallDownRedSquare()
	{
		frameHandler->measureTime();
		
		if( frameHandler->isNextFrame())
		{
			frameHandler->resetTime();
			
			for(int i=0; i< redSquares.size();i++)
			{
				redSquares[i].y -=1;
				redSquares[i].setOrigin(redSquares[i].x,redSquares[i].y);
			}
		}
	}
	
	void fallDownWhiteSquare()
	{
		frameHandler5->measureTime();
		
		if( frameHandler5->isNextFrame())
		{
			frameHandler5->resetTime();
			
			for(int i=0; i< whiteSquares.size();i++)
			{
				whiteSquares[i].y -=1;
				whiteSquares[i].setOrigin(whiteSquares[i].x,whiteSquares[i].y);
			}
		}
	}
	
	void fallDownBlackSquare()
	{
		frameHandler3->measureTime();
		
		if( frameHandler3->isNextFrame())
		{
			frameHandler3->resetTime();
			
			for(int i=0; i< blackSquares.size();i++)
			{
				blackSquares[i].y -=1;
				blackSquares[i].setOrigin(blackSquares[i].x,blackSquares[i].y);
			}
		}
	}
	
	bool checkPadColiisionWhiteSquare(Pad& padref)
	{
			frameHandler6->measureTime();
		//	int i =0;
		
		whiteSquares.erase(std::remove_if(whiteSquares.begin(),whiteSquares.end(),[&](auto & whitesquare)
		{
			if(whitesquare.x <= padref.xPos()  && 
			whitesquare.x - whitesquare.width >= padref.xPos() - padref.getWidth()  &&
			whitesquare.y >= padref.yPos() && 
			whitesquare.y - whitesquare.height <= padref.yPos() - padref.getHeight())
			{
					setOrigin();
					std::cout << "wszedlem do dodawania amunicji\n";				
			}
			return false;
		
		}),whiteSquares.end());
		
		if( frameHandler4->isNextFrame())
		{
			frameHandler4->resetTime();
		}
	}
	
	bool checkPadColiisionBlackSquare(Pad& padref)
	{
		
			frameHandler4->measureTime();
	
		
		blackSquares.erase(std::remove_if(blackSquares.begin(),blackSquares.end(),[&](auto & blacksquare)
		{
			if(blacksquare.x <= padref.xPos()  && 
			blacksquare.x - blacksquare.width >= padref.xPos() - padref.getWidth()  &&
			blacksquare.y >= padref.yPos() && 
			blacksquare.y- blacksquare.height <= padref.yPos() - padref.getHeight())
			{
				if(addBlackSquere == true)
				{
					
						padref.deleteWidth(20);
						whereAdd = false;
						addRedSquere = false;
				}
			}
			return false;
		
		}),blackSquares.end());
		
		if( frameHandler4->isNextFrame())
		{
			frameHandler4->resetTime();
			addRedSquere = true;
			padref.setNormalWidth(120);
		}
		
	}
	bool checkPadColiisionSquare(Pad& padref)
	{
			frameHandler2->measureTime();
	
		
		redSquares.erase(std::remove_if(redSquares.begin(),redSquares.end(),[&](auto & redsquare)
		{
			if(redsquare.x <= padref.xPos()  && 
			redsquare.x - redsquare.width >= padref.xPos() - padref.getWidth()  &&
			redsquare.y >= padref.yPos() && 
			redsquare.y- redsquare.height <= padref.yPos() - padref.getHeight())
			{
				if(addRedSquere == true)
				{
					if(whereAdd == true)
					{
						padref.addRightWidth(20);
						whereAdd = false;
						addRedSquere = false;
						
					}
					else
					{
						padref.addRightWidth(20);
						addRedSquere = false;
						whereAdd = true;
					}
				}
				return true;
			}
			return false;
		
		}),redSquares.end());
		
		
		
		if( frameHandler2->isNextFrame())
		{
			frameHandler2->resetTime();
			addRedSquere = true;
			padref.setNormalWidth(120);
		}
	}
	
};
