#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
#define Max_main_menu 3
class menu
{
public:

	menu(float width, float hight);
	void draw(RenderWindow& window);
	void moveup();
	void moveDown();
	int mainmenuPressed()
	{
		return mainmenuSelected;
	}
	~menu();
private:
	int mainmenuSelected;
	Font font;
	Text mainmenu[Max_main_menu];
};