#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
#define Max_main_levels 10 
class levels
{
public:
	levels(float width, float hight);
	void draw(RenderWindow& window_Levels);
	void moveup();
	void moveDown();
	int mainlevelsPressed()
	{
		return mainlevelsSelected;
	}

	~levels();
private:
	int mainlevelsSelected;
	Font font2;
	Text mainlevels[Max_main_levels];

};