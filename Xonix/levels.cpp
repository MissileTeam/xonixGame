#include "levels.h"
using namespace sf;



levels::levels(float width, float hight)
{
	if (!font2.loadFromFile("Data/numbers_font.ttf")) {}

	//level 1
	mainlevels[0].setFont(font2);
	mainlevels[0].setFillColor(Color::Blue);
	mainlevels[0].setString("Level One");
	mainlevels[0].setCharacterSize(50);
	mainlevels[0].setPosition(Vector2f(width / 2 - 50, hight / (Max_main_levels + 1)));

	//level 2
	mainlevels[1].setFont(font2);
	mainlevels[1].setFillColor(Color::White);
	mainlevels[1].setString("Level Two");
	mainlevels[1].setCharacterSize(50);
	mainlevels[1].setPosition(Vector2f(width / 2 - 50, hight / (Max_main_levels + 1) * 2));

	//level 3
	mainlevels[2].setFont(font2);
	mainlevels[2].setFillColor(Color::White);
	mainlevels[2].setString("Level Three");
	mainlevels[2].setCharacterSize(50);
	mainlevels[2].setPosition(Vector2f(width / 2 - 50, hight / (Max_main_levels + 1) * 3));

	mainlevelsSelected = -1;
}


levels::~levels()
{
}

//Function of drawing levels 
void levels::draw(RenderWindow& window_Levels)
{
	for (int i = 0; i < 3; i++)
	{
		window_Levels.draw(mainlevels[i]);
	}
}

//move down 
void levels::moveDown()
{
	if (mainlevelsSelected + 1 <= Max_main_levels) //check if not on the last item (level3)    
	{
		mainlevels[mainlevelsSelected].setFillColor(Color::White);			// لو في بعديها وانا دوست علي دون يبقي اللي انا واقف عليها ابيض ووهيحركني علي اللي بعدي

		mainlevelsSelected++; //move to the lower item 
		if (mainlevelsSelected == 3)  //=3 == level 4 and it not found
		{
			mainlevelsSelected = 0;
		}
		mainlevels[mainlevelsSelected].setFillColor(Color::Blue); //change the new item's color
	}
}

//move up 
void levels::moveup()
{
	if (mainlevelsSelected - 1 <= -1) //check if not on the first item (level 1)
	{
		mainlevels[mainlevelsSelected].setFillColor(Color::White); //change the pervious item's color

		mainlevelsSelected--;        //move to the upper item 
		if (mainlevelsSelected == -1)
		{
			mainlevelsSelected = 2;
		}
		mainlevels[mainlevelsSelected].setFillColor(Color::Blue); //change the new item's color
	}
}

