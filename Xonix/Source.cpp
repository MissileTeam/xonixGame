#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp> 
#include <iostream> // to use input and output functions 
#include <ctime> //to use time functions 
#include <sstream> 
#include "menu.h"   //call class of menu
#include <chrono>
#include <thread>
#define ScreenWidth 820
#define ScreenHeight 680
#define Rows 82
#define Coulmns 62
enum { Down, Up, Left, Right };
using namespace std;
using namespace sf;
int page_number;   //tell me i did selelction to which window
//global varibles
int grid[Rows][Coulmns] = {}; // window scale 
struct enemy {
	//e=enemy
	// we put the function in the struct to make varibles of struct idientfied in the functions
	short expostion, eypostion, exvelocity, eyvelocity;
	enemy() {
		expostion = 400;
		eypostion = 300;
		exvelocity = 4 - rand() % 8;
		eyvelocity = 4 - rand() % 8;
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
// Function to check the area around enemies and set it to (-1) and check the area to be  filled which is (0) bounded by (2) in the matrix
void rules_of_draw(int x, int y)
{
	if (grid[x][y] == 0)

		grid[x][y] = -1;

	if (grid[x - 1][y] == 0)

		rules_of_draw(x - 1, y);

	if (grid[x + 1][y] == 0)

		rules_of_draw(x + 1, y);

	if (grid[x][y + 1] == 0)

		rules_of_draw(x, y + 1);

	if (grid[x][y - 1] == 0)

		rules_of_draw(x, y - 1);

}
int main()
{
	while (true)   //this move on all pages
	{

		RenderWindow window(VideoMode(ScreenWidth, ScreenHeight), "Xonix");//render window 
		menu menuu(ScreenWidth, ScreenHeight);  //to take object from class  
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::KeyReleased)
				{
					if (event.key.code == Keyboard::Up)
					{
						menuu.moveup();
						break;
					}
					if (event.key.code == Keyboard::Down)
					{
						menuu.moveDown();
						break;
					}
				}
				//choose page
				if (event.key.code == Keyboard::Return)   // Return == I pressed enter
				{
					if (menuu.mainmenuPressed() == 0)    //  play
					{
						window.close();				//close the main window and open window.play
						page_number = 0;
					}
					if (menuu.mainmenuPressed() == 1)    //  options
					{
						window.close();				//close the main window and open window.option
						page_number = 1;

					}
					if (menuu.mainmenuPressed() == 2)    //  exit
					{
						window.close();				//close the main window and open window.exit
						page_number = 2;
					}
				}
			}

			window.clear();
			menuu.draw(window);
			window.display();
		}
		if (page_number == 0)
		{
			//play

			RenderWindow window_play(VideoMode(ScreenWidth, ScreenHeight), "play");//render window_play 

			window_play.setFramerateLimit(60);//set frames to 60 per second 
			bool play = true , endgame = false;; // play variable 
			int xpos = 0, ypos = 0; //playes position
			short dir = -1;//direction of the player  -1 means no direction in the start it can be anything

			//images 
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
			Font Arial_font;
			if (Arial_font.loadFromFile("Data/arial.ttf") == false)
			{
				cout << "font is not here";
				return 1; // end the program 
			}
			RectangleShape enemies_shapes[8];
			for (int i = 0; i < 8; i++) {
				enemies_shapes[i].setSize(Vector2f(10, 10));
				enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
			}
			// time 
			time_t first_second, this_second;
			time(&first_second);
			int second = 0, minute = 0;
			//time text
			Text time_text, PercentText;
			time_text.setFont(number_font);
			time_text.setFillColor(Color::Red);
			time_text.setPosition(0, 640);
			time_text.setCharacterSize(20);
			//Percent Text
			PercentText.setFont(Arial_font);
			PercentText.setFillColor(Color::Green);
			PercentText.setPosition(500, 630);
			PercentText.setCharacterSize(30);

			//player rectangle 
			RectangleShape player;
			player.setFillColor(Color::Magenta);
			player.setPosition(0, 0);
			player.setSize(Vector2f(10, 10));
			//under bound rectangle 
			RectangleShape bound;
			bound.setFillColor(Color::Red);
			bound.setPosition(0, 620);
			bound.setSize(Vector2f(820, 5));
			// event
			Event event;
			//sound
	// sound track while the game is playing
			Music music;
			if (!music.openFromFile("Data/soundtrack.ogg"))
				return -1;
			music.play();
			SoundBuffer sound;
			Sound collisionSound;
			if (sound.loadFromFile("Data/impact.wav"))
				cout << "collision done " << endl;
			collisionSound.setBuffer(sound);
			while (play)     //this move one page
			{
				Sprite Sgrid;
				int percent = 0;
				for (int i = 0; i < 82; i++)
				{
					for (int j = 0; j < 62; j++)
					{
						if (i == 0 || i == 81 || j == 0 || j == 61 || i == 1 || i == 80 || j == 1 || j == 60)
						{
							grid[i][j] = 1;
						}
						else if (grid[i][j] == 1)
						{
							percent++;
						}
						
					}
				}
				percent = percent / (44);
				// time string 
				stringstream time_string, areaString;
				areaString << "You Finished " << percent << "%";
				PercentText.setString(areaString.str());
			
				
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
					if ((second) < 10)
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

				while (window_play.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window_play.close();
						play = false;
						endgame = true;
					}

					if (Keyboard::isKeyPressed(Keyboard::Escape))
					{
						play = false;

					}

					if (Keyboard::isKeyPressed(Keyboard::Up)) 		dir = Up;

					else if (Keyboard::isKeyPressed(Keyboard::Down))	dir = Down;

					else if (Keyboard::isKeyPressed(Keyboard::Right))	dir = Right;

					else if (Keyboard::isKeyPressed(Keyboard::Left))	dir = Left;

				}


				//enemy move
				int numberofenemy = 7;
				for (int i = 1; i <= numberofenemy; i++) {
					enemies_struct[i].motion();
					rules_of_draw(enemies_struct[i].expostion / 10, enemies_struct[i].eypostion / 10);
				}
				//player movement in the Grid 
				if (grid[xpos][ypos] != 1)
				{
					grid[xpos][ypos] = 2;
				}
				if (grid[xpos][ypos] == 1)
				{
					if (Keyboard::isKeyPressed(Keyboard::Up))				ypos -= 1;

					else if (Keyboard::isKeyPressed(Keyboard::Down))		ypos += 1;

					else if (Keyboard::isKeyPressed(Keyboard::Right))		xpos += 1;

					else if (Keyboard::isKeyPressed(Keyboard::Left))		xpos -= 1;
				}
				else
				{
					if (dir == Up)	ypos -= 1;

					else if (dir == Down)	ypos += 1;

					else if (dir == Right)	xpos += 1;

					else if (dir == Left)	xpos -= 1;
				}
				// boundaries that anything can't go after it like player
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
				for (int i = 0; i <= numberofenemy; i++)
				{
					enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
				}
				for (int i = 0; i <= numberofenemy; i++)
				{
					if (grid[enemies_struct[i].expostion / 10][enemies_struct[i].eypostion / 10] == 2)
					{
						collisionSound.play();
						this_thread::sleep_for(0.2s);
						play = false;
						endgame = true;
						

					}
				}
				for (int i = 0; i < 82; i++)
					for (int j = 0; j < 62; j++)
						if (grid[xpos][ypos] == 1)
						{
							if (grid[i][j] == -1)
								grid[i][j] = 0;
							else
								grid[i][j] = 1;
						}
						else
						{
							if (grid[i][j] == -1)
								grid[i][j] = 0;
							else if (grid[i][j] == 2)
								grid[i][j] = 2;
							else
								grid[i][j] = 1;
						}

				//draw 
				window_play.clear();
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
						window_play.draw(Sgrid);
					}
				window_play.draw(player);
				window_play.draw(bound);
				for (int i = 1; i <= numberofenemy; i++) {
					window_play.draw(enemies_shapes[i]);
				}
				window_play.draw(time_text);
				window_play.draw(PercentText);
				window_play.display();
			}
			if (endgame)
			{
				break;
			}
		}
		if (page_number == 1)
		{
			//option
			RenderWindow window_option(VideoMode(ScreenWidth, ScreenHeight), "option");//render window_option 
			while (window_option.isOpen())
			{
				Event event;
				while (window_option.pollEvent(event))
				{
					if (event.type == Event::Closed)
						window.close();
					if (Keyboard::isKeyPressed(Keyboard::Escape))
						window_option.close();
				}
				window_option.clear();
				window_option.display();
			}
		}
		if (page_number == 2)
		{
			//exit
			break;
		}
	}
	return 0;
}

