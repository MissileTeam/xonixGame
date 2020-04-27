#include "levels.h"
using namespace sf;



levels::levels(float width, float hight, int mode,RenderWindow &CustomWindow,std:: string*name)
{
	if (mode == 0)
	{
		if (!font2.loadFromFile("Data/menu.ttf")) {}

		//level 1
		mainlevels[0].setFont(font2);
		mainlevels[0].setFillColor(Color::Blue);
		mainlevels[0].setString("Level One");
		mainlevels[0].setCharacterSize(50);
		mainlevels[0].setPosition(Vector2f(width / 4 - 150, hight / (Max_main_levels + 1)));

		//level 2
		mainlevels[1].setFont(font2);
		mainlevels[1].setFillColor(Color::White);
		mainlevels[1].setString("Level Two");
		mainlevels[1].setCharacterSize(50);
		mainlevels[1].setPosition(Vector2f(width / 4 - 150, hight / (Max_main_levels + 1) * 3));

		//level 3
		mainlevels[2].setFont(font2);
		mainlevels[2].setFillColor(Color::White);
		mainlevels[2].setString("Level Three");
		mainlevels[2].setCharacterSize(50);
		mainlevels[2].setPosition(Vector2f(width / 4 - 150, hight / (Max_main_levels + 1) * 5));

		//level 4
		mainlevels[3].setFont(font2);
		mainlevels[3].setFillColor(Color::White);
		mainlevels[3].setString("Level four");
		mainlevels[3].setCharacterSize(50);
		mainlevels[3].setPosition(Vector2f(width / 4 - 150, hight / (Max_main_levels + 1) * 7));

		//level 5
		mainlevels[4].setFont(font2);
		mainlevels[4].setFillColor(Color::White);
		mainlevels[4].setString("Level five");
		mainlevels[4].setCharacterSize(50);
		mainlevels[4].setPosition(Vector2f(width / 2 + 120, hight / (Max_main_levels + 1) * 1));

		//level 6
		mainlevels[5].setFont(font2);
		mainlevels[5].setFillColor(Color::White);
		mainlevels[5].setString("Level six");
		mainlevels[5].setCharacterSize(50);
		mainlevels[5].setPosition(Vector2f(width / 2 + 120, hight / (Max_main_levels + 1) * 3));

		//level 7
		mainlevels[6].setFont(font2);
		mainlevels[6].setFillColor(Color::White);
		mainlevels[6].setString("Level seven");
		mainlevels[6].setCharacterSize(50);
		mainlevels[6].setPosition(Vector2f(width / 2 + 120, hight / (Max_main_levels + 1) * 5));

		//level 8
		mainlevels[7].setFont(font2);
		mainlevels[7].setFillColor(Color::White);
		mainlevels[7].setString("Level eight");
		mainlevels[7].setCharacterSize(50);
		mainlevels[7].setPosition(Vector2f(width / 2 + 120, hight / (Max_main_levels + 1) * 7));

		//Custom levels
		mainlevels[8].setFont(font2);
		mainlevels[8].setFillColor(Color::White);
		mainlevels[8].setString("Custom levels");
		mainlevels[8].setCharacterSize(50);
		mainlevels[8].setPosition(Vector2f(width / 4 - 150, hight / (Max_main_levels + 1) * 9));


		//exit_levels
		mainlevels[9].setFont(font2);
		mainlevels[9].setFillColor(Color::White);
		mainlevels[9].setString("Main Menu");
		mainlevels[9].setCharacterSize(50);
		mainlevels[9].setPosition(Vector2f(width / 2 + 120, hight / (Max_main_levels + 1) * 9));

		mainlevelsSelected = 0;
	}
	else if (mode == 1)
	{
		if (!font2.loadFromFile("Data/menu.ttf")) {}
		// set Text elements
		for (int i = 0; i < nCustom_level; ++i)
		{
			if (i == 1)
			{
				CustomLevels[1].setFillColor(Color::Green);
			}
			else
			{
				CustomLevels[i].setFillColor(Color::White);
			}
			CustomLevels[i].setFont(font2);
			CustomLevels[i].setString(name[i]);
			CustomLevels[i].setPosition(Vector2f(ScreenWidth / 4 - 150, ScreenHeight / (Max_main_levels + 1) * (1 + 2 * i)));
			CustomLevels[i].setCharacterSize(50);
			//displaying Them to screen
		}
		mainClevelsSelected = 1;
	}

}


