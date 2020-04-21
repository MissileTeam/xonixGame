#pragma once
#include <SFML\Graphics.hpp>
#include<string>
using namespace sf;
using namespace std;
#define Max_main_levels 10
#define hight 820
#define  width 680
class levels
{
public:
	levels();
	void draw(RenderWindow& window_Levels);
	void moveup();
	void moveDown();
	void displayCustom_lvs(string levels []);
	void display_mainLevels();

	int mainlevelsPressed()
	{
		return mainlevelsSelected;
	}

	~levels();
private:
	int mainlevelsSelected; int nCustom_levels = 0;
	Font font2;
	Text mainlevels[Max_main_levels];

	Text*customLevels = new Text[nCustom_levels];

};

