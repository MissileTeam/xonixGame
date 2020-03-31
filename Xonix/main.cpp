/*
 
using namespace std;
using namespace sf;
int main(void)
{
	int grid[82][62] = {};
	sf::RenderWindow window(sf::VideoMode(820, 680), "Xonix");//render window 
	window.setFramerateLimit(60);//set frames to 60 per second 
	bool play = true;
	bool top = false, down = false, right = false, left = false; //key pressed bools 
	bool tr = false, dr = false, rr = false, lr = false; //key realessed bools 
	bool MoveUp = false, MoveDown = false, MoveRight = false, MoveLeft = false;//move bools 
	int xpos = 0, ypos = 0; //playes position
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
	while (play)
	{
		Sprite Sgrid;
		// time string 
		for (int i = 0; i < 82; i++)
		{
			for (int j = 0; j < 62; j++)
			{
				if (i == 0 || i == 81 || j == 0 || j == 61 || i == 1 || i == 80 || j == 1 || j == 60)
				{
					grid[i][j] = 1;
				}
			}
		}
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
				down = false;
				right = false;
				left = false;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down)
			{
				down = true;
				right = false;
				left = false;
				top = false;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right)
			{
				right = true;
				left = false;
				top = false;
				down = false;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
			{
				left = true;
				right = false;
				top = false;
				down = false;
			}
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Up) {
				tr = true;
			}
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
			{
				dr = true;
			}
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Right)
			{
				rr = true;
			}
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Left)
			{
				lr = true;
			}
		}
		if (top == true)
		{
			MoveUp = true;
			MoveLeft = false;
			MoveDown = false;
			MoveRight = false;
		}
		else if (down == true)
		{
			MoveUp = false;
			MoveDown = true;
			MoveLeft = false;
			MoveRight = false;
		}
		else if (right == true)
		{
			MoveUp = false;
			MoveLeft = false;
			MoveRight = true;
			MoveDown = false;
		}
		else if (left == true)
		{
			MoveUp = false;
			MoveDown = false;
			MoveRight = false;
			MoveLeft = true;
		}
		// move 
		if (grid[xpos][ypos] != 1)
		{
			grid[xpos][ypos] = 2;
		}
		if (grid[xpos][ypos] == 1)
		{
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
				ypos -= 1;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down)
			{
				ypos += 1;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right)
			{
				xpos += 1;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
			{
				xpos -= 1;
			}
		}
		else {
			if (MoveUp == true)
			{
				ypos -= 1;
			}
			else if (MoveDown == true)
			{
				ypos += 1;
			}
			else if (MoveRight == true)
			{
				xpos += 1;
			}
			else if (MoveLeft == true)
			{
				xpos -= 1;
			}
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



/*


using namespace sf;
using namespace std;
#define ScreenWidth 400
#define ScreenHeight 400
bool coloring = false;
int xmarker = 20, ymarker = 0;
float lineWidth = 0, lineHeight = 0;
void fillGrid(float xmarker, float ymarker ,float &lineWidth,float&lineHeight) {
	if ( xmarker>30 &&ymarker>30) { coloring = true;

	cout << "in the range";

	}

	else
		coloring = false;

	if (coloring){ lineWidth = 20; lineHeight = -(ymarker - 20); }

	else { lineWidth = 0; lineHeight = 0; }

}
int main()
{
	bool Game = true;
	int moveSpeed = 5;
	float timer = 0, delay = 0.07;
	srand(time(0));

	RenderWindow window(VideoMode(ScreenWidth, ScreenHeight), "Xonix Game!");
	RectangleShape Rect(sf::Vector2f(ScreenWidth-50,ScreenHeight-50));
	RectangleShape filler(sf::Vector2f(lineWidth, lineHeight));
	RectangleShape marker(sf::Vector2f(20, 20));
	marker.setFillColor(sf::Color::Blue);
	filler.setFillColor(sf::Color::Magenta);
	Rect.setOutlineColor(sf::Color::Transparent);
	window.setFramerateLimit(60);
	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			if (e.type == Event::KeyPressed)
				if (e.key.code == Keyboard::Escape)
				{
					main();
				}

		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) xmarker -= moveSpeed;
		if (Keyboard::isKeyPressed(Keyboard::Right)) xmarker += moveSpeed;
		if (Keyboard::isKeyPressed(Keyboard::Up)) ymarker -= moveSpeed;
		if (Keyboard::isKeyPressed(Keyboard::Down)) ymarker += moveSpeed;
		window.clear();

		window.draw(Rect);

		window.draw(marker);
		Rect.setOrigin(10, 25);
		marker.setPosition(xmarker, ymarker);
		Rect.setPosition(30,50 );
		filler.setPosition(xmarker, ymarker);
		fillGrid(xmarker, ymarker,lineWidth,lineHeight);
		window.draw(filler);
		filler.setSize(sf::Vector2f(lineWidth,lineHeight));
		window.display();
	}
	return 0;
}
*/
///////////////////////// IGNORE This file :) 
/*
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;
enum {Down,Up,Right,Left};
#define ScreenWidth 400
#define ScreenHeight 400
# define Rows 30
#define Coulmns 30
//variables decleartion
int x = 0, y = 0,Width=0,Height=0; bool gameOver = false,area_range=false;
short dir = -1,movespeed=5;
void move_marker(int& x, int& y) {
	switch (dir)
	{
	case Up:
		y -= movespeed;
		break;
	case Down:
		y+=movespeed;
		break;
	case Right:
		x += movespeed;
		break;
	case Left:
		x -= movespeed;
		break;
	default:
		break;
	}

}

void fill_area(int x, int y) {
  if(x+10==50 || x+10<=300)



}
int main(void)
{
	//window decleartion:
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Xonix Game");
	window.setFramerateLimit(60);
	//Shapes declaration:
	RectangleShape marker(sf::Vector2f(10, 10));
	RectangleShape grid(sf::Vector2f(300, 300));
	RectangleShape area(sf::Vector2f(Width, Height));
	RectangleShape cells[Rows][Coulmns];
	area.setFillColor(sf::Color::Magenta);
	grid.setPosition(50, 50);
	grid.setFillColor(sf::Color::White);
	marker.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) { dir = Up; }
		else if (Keyboard::isKeyPressed(Keyboard::Down)) { dir = Down; }
		else if (Keyboard::isKeyPressed(Keyboard::Left)) { dir = Left; }
		 else if (Keyboard::isKeyPressed(Keyboard::Right)) { dir = Right; }
	 /*   if (x+10 >= ScreenWidth)
			x -= movespeed;
		else if (x < 0)
			x += movespeed;
		if (y >= ScreenHeight)
			y += movespeed;
		else if (y <= 0)
			y -= movespeed;
			// end of comment

		move_marker(x, y);
		window.draw(grid);
		window.draw(area);
		window.draw(marker);
		marker.setPosition(x, y);
		fill_area(x, y, Width, Height);
		area.setSize(Vector2f(Width, Height));
		area.setPosition(x, -y);
	   // area.setTextureRect(sf::IntRect(x, y, 10, 10));



		//draw

		window.display();
		window.clear();

	}
}




*/

