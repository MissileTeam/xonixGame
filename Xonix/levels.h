#pragma once
#include <SFML\Graphics.hpp>
#include <string>
using namespace sf;
#define Max_main_levels 10 
#define ScreenWidth 680
#define ScreenHeight 820
class Levels_menu
{
public:
	int nCustom_level = 9;
	Levels_menu(float width, float hight, int mode,RenderWindow& CustomWindow,std:: string * name);


	void draw(RenderWindow& window_Levels);
	void moveup();
	void moveDown();
	void moveUp(int mode,std::string* name);
	void moveDown(int mode,std::string* name);
	int mainlevelsPressed()
	{
		return mainlevelsSelected;
	}
	int mainClevelsPressed()
	{
		return mainClevelsSelected;
	}
	void display_customLevels(std::string* levelnames, RenderWindow& window);



	~Levels_menu();
private:
	int mainlevelsSelected=0;
	int mainClevelsSelected=1;
	Font font2;
	Text mainlevels[Max_main_levels];
	Text* CustomLevels = new Text[nCustom_level];
};