void levels::display_customLevels(std::string* levelnames, RenderWindow& window)
{

	// set Text elements
	for (int i = 0; i < nCustom_level; ++i)
	{
		//displaying Them to screen
		window.draw(CustomLevels[i]);
	}
}





levels::~levels()
{

}

//Function of drawing levels 
void levels::draw(RenderWindow& window_Levels)
{
	for (int i = 0; i < 10; i++)
	{
		window_Levels.draw(mainlevels[i]);
	}
}

//void levels::display_customLevels(std::string* levelnames, RenderWindow&  cLevelsWindow)
//{
//	for (int j = 0; j <nCustom_level; j++)
//	{
//		cLevelsWindow.draw(CustomLevels[j]);
//	}
//}
//move down 
void levels::moveDown()
{
	if (mainlevelsSelected + 1 <= Max_main_levels) //check if not on the last item (level3)    
	{

		mainlevels[mainlevelsSelected].setFillColor(Color::White);			// áæ Ýí ÈÚÏíåÇ æÇäÇ ÏæÓÊ Úáí Ïæä íÈÞí Çááí ÇäÇ æÇÞÝ ÚáíåÇ ÇÈíÖ ææåíÍÑßäí Úáí Çááí ÈÚÏí

		mainlevelsSelected++; //move to the lower item 
		if (mainlevelsSelected == 10)  //=3 == level 4 and it not found
		{
			mainlevelsSelected = 0;
		}
		mainlevels[mainlevelsSelected].setFillColor(Color::Blue);	//change the new item's color
	}
}
//move up 
void levels::moveup()
{
	if (mainlevelsSelected - 1 >= -1) //check if not on the first item (level 1)
	{
		mainlevels[mainlevelsSelected].setFillColor(Color::White); //change the pervious item's color

		mainlevelsSelected--;        //move to the upper item 
		if (mainlevelsSelected == -1)
		{
			mainlevelsSelected = 9;
		}

		mainlevels[mainlevelsSelected].setFillColor(Color::Blue); //change the new item's color



	}
}




void levels::moveDown(int mode)
{
	if (mainClevelsSelected + 1 <= nCustom_level) //check if not on the last item (level3)    
	{

		CustomLevels[mainClevelsSelected].setFillColor(Color::White);			// áæ Ýí ÈÚÏíåÇ æÇäÇ ÏæÓÊ Úáí Ïæä íÈÞí Çááí ÇäÇ æÇÞÝ ÚáíåÇ ÇÈíÖ ææåíÍÑßäí Úáí Çááí ÈÚÏí

		mainClevelsSelected++; //move to the lower item 
		if (mainClevelsSelected == 4)  //=3 == level 4 and it not found
		{
			mainClevelsSelected = 0;
		}
		CustomLevels[mainClevelsSelected].setFillColor(Color::Green);	//change the new item's color
	}
}



void levels::moveUp(int mode)
{
	if (mainClevelsSelected - 1 >= -1) //check if not on the first item (level 1)
	{
		CustomLevels[mainClevelsSelected].setFillColor(Color::White); //change the pervious item's color

		mainClevelsSelected--;        //move to the upper item 
		if (mainClevelsSelected == -1)
		{
			mainClevelsSelected = 0;
		}

		CustomLevels[mainClevelsSelected].setFillColor(Color::Green); //change the new item's color



	}
}
