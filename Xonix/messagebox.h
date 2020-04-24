#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
#define Max_message 2

class messagebox
{
public:
	messagebox(float  messageWidth, float  massegeHeight);
	void draw(RenderWindow& message);
	void moveLeft();
	void moveRight();
	int messagePressed()
	{
		return  messageSelected;
	}
	~messagebox();

private:
	int messageSelected;
	Font font;
	Text mainmessage[Max_message];
};


