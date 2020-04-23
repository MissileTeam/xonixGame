#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
#define Max_main_levels 10 
#define ScreenWidth 680
#define ScreenHeight 820
class levels
{
public:
	int nCustom_level = 9;
	levels(float width, float hight, int mode);

	void draw(RenderWindow& window_Levels);
	void moveup();
	void moveDown();
	void moveUp(int mode);
	void moveDown(int mode);
	int mainlevelsPressed()
	{
		return mainlevelsSelected;
	}
	void display_customLevels(std::string* levelnames,RenderWindow& window);
	

	

	~levels();
private:
	int mainlevelsSelected; 
	Font font2;
	Text mainlevels[Max_main_levels];
	Text* CustomLevels = new Text[nCustom_level];
};