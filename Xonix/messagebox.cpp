#include "messagebox.h"
using namespace sf;

messagebox::messagebox(float  messageWidth, float  massegeHeight)
{
	if (!font.loadFromFile("Data/menu.ttf")) {

	}

	//yes
	mainmessage[0].setFont(font);
	mainmessage[0].setFillColor(Color::Magenta);
	mainmessage[0].setString("YES");
	mainmessage[0].setCharacterSize(40);
	mainmessage[0].setPosition(Vector2f(150, 290));
	//no
	mainmessage[0].setFont(font);
	mainmessage[0].setFillColor(Color::White);
	mainmessage[0].setString("NO");
	mainmessage[0].setCharacterSize(40);
	mainmessage[0].setPosition(Vector2f(200, 290));

	messageSelected = 0;
}


messagebox::~messagebox()
{
}


//Function of drawing message
void messagebox::draw(RenderWindow& message)
{
	for (int i = 0; i < 2; i++)
	{
		message.draw(mainmessage[i]);
	}
}


//move right
void messagebox::moveRight()
{
	if (messageSelected + 1 <= Max_message) //check if not on the last item (exit)
	{
		mainmessage[messageSelected].setFillColor(Color::White);

		messageSelected++; //move to the right item 
		if (messageSelected == 2)
		{
			messageSelected = 0;
		}
		mainmessage[messageSelected].setFillColor(Color::Magenta); //change the new item's color
	}
}

//move left
void messagebox::moveLeft()
{
	if (messageSelected - 1 >= -1) //check if not on the first item (play)
	{
		mainmessage[messageSelected].setFillColor(Color::White); //change the pervious item's color

		messageSelected--;        //move to the upper item 
		if (messageSelected == -1)
		{
			messageSelected = 1;
		}
		mainmessage[messageSelected].setFillColor(Color::Magenta); //change the new item's color
	}
}
