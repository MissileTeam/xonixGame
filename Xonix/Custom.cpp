#include "Custom.h"
using namespace sf;
#define width 680
#define height 820
Custom::Custom()
{
	display_Custom();
}


Custom::~Custom()
{
}



void Custom::display_Custom()
{
	if (!font.loadFromFile("Data/arial.ttf")) {}

	//make_level
	mainCustom[0].setFont(font);
	mainCustom[0].setFillColor(Color::Blue);
	mainCustom[0].setString("make_level");
	mainCustom[0].setCharacterSize(50);
	mainCustom[0].setPosition(Vector2f(width / 2, height / (Max_Custom + 1)));

	//load_level
	mainCustom[1].setFont(font);
	mainCustom[1].setFillColor(Color::White);
	mainCustom[1].setString("load_level");
	mainCustom[1].setCharacterSize(50);
	mainCustom[1].setPosition(Vector2f(width / 2, height / (Max_Custom + 1) * 2));


	//exit
	mainCustom[2].setFont(font);
	mainCustom[2].setFillColor(Color::White);
	mainCustom[2].setString("main_levels");
	mainCustom[2].setCharacterSize(50);
	mainCustom[2].setPosition(Vector2f(width / 2, height / (Max_Custom + 1) * 3));

	mainCustomSelected = 0;  //start from zero index (play)
}

//********************************Function of drawing main menu**********************************************//
void Custom::draw(RenderWindow& window_Custom)
{
	for (int i = 0; i < 3; i++)
	{
		window_Custom.draw(mainCustom[i]);
	}
}

//********************************Function of moving up***************************************************
void Custom::moveUp()
{
	if (mainCustomSelected - 1 >= -1) // check if not on the first item (play)

	{

		mainCustom[mainCustomSelected].setFillColor(Color::White);  //change the pervious item's color

		mainCustomSelected--;  //move to the upper item       
		if (mainCustomSelected == -1)
		{
			mainCustomSelected = 2;
		}
		mainCustom[mainCustomSelected].setFillColor(Color::Blue); //change the new item's color
	}
}

//********************************Function of moving down***************************************************
void Custom::moveDown()
{
	if (mainCustomSelected + 1 <= Max_Custom) //check if not on the last item (exit)

	{
		mainCustom[mainCustomSelected].setFillColor(Color::White);  //change the pervious item's color

		mainCustomSelected++;  //move to the lower item
		if (mainCustomSelected == 3)
		{
			mainCustomSelected = 0;
		}
		mainCustom[mainCustomSelected].setFillColor(Color::Blue);           //change the new item's color

	}
}