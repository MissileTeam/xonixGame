#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

#define Max_Custom 3
#define width 680
#define height 820
class Custom //menuu
{
public:
	Custom();

	void display_Custom();
	void draw(sf::RenderWindow& window_Custom);
	void moveUp();
	void moveDown();

	int mainCustomPressed()
	{
		return mainCustomSelected;
	}

	~Custom();

public:
	int mainCustomSelected;
	sf::Font font;
	sf::Text mainCustom[Max_Custom];
};