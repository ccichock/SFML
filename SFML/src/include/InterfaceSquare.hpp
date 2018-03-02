/*#include <vector>
#include <cstdlib>
#include <algorithm>

#include "FrameHandler.hpp"
#include "Pad.hpp"

class SpecialSquare
{		
	int xWallSpeed;
	int yWallSpeed; 
	int random;
	bool addRedSquere = true;
	bool whereAdd = true;
	
	std::unique_ptr<FrameHandler> frameHandler= std::make_unique<FrameHandler>(3);
	std::unique_ptr<FrameHandler> frameHandler2= std::make_unique<FrameHandler>(10000);
	std::unique_ptr<FrameHandler> frameHandler3= std::make_unique<FrameHandler>(3);
	std::vector<BlackSquare> redSquares;
		
	public:
	std::vector<BlackSquare>& getBlackSquare()
	{
		return squares;
	}
	public:
		bool createSquare()
		{
			random = rand() % 100;
			return random %4 == 0;
		}
	
	
	void fallDownSquare()
	{
		frameHandler->measureTime();
		
		if( frameHandler->isNextFrame())
		{
			frameHandler->resetTime();
			
			for(int i=0; i< squares.size();i++)
			{
				redSquares[i].y -=1;
				redSquares[i].setOrigin(redSquares[i].x,redS/*quares[i].y);
			}
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
};*/
