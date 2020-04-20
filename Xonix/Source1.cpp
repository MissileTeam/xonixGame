
/*

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp> 
#include <sstream> 
#include<string>
#include <iostream> // to use input and output functions 
#include <ctime> //to use time functions 
#include "FilesHandler.h"
using namespace std;
using namespace sf;
//global varibles
int grid[82][62] = {};
struct enemy {//e=enemy
	// we put the function in the struct to make varibles of struct idientfied in the functions
	int expostion, eypostion, exvelocity, eyvelocity;
	enemy() {
		expostion = -10;
		eypostion = -10;
		exvelocity = 0;
		eyvelocity = 0;
	}
	void motion() {

		expostion += exvelocity;
		if (grid[expostion / 10][eypostion / 10] == 1) {
			exvelocity = -exvelocity;
			expostion += exvelocity;
		}
		eypostion += eyvelocity;
		if (grid[expostion / 10][eypostion / 10] == 1) {
			eyvelocity = -eyvelocity;
			eypostion += eyvelocity;
		}
	}
}enemies_struct[10];
int main(void)
{
	
	string levelgrid = "";
	sf::RenderWindow window(sf::VideoMode(820, 680), "Xonix");//render window 
	window.setFramerateLimit(30);//set frames to 60 per second 
	bool play = true;
	bool top = false, down = false, right = false, left = false; //key pressed bools 
	bool paint = false, clear = false;
	int xpos = 0, ypos = 0; //playes position
	int x_paint = 0, y_paint = 0;
	//
	Texture image;
	if (image.loadFromFile("Data/borders.png") == false)
	{
		cout << "image is not here";
		return 1; // end the program 
	}
	Texture image2;
	if (image2.loadFromFile("Data/borders1.png") == false)
	{
		cout << "image is not here";
		return 1; // end the program 
	}
	//font 
	Font number_font;
	if (number_font.loadFromFile("Data/numbers_font.ttf") == false)
	{
		cout << "font is not here";
		return 1; // end the program 
	}
/*	sf::RectangleShape enemies_shapes[8];
	for (int i = 0; i < 8; i++) {
		enemies_shapes[i].setSize(Vector2f(10, 10));
		enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
		
	}
	///////////////////////

	// time 
	time_t first_second, this_second;
	time(&first_second);
	int second = 0, minute = 0;
	//time text
	Text time_text;
	time_text.setFont(number_font);
	time_text.setFillColor(Color::Red);
	time_text.setPosition(0, 640);
	time_text.setCharacterSize(20);
	//player rectangle 
	RectangleShape player;
	player.setFillColor(Color::Magenta);
	player.setPosition(400, 300);
	player.setSize(Vector2f(10, 10));
	//under bound rectangle 
	RectangleShape bound;
	bound.setFillColor(Color::Red);
	bound.setPosition(0, 620);
	bound.setSize(Vector2f(820, 5));
	// event
	Event event;
	FilesHandler levelsFile;
	
	while (play)
	{
		Sprite Sgrid;
		//
		stringstream time_string;
		time(&this_second);
		if (second < 60)
		{
			second = this_second - first_second;
		}
		else if (second % 60 == 0)
		{
			minute++;
			time(&first_second);
			second = 0;
		}
		if (minute < 10)
		{
			if ((this_second - first_second) < 10)
			{
				time_string.clear();
				time_string << "Time " << "0" << minute << " : " << "0" << second;
			}
			else
			{
				time_string.clear();
				time_string << "Time " << "0" << minute << " : " << second;
			}
		}
		else
		{

			if ((this_second - first_second) < 10)
			{
				time_string.clear();
				time_string << "Time " << minute << " : " << "0" << second;
			}
			else
			{
				time_string.clear();
				time_string << "Time " << minute << " : " << second;
			}
		}
		while (window.pollEvent(event))
		{
			time_string.clear();
			if (event.type == Event::Closed)
			{
				play = false;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
				top = true;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down)
			{
				down = true;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right)
			{
				right = true;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
			{
				left = true;
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
			{
				top = false;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
			{
				down = false;
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
			{
				right = false;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
			{
				left = false;
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)
			{
				if (paint == true)
					paint = false;
				else
				{
					paint = true;
					clear = false;
				}
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
			{
				if (clear == true)
					clear = false;
				else
				{
					clear = true;
					paint = false;
				}
			}	
			string levelname = "";

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::P)
			{
				for (int i = 0; i < 82; i++)
				{
					for (int j = 0; j < 62; j++)
					{
						levelgrid += to_string(grid[i][j]);
						
					}
					//cout << endl;
					
				}
				cout << "Enter level name here : ";
				cin >> levelname;
				levelsFile.writeLevels(levelgrid,levelname);


				cout << "------------------------------------------------------------------------";
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::L)
			{
				levelgrid = levelsFile.load_levels();

				for (int i = 0; i < 82; i++)
				{
					for (int j = 0; j < 62; j++)
					{
						levelgrid += to_string(grid[i][j]);

					}
					//cout << endl;

				}
				cout << "level  : "+levelname;
				
				


				cout << "------------------------------------------------------------------------";
			}
			if (event.type == sf::Event::MouseMoved)
			{

				if (paint == true)
				{
					xpos = event.mouseMove.x / 10;
					ypos = event.mouseMove.y / 10;
				}
				else if (clear == true)
				{
					xpos = event.mouseMove.x / 10;
					ypos = event.mouseMove.y / 10;
				}
			}
			cout << event.mouseMove.x << " : " << event.mouseMove.y << endl;
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::K)
			{
				cout << "Enter brush x position : ";
				int x, y;
				cin >> x;
				if (x >= 0 && x <= 82)
				{
					xpos = x;
				}
				cout << "Enter brush y position : ";
				cin >> y;
				if (y >= 0 && y <= 68)
				{
					ypos = y;
				}
			}
		}

		int numberofenemy = 7;
		//player move 
		if (top == true)
		{
			ypos -= 1;
		}
		else if (down == true)
		{
			ypos += 1;
		}
		else if (right == true)
		{
			xpos += 1;
		}
		else if (left == true)
		{
			xpos -= 1;
		}
		if (x_paint != xpos)
			x_paint = xpos;
		if (y_paint != ypos)
			y_paint = ypos;
		if (paint == true)
		{
			grid[x_paint][y_paint] = 1;
		}
		if (clear == true)
		{
			grid[x_paint][y_paint] = 0;
		}
		// bound moving
		if (xpos >= 82)
			xpos -= 1;
		if (xpos < 0)
			xpos += 1;
		if (ypos >= 62)
			ypos -= 1;
		if (ypos < 0)
			ypos += 1;
		player.setPosition(xpos * 10, ypos * 10);
		time_text.setString(time_string.str());
	
		//draw 
		window.clear();

		for (int i = 0; i < 82; i++)
			for (int j = 0; j < 62; j++)
			{
				if (grid[i][j] == 0)
				{
					continue;
				}
				if (grid[i][j] == 1)
				{
					Sgrid.setTexture(image2);
				}
				if (grid[i][j] == 2)
				{
					Sgrid.setTexture(image);
				}

				Sgrid.setPosition(i * 10, j * 10);
				window.draw(Sgrid);
			}

		window.draw(player);
		window.draw(bound);
		
		window.draw(time_text);
		window.display();
	}
}
*/