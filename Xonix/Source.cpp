#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp> 
#include <iostream> // to use input and output functions 
#include <ctime> //to use time functions 
#include <sstream> 
#define ScreenWidth 820
#define ScreenHeight 620
#define Rows 82
#define Coulmns 62
 enum { Down, Up, Left, Right };
using namespace std;
using namespace sf;

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
int main(void)
{
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Xonix");//render window 
	window.setFramerateLimit(60);//set frames to 60 per second 
	bool play = true; // play variable 
	int xpos = 0, ypos = 0; //playes position
	short dir = -1;//direction of the player  -1 means no direction in the start it can be anything

	//images 
	Texture image;
	if (image.loadFromFile("borders.png") == false)
	{
		cout << "image is not here";
		return 1; // end the program 
	}
	Texture image2;
	if (image2.loadFromFile("borders1.png") == false)
	{
		cout << "image is not here";
		return 1; // end the program 
	}
	//font 
	Font number_font;
	if (number_font.loadFromFile("numbers_font.ttf") == false)
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
	Text time_text;
	time_text.setFont(number_font);
	time_text.setFillColor(Color::Red);
	time_text.setPosition(0, 640);
	time_text.setCharacterSize(20);
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
	SoundBuffer sound;
	Sound collisionSound;
	if (sound.loadFromFile("collision.wav"))  cout << "ERROR Loading sound: collision.wav ";
	collisionSound.setBuffer(sound);
	while (play)
	{
		Sprite Sgrid;
		for (int i = 0; i < 82; i++)
			for (int j = 0; j < 62; j++)
				if (i == 0 || i == 81 || j == 0 || j == 61 || i == 1 || i == 80 || j == 1 || j == 60)
					grid[i][j] = 1;
		// time string 
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
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
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
				play = false;
				//collisionSound.play();
				
			}
		}
		for (int i = 0; i < 82; i++)
			for (int j = 0; j < 62; j++)
				if (grid[i][j] == -1)
					grid[i][j] = 0;
				else  
					grid[i][j] = 1;

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
		for (int i = 1; i <= numberofenemy; i++) {
			window.draw(enemies_shapes[i]);
		}
		window.draw(time_text);
		window.display();
	}
}

