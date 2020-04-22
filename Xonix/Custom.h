#pragma once
#include <SFML\Graphics.hpp>

#define Max_Custom 3

class Custom //menuu
{
public:
	Custom(float width, float hegiht);


	void draw(sf::RenderWindow& window_Custom);
	void moveUp();
	void moveDown();

	int mainCustomPressed()
	{
		return mainCustomSelected;
	}

	~Custom();

private:
	int mainCustomSelected;
	sf::Font font;
	sf::Text mainCustom[Max_Custom];
};