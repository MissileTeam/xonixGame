#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp> 
#include <iostream> // to use input and output functions 
#include <ctime> //to use time functions 
#include <sstream> 
#include "menu.h"   //call class of menu
#include <chrono>
#include <thread>
#include "levels.h"
#define ScreenWidth 820
#define ScreenHeight 680
#define Rows 82
#define Coulmns 62
int  page_number = -1;
int  level_number = -1;
int grid[Rows][Coulmns] = {};

enum { Down, Up, Left, Right };
using namespace std;
using namespace sf;
  //tell me i did selelction to which window
//global varibles
 // window scale 
struct enemy {
	//e=enemy
	// we put the function in the struct to make varibles of struct idientfied in the functions
	short expostion, eypostion, exvelocity, eyvelocity;
	enemy() {
		expostion =400-rand()%100;
		eypostion = 400-rand()%50;
		
		exvelocity = 1 - rand() % 10;
		if (exvelocity == 0)
			exvelocity = 1 - rand() % 10;
		eyvelocity =1 - rand() % 10;
		if (eyvelocity == 0)
		eyvelocity = 1 - rand() % 10;
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
// Function to check the area around enemies and set it to (-1) and check the area to be  filled which is (0) bounded by (2) in the matrix which is player lines

void movePlayer(int &xpos,int &ypos,int dir)
{
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

	//check_bounderies
	if (xpos >= 82)
		xpos -= 1;
	else if (xpos < 0)
		xpos += 1;
	if (ypos >= 62)
		ypos -= 1;
	else if (ypos < 0)
		ypos += 1;

}
void rules_of_draw(int x, int y)
{
	if (grid[x][y] == 0)
	
		grid[x][y] = -1; //strange error happens here becuase the random position of the enemy  y =- number;

	if (grid[x - 1][y] == 0)

		rules_of_draw(x - 1, y);

	if (grid[x + 1][y] == 0)

		rules_of_draw(x + 1, y);

	if (grid[x][y + 1] == 0)

		rules_of_draw(x, y + 1);

	if (grid[x][y - 1] == 0)

		rules_of_draw(x, y - 1);

}
void moveEnemy(int numberofenemy)
{
	
	for (int i = 0; i < numberofenemy; i++) {
		enemies_struct[i].motion();
		rules_of_draw(enemies_struct[i].expostion / 10, enemies_struct[i].eypostion / 10);
	}
}
void setsBrush(int& xpos, int& ypos)
{
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
}
void drawArea(Sprite& Sgrid, RenderWindow& window,Texture & image,Texture &image2)
{
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

}
int checkBoundaries()
{
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
	return percent;
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
			while (true)   //this move on all levels
			{
				//play levels
				RenderWindow window_Levels(VideoMode(ScreenWidth, ScreenHeight), "Levels");//render window_play 
				levels Levels(ScreenWidth, ScreenHeight);  //to take object from class  
				while (window_Levels.isOpen())
				{
					Event event2;
					while (window_Levels.pollEvent(event2))
					{
						if (event2.type == Event::Closed)
							window_Levels.close();

						if (event2.type == Event::KeyReleased)
						{
							if (event2.key.code == Keyboard::Up)
							{
								Levels.moveup();
								break;
							}
							if (event2.key.code == Keyboard::Down)
							{
								Levels.moveDown();
								break;
							}
						}

						//choose page
						if (event2.key.code == Keyboard::Enter)   // Return == I pressed enter
						{
							if (Levels.mainlevelsPressed() == 0)    //  level 1
							{
								window_Levels.close();				//close the main window and open window.1
								level_number = 0;
							}
							if (Levels.mainlevelsPressed() == 1)    //  level 2
							{
								window_Levels.close();				//close the main window and open window.2
								level_number = 1;

							}
							if (Levels.mainlevelsPressed() == 2)    //  level 3
							{
								window_Levels.close();				//close the main window and open window.3
								level_number = 2;
							}
						}
					}

					window_Levels.clear();
					Levels.draw(window_Levels);
					window_Levels.display();
				}
				if (level_number == 0)
				{
					 

					//level one  --- 
					//nested loop to set grid to 0
					for (int i = 0; i < Rows; i++)
						for (int j = 0; j < Coulmns; j++)
							grid[i][j] = 0;
					short nEnemy = 4;//number of enemy of selected level
										//level one  
					RenderWindow window_Level_one(VideoMode(ScreenWidth, ScreenHeight), "play");//render window_play 
					window_Level_one.setFramerateLimit(30);//set frames to 60 per second 
					bool play = true, endgame = false;; // play variable 
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
					RectangleShape enemies_shapes[10];
					for (int i = 0; i < nEnemy; i++) {
						enemies_shapes[i].setSize(Vector2f(10, 10));
						enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
						enemies_shapes[i].setFillColor(Color::Red);//Se7aaaaaaaaaa
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
						percent = checkBoundaries() / (44);
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
						while (window_Level_one.pollEvent(event))
						{
							if (event.type == Event::Closed)
							{
								window_Level_one.close();
								play = false;
								//endgame = true;
							}
							if (Keyboard::isKeyPressed(Keyboard::Escape))
							{
								play = false;
							}
							if (Keyboard::isKeyPressed(Keyboard::Up)) 		dir = Up;
							else if (Keyboard::isKeyPressed(Keyboard::Down))	dir = Down;
							else if (Keyboard::isKeyPressed(Keyboard::Right))	dir = Right;
							else if (Keyboard::isKeyPressed(Keyboard::Left))	dir = Left;
							for (int l = 0; l < nEnemy; l++)
							{
								for (int k = 1; k < nEnemy; k++)
									if (enemies_shapes[l].getGlobalBounds().intersects(enemies_shapes[k].getGlobalBounds()))
									{
										enemies_struct[l].expostion = -enemies_struct[l].expostion;
										enemies_struct[l].eypostion = -enemies_struct[l].eypostion;
										enemies_struct[k].expostion = -enemies_struct[k].expostion;
										enemies_struct[k].eypostion = -enemies_struct[k].eypostion;
									}
							}
						}
						//enemy move
					//	moveEnemy(nEnemy); activate it when you want to cut pieces of the pink line and remove it below :)
						// boundaries that anything can't go after it like player
						//player movement in the Grid 
						movePlayer(xpos, ypos, dir);
						player.setPosition(xpos * 10, ypos * 10);
						time_text.setString(time_string.str());
						for (int i = 0; i < nEnemy; i++)
						{
							enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
						}
						for (int i = 0; i < nEnemy; i++)
						{
							if (grid[enemies_struct[i].expostion / 10][enemies_struct[i].eypostion / 10] == 2)
							{
								collisionSound.play();
								this_thread::sleep_for(.2s);
								for(int i=0;i<82;i++)
									for(int j=0;j<62;j++ )
										if(grid[i][j]==2)
											grid[i][j] = 0;
								
								//play = false;
							}
						}
						moveEnemy(nEnemy);

						for (int i = 0; i < 82; i++)
						{
							for (int j = 0; j < 62; j++)
							{
								if (player.getPosition().x == grid[i][j] == 2 || player.getPosition().y == grid[i][j] == 2)
									play = false;
							}
						}
						setsBrush(xpos, ypos);
						//draw 
						window_Level_one.clear();
						drawArea(Sgrid, window_Level_one, image, image2);
						window_Level_one.draw(player);
						window_Level_one.draw(bound);
						for (int i = 0; i < nEnemy; i++) {
							window_Level_one.draw(enemies_shapes[i]);
						}
						window_Level_one.draw(time_text);
						window_Level_one.draw(PercentText);
						window_Level_one.display();
					}

				}
				if (level_number == 1)
				{
					//level two 
					//nested loop to set grid to 0
					for (int i = 0; i < Rows; i++)
						for (int j = 0; j < Coulmns; j++)
							grid[i][j] = 0;
					short nEnemy = 6;//number of enemy of selected level
				//level one  
					RenderWindow window_Level_one(VideoMode(ScreenWidth, ScreenHeight), "play");//render window_play 
					window_Level_one.setFramerateLimit(30);//set frames to 60 per second 
					bool play = true, endgame = false;; // play variable 
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
					RectangleShape enemies_shapes[10];
					for (int i = 0; i < nEnemy; i++) {
						enemies_shapes[i].setSize(Vector2f(20, 20));
						enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
						enemies_shapes[i].setFillColor(Color::Yellow);//Se7aaaaaaaaaa
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
						percent = checkBoundaries() / (44);
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
						while (window_Level_one.pollEvent(event))
						{
							if (event.type == Event::Closed)
							{
								window_Level_one.close();
								play = false;
								//endgame = true;
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
						moveEnemy(nEnemy);
						// boundaries that anything can't go after it like player
						//player movement in the Grid 
						movePlayer(xpos, ypos, dir);
						player.setPosition(xpos * 10, ypos * 10);
						time_text.setString(time_string.str());
						for (int i = 0; i < nEnemy; i++)
						{
							enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
						}
						for (int i = 0; i < nEnemy; i++)
						{
							if (grid[enemies_struct[i].expostion / 10][enemies_struct[i].eypostion / 10] == 2)
							{
								collisionSound.play();
								this_thread::sleep_for(.2s);


								play = false;

							}
							for (int i = 0; i < 82; i++)
							{
								for (int j = 0; j < 62; j++)
								{
									if (player.getPosition().x == grid[i][j] == 2 || player.getPosition().y == grid[i][j] == 2)
										play = false;
								}
							}
						}
						setsBrush(xpos, ypos);
						//draw 
						window_Level_one.clear();
						drawArea(Sgrid, window_Level_one, image, image2);
						window_Level_one.draw(player);
						window_Level_one.draw(bound);
						for (int i = 0; i < nEnemy; i++) {
							window_Level_one.draw(enemies_shapes[i]);
						}
						window_Level_one.draw(time_text);
						window_Level_one.draw(PercentText);
						window_Level_one.display();
					}
				}
				if (level_number == 2)
				{
					//nested loop to set grid to 0
					for (int i = 0; i < Rows; i++)
						for (int j = 0; j < Coulmns; j++)
							grid[i][j] = 0;
					short nEnemy = 4;//number of enemy of selected level
										//level one  
					RenderWindow window_Level_one(VideoMode(ScreenWidth, ScreenHeight), "play");//render window_play 
					window_Level_one.setFramerateLimit(30);//set frames to 60 per second 
					bool play = true, endgame = false;; // play variable 
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
					RectangleShape enemies_shapes[10];
					for (int i = 0; i < nEnemy; i++) {
						enemies_shapes[i].setSize(Vector2f(20, 20));
						enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
						enemies_shapes[i].setFillColor(Color::Yellow);//Se7aaaaaaaaaa
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
						percent = checkBoundaries() / (44);
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
						while (window_Level_one.pollEvent(event))
						{
							if (event.type == Event::Closed)
							{
								window_Level_one.close();
								play = false;
								//endgame = true;
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
						moveEnemy(nEnemy);
						// boundaries that anything can't go after it like player
						//player movement in the Grid 
						movePlayer(xpos, ypos, dir);
						player.setPosition(xpos * 10, ypos * 10);
						time_text.setString(time_string.str());
						for (int i = 0; i < nEnemy; i++)
						{
							enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
						}
						for (int i = 0; i < nEnemy; i++)
						{
							if (grid[enemies_struct[i].expostion / 10][enemies_struct[i].eypostion / 10] == 2)
							{
								collisionSound.play();
								this_thread::sleep_for(.2s);


								play = false;

							}
							for (int i = 0; i < 82; i++)
							{
								for (int j = 0; j < 62; j++)
								{
									if (player.getPosition().x == grid[i][j] == 2 || player.getPosition().y == grid[i][j] == 2)
										play = false;
								}
							}
						}
						setsBrush(xpos, ypos);
						//draw 
						window_Level_one.clear();
						drawArea(Sgrid, window_Level_one, image, image2);
						window_Level_one.draw(player);
						window_Level_one.draw(bound);
						for (int i = 0; i < nEnemy; i++) {
							window_Level_one.draw(enemies_shapes[i]);
						}
						window_Level_one.draw(time_text);
						window_Level_one.draw(PercentText);
						window_Level_one.display();
					}
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
}