/*

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp> 
#include <iostream> // to use input and output functions 
#include <ctime> //to use time functions 
#include <sstream> 
using namespace std;
using namespace sf;
enum { Down, Up, Left, Right }; // 0 is called down and 1 is called up and so on 
int main(void)
{
	int grid[82][62] = {};
	sf::RenderWindow window(sf::VideoMode(820, 680), "Xonix");//render window 
	window.setFramerateLimit(60);//set frames to 60 per second 
	bool play = true;

	int xpos = 0, ypos = 0; //playes position
	short dir = -1;//direction of the player  -1 means no direction in the start it can be anything

	//Adding images:
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
	// Adding font 
	Font number_font;
	if (number_font.loadFromFile("numbers_font.ttf") == false)
	{
		cout << "font is not here";
		return 1; // end the program 
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
	player.setPosition(400, 300);
	player.setSize(Vector2f(10, 10));
	//under bound rectangle 
	RectangleShape bound;
	bound.setFillColor(Color::Red);
	bound.setPosition(0, 620);
	bound.setSize(Vector2f(820, 5));
	// event
	Event event;
	while (play)
	{
		Sprite Sgrid;
		// time string 
		for (int i = 0; i < 82; i++)
		{
			for (int j = 0; j < 62; j++)
			{
				if (i == 0 || i == 81 || j == 0 || j == 61 || i == 1 || i == 80 || j == 1 || j == 60)
				{
					grid[i][j] = 1;
				}
			}
		}
		//
		stringstream time_string;
		time(&this_second);
		if (second < 60)   second = this_second - first_second;

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
			if (Keyboard::isKeyPressed(Keyboard::Up))				dir = Up;

			else if (Keyboard::isKeyPressed(Keyboard::Down))		dir = Down;

			else if (Keyboard::isKeyPressed(Keyboard::Right))		dir = Right;

			else if (Keyboard::isKeyPressed(Keyboard::Left))		dir = Left;

		}

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
		else {
			if (dir == Up)	ypos -= 1;

			else if (dir == Down)	ypos += 1;

			else if (dir == Right)	xpos += 1;

			else if (dir == Left)	xpos -= 1;

		}
		// bound moving
		if (xpos >= 82) xpos -= 1;

		if (xpos < 0)	xpos += 1;

		if (ypos >= 62)	ypos -= 1;

		if (ypos < 0)	ypos += 1;

		player.setPosition(xpos * 10, ypos * 10);
		time_text.setString(time_string.str());
		//draw 
		window.clear();
		for (int i = 0; i < 82; i++)
			for (int j = 0; j < 62; j++)
			{
				if (grid[i][j] == 0) continue;

				if (grid[i][j] == 1) Sgrid.setTexture(image2);

				if (grid[i][j] == 2) Sgrid.setTexture(image);

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

