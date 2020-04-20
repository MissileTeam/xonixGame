#include "menu.h"
using namespace sf;

menu::menu(float width, float hight)
{
	if (!font.loadFromFile("Data/menu.ttf")) {}

	//play
	mainmenu[0].setFont(font);
	mainmenu[0].setFillColor(Color::Cyan);
	mainmenu[0].setString("play");
	mainmenu[0].setCharacterSize(50);
	mainmenu[0].setPosition(Vector2f(width / 4 - 150, hight / (Max_main_menu + 1)));

	//Credits
	mainmenu[1].setFont(font);
	mainmenu[1].setFillColor(Color::White);
	mainmenu[1].setString("Credits");
	mainmenu[1].setCharacterSize(50);
	mainmenu[1].setPosition(Vector2f(width / 4 - 150, hight / (Max_main_menu + 1) *3));


	//options
	mainmenu[2].setFont(font);
	mainmenu[2].setFillColor(Color::White);
	mainmenu[2].setString("options");
	mainmenu[2].setCharacterSize(50);
	mainmenu[2].setPosition(Vector2f(width / 4 - 150, hight / (Max_main_menu + 1) * 5));

	//exit
	mainmenu[3].setFont(font);
	mainmenu[3].setFillColor(Color::White);
	mainmenu[3].setString("Exit");
	mainmenu[3].setCharacterSize(50);
	mainmenu[3].setPosition(Vector2f(width / 4 - 150, hight / (Max_main_menu + 1) * 7));

	mainmenuSelected = 0;
}


menu::~menu()
{
}

//Function of drawing main menu 
void menu::draw(RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(mainmenu[i]);
	}
}


//move down 
void menu::moveDown()
{
	if (mainmenuSelected + 1 <= Max_main_menu) //check if not on the last item (exit)
	{
		mainmenu[mainmenuSelected].setFillColor(Color::White);

		mainmenuSelected++; //move to the lower item 
		if (mainmenuSelected == 4)
		{
			mainmenuSelected = 0;
		}
		mainmenu[mainmenuSelected].setFillColor(Color::Cyan); //change the new item's color
	}
}

//move up 
void menu::moveup()
{
	if (mainmenuSelected - 1 >= -1) //check if not on the first item (play)
	{
		mainmenu[mainmenuSelected].setFillColor(Color::White); //change the pervious item's color

		mainmenuSelected--;        //move to the upper item 
		if (mainmenuSelected == -1)
		{
			mainmenuSelected = 3;
		}
		mainmenu[mainmenuSelected].setFillColor(Color::Cyan); //change the new item's color
	}
}
