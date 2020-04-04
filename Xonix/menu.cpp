#include "menu.h"
using namespace sf;
menu::menu(float width, float hight)
{
	if (!font.loadFromFile("Data/numbers_font.ttf")) {}
	//play
	mainmenu[0].setFont(font);
	mainmenu[0].setColor(Color::Blue);
	mainmenu[0].setString("play");
	mainmenu[0].setCharacterSize(50);
	mainmenu[0].setPosition(Vector2f(width / 2 - 50, hight / (Max_main_menu +
		1)));
	//options
	mainmenu[1].setFont(font);
	mainmenu[1].setColor(Color::White);
	mainmenu[1].setString("options");
	mainmenu[1].setCharacterSize(50);
	mainmenu[1].setPosition(Vector2f(width / 2 - 50, hight / (Max_main_menu +
		1) * 2));
	//exit
	mainmenu[2].setFont(font);
	mainmenu[2].setColor(Color::White);
	mainmenu[2].setString("Exit");
	mainmenu[2].setCharacterSize(50);
	mainmenu[2].setPosition(Vector2f(width / 2 - 50, hight / (Max_main_menu +
		1) * 3));
	mainmenuSelected = 0;
}
menu::~menu()
{
}
//Function of drawing main menu
void menu::draw(RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainmenu[i]);
	}
}
//move down
void menu::moveDown()
{
	if (mainmenuSelected + 1 <= Max_main_menu) //check if not on the last item
		(exit)
	{
		mainmenu[mainmenuSelected].setColor(Color::White);
		mainmenuSelected++; //move to the lower item
		if (mainmenuSelected == 3)
		{
			mainmenuSelected = 0;
		}
		mainmenu[mainmenuSelected].setColor(Color::Blue); //change the new 	item's color

	
	}
}
//move up
void menu::moveup()
{
	if (mainmenuSelected - 1 <= -1) //check if not on the first item (play)
	{
		mainmenu[mainmenuSelected].setColor(Color::White); //change the pervious item's color

		

			mainmenuSelected--; //move to the upper item
		if (mainmenuSelected == -1)
		{
			mainmenuSelected = 2;
		}
		mainmenu[mainmenuSelected].setColor(Color::Blue); //change the new item's color

		
	}
}