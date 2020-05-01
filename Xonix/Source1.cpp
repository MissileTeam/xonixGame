//#include <SFML/Graphics.hpp>
//#include<SFML/Audio.hpp> 
//#include <iostream> // to use input and output functions 
//#include <ctime> //to use time functions 
//#include <sstream> 
//#include "menu.h"   //call class of menu
//#include <chrono>
//#include <thread>
//#include "levels.h"
//#include "messagebox.h"
//#include "Custom.h"
//#include "FilesHandler.h"
//#include <string>
//#define ScreenWidth 820
//#define ScreenHeight 680
//#define messageWidth 300
//#define messageHeight 350
//#define Rows 82
//#define Coulmns 62
//string* name;
//bool defaultmode = false, replay = false;
//int  page_number = -1;
//int  level_number = 0;
//int Clevel_number = -1;
//std::string playername = "Player'sName: ";
//int score = 0; short heart = 3;
//int page_Custom = 0;
//short grid[Rows][Coulmns] = {};
//bool start = 0;
//enum { Down, Up, Left, Right };
//using namespace std;
//using namespace sf;
////tell me i did selelction to which window
////global varibles
//// window scale 
//stringstream sscore; Text labelscore;
//struct enemy {
//	//e=enemy
//	// we put the function in the struct to make varibles of struct idientfied in the functions
//	short expostion, eypostion, exvelocity, eyvelocity;
//	enemy() {
//		expostion = 400 - rand() % 50;
//		eypostion = 400 - rand() % 50;
//
//		exvelocity = 1 - rand() % 10;
//		if (exvelocity == 0)
//			exvelocity = 1 - rand() % 10;
//		eyvelocity = 1 - rand() % 10;
//		if (eyvelocity == 0)
//			eyvelocity = 1 - rand() % 10;
//	}
//	void motion() {
//		expostion += exvelocity;
//		if (grid[expostion / 10][eypostion / 10] == 1) {
//			exvelocity = -exvelocity;
//			expostion += exvelocity;
//		}
//		eypostion += eyvelocity;
//		if (grid[expostion / 10][eypostion / 10] == 1) {
//			eyvelocity = -eyvelocity;
//			eypostion += eyvelocity;
//		}
//
//	}
//}enemies_struct[10];
//// Function to check the area around enemies and set it to (-1) and check the area to be  filled which is (0) bounded by (2) in the matrix which is player lines
//void calculateScore(int& minute, int& seconds, int& percent)
//{
//	FilesHandler scores;
//	score = score / 44;
//
//	do {
//
//		if ((seconds < 40) || (heart == 3) && (percent >= 20))
//		{
//
//			score = score + (score * 25 / 100);
//
//			scores.writeScore(score, score, "Level 1 : ");
//			cout << "You hit new score" << endl;
//			break;
//		}
//		else
//			break;
//
//	} while (true);
//
//
//
//
//	sscore.str("");
//	sscore << "Score:" << score;
//	labelscore.setString(sscore.str());
//}
//void setTime(time_t& this_second, int& second, int& minute, time_t& first_second, stringstream& time_string)
//{
//	time(&this_second);
//	if (second < 60)
//	{
//
//		second = this_second - first_second;
//	}
//	else if (second % 60 == 0)
//	{
//		minute++;
//		time(&first_second);
//		second = 0;
//	}
//	if (minute < 10)
//	{
//		if ((second) < 10)
//		{
//			time_string.clear();
//			time_string << "Time " << "0" << minute << " : " << "0" << second;
//		}
//		else
//		{
//			time_string.clear();
//			time_string << "Time " << "0" << minute << " : " << second;
//		}
//	}
//	else
//	{
//		if ((this_second - first_second) < 10)
//		{
//			time_string.clear();
//			time_string << "Time " << minute << " : " << "0" << second;
//		}
//		else
//		{
//			time_string.clear();
//			time_string << "Time " << minute << " : " << second;
//		}
//	}
//}
//void setTimeText(Font& number_font, Text& time_text)
//{
//	time_text.setFont(number_font);
//	time_text.setFillColor(Color::Red);
//	time_text.setPosition(0, 640);
//	time_text.setCharacterSize(20);
//}
//void setHeartText(Font& Arial_font, Text& heartText)
//{
//	heartText.setFont(Arial_font);
//	heartText.setFillColor(Color::Green);
//	heartText.setPosition((ScreenWidth / 3), 633);
//	heartText.setCharacterSize(30);
//}
//void setPercentText(Font& Arial_font, Text& PercentText)
//{
//	PercentText.setFont(Arial_font);
//	PercentText.setFillColor(Color::Green);
//	PercentText.setPosition(370, 630);
//	PercentText.setCharacterSize(30);
//}
//void setEnemiesShapes(short& nEnemy, RectangleShape enemies_shapes[])
//{
//	for (int i = 0; i < nEnemy; i++) {
//		enemies_shapes[i].setSize(Vector2f(10, 10));
//		enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
//		enemies_shapes[i].setFillColor(Color::Red);
//	}
//}
//void set_grid_0();
//void setScoreText(Font& Arial_font)
//{
//	score = 0;
//	sscore << "Score : " << score;
//	labelscore.setCharacterSize(20);
//	labelscore.setPosition({ 30, 50 });
//	labelscore.setFont(Arial_font);
//	labelscore.setString(sscore.str());
//	labelscore.setFillColor(Color::Green);
//
//
//}
//void updateScore()
//{
//
//}
//void win(RenderWindow& window)
//{
//	Font Arial_font, font;
//	Text wintext, scoretext, nametext;
//	if (Arial_font.loadFromFile("Data/menu.ttf") == false)
//		wintext.setFont(Arial_font);
//	wintext.setFillColor(Color::Green);
//	wintext.setPosition(400, 250);
//	wintext.setCharacterSize(100);
//	if (font.loadFromFile("Data/levels.ttf") == false)
//		scoretext.setFont(font);
//	scoretext.setFillColor(Color::Green);
//	scoretext.setPosition(400, 400);
//	scoretext.setCharacterSize(60);
//	if (font.loadFromFile("Data/levels.ttf") == false)
//		nametext.setFont(font);
//	nametext.setFillColor(Color::Green);
//	nametext.setPosition(400, 470);
//	nametext.setCharacterSize(60);
//
//	stringstream  winString, scoreString, nameString;
//	nameString << playername;
//	nametext.setString(nameString.str());
//	scoreString << "your score :: ";
//	scoretext.setString(scoreString.str());
//	winString << "WIN";
//	wintext.setString(winString.str());
//	window.clear();
//	window.draw(wintext);
//	window.draw(scoretext);
//	window.draw(nametext);
//	window.display();
//}
//void player_rectangle(RectangleShape& player);
//void reply_level(bool play, Music& music, int& xpos, int& ypos)
//{
//	if (heart == 0)
//	{
//		//scores.writeScore(score, highscore, "Level one : ");
//		FilesHandler scores;
//
//		scores.writeScore(score, score, "Level 1 : ");
//		RenderWindow message(VideoMode(messageWidth, messageHeight), "message", Style::Close);
//		messagebox  Message(messageWidth, messageHeight);
//		Texture background;
//		if (!background.loadFromFile("Data/gameover.png")) {}
//		RectangleShape photo;
//		photo.setSize(Vector2f(300, 100));
//		photo.setPosition(0, 0);
//		photo.setTexture(&background);
//		while (message.isOpen())
//		{
//			Event event;
//			while (message.pollEvent(event))
//			{
//				if (event.type == Event::Closed)
//					message.close();
//				if (event.type == Event::KeyReleased)
//				{
//					if (event.key.code == Keyboard::Left)
//					{
//						Message.moveLeft();
//						break;
//					}
//					if (event.key.code == Keyboard::Right)
//					{
//						Message.moveRight();
//						break;
//					}
//				}
//				//choose decision
//				if (event.key.code == Keyboard::Return)   // Return == I pressed enter
//				{
//					if (Message.messagePressed() == 0)    //  yes
//					{
//						message.close();//close the main window and open window.play
//						//window_Level_one.close();
//						music.stop();                //closing window level to open new one
//						play = true;
//						replay = true;
//						break;
//
//					}
//					if (Message.messagePressed() == 1)    //  no
//					{
//						message.close();				//close the main window and open window.credits
//						play = false;
//						replay = false;
//					}
//				}
//			}
//			message.clear();
//			message.draw(photo);
//			Message.draw(message);
//			message.display();
//		}
//		if (replay == true)
//		{
//			heart = 3;
//			xpos, ypos = 0;
//			message.close();
//			replay = false;
//			set_grid_0();
//			music.play();
//			//break;
//		}
//	}
//}
//void checkCollision(short nEnemy, RectangleShape enemies_shapes[], Sound collisionSound)
//{
//	for (int i = 0; i < nEnemy; i++)
//	{
//		enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
//
//
//		if (grid[enemies_struct[i].expostion / 10][enemies_struct[i].eypostion / 10] == 2)
//		{
//			heart--;
//			collisionSound.play();
//			//make the enemy destroy your line "Nice"
//			//grid[enemies_struct[i].expostion / 10][enemies_struct[i].eypostion / 10] = -1;
//			//this_thread::sleep_for(.2s);
//			for (int i = 0; i < 82; i++)
//				for (int j = 0; j < 62; j++)
//					if (grid[i][j] == 2)
//						grid[i][j] = -1;
//
//			//play = false;
//		}
//	}
//}
//void movePlayer(int& xpos, int& ypos, int dir)
//{
//	if (grid[xpos][ypos] != 1)
//	{
//		grid[xpos][ypos] = 2;
//	}
//	if (grid[xpos][ypos] == 1)
//	{
//		if (Keyboard::isKeyPressed(Keyboard::Up))				ypos -= 1;
//
//		else if (Keyboard::isKeyPressed(Keyboard::Down))		ypos += 1;
//
//		else if (Keyboard::isKeyPressed(Keyboard::Right))		xpos += 1;
//
//		else if (Keyboard::isKeyPressed(Keyboard::Left))		xpos -= 1;
//	}
//	else
//	{
//		if (dir == Up)	ypos -= 1;
//
//		else if (dir == Down)	ypos += 1;
//
//		else if (dir == Right)	xpos += 1;
//
//		else if (dir == Left)	xpos -= 1;
//	}
//
//	//check_bounderies
//	if (xpos >= 82)
//		xpos -= 1;
//	else if (xpos < 0)
//		xpos += 1;
//	if (ypos >= 62)
//		ypos -= 1;
//	else if (ypos < 0)
//		ypos += 1;
//
//}
//void rules_of_draw(int x, int y)
//{
//
//	if (grid[x][y] == 0)
//
//		grid[x][y] = -1; //strange error happens here becuase the random position of the enemy  y =- number;
//
//	if (grid[x - 1][y] == 0)
//
//		rules_of_draw(x - 1, y);
//
//	if (grid[x + 1][y] == 0)
//
//		rules_of_draw(x + 1, y);
//
//	if (grid[x][y + 1] == 0)
//
//		rules_of_draw(x, y + 1);
//
//	if (grid[x][y - 1] == 0)
//
//		rules_of_draw(x, y - 1);
//
//}
//void moveEnemy(int numberofenemy)
//{
//
//	for (int i = 0; i < numberofenemy; i++) {
//		enemies_struct[i].motion();
//		rules_of_draw(enemies_struct[i].expostion / 10, enemies_struct[i].eypostion / 10);
//	}
//}
//void setsBrush(int& xpos, int& ypos)
//{
//
//	for (int i = 0; i < 82; i++)
//		for (int j = 0; j < 62; j++)
//		{
//			/*if (grid[i][j] == 3)
//			grid[i][j] = 3;*/
//
//			if (grid[xpos][ypos] == 1)
//			{
//
//				if (grid[i][j] == -1)
//					grid[i][j] = 0;
//				else if (grid[i][j] == 3)
//					grid[i][j] = 3;
//				else
//					grid[i][j] = 1;
//
//
//			}
//			else
//			{
//				if (grid[i][j] == -1)
//					grid[i][j] = 0;
//
//				else if (grid[i][j] == 2)
//					grid[i][j] = 2;
//				else if (grid[i][j] == 3)///new thing to add
//					grid[i][j] = 3;
//				else if (grid[i][j] == 0)
//					grid[i][j] = 1;
//			}
//		}
//
//}
//void drawArea(Sprite& Sgrid, RenderWindow& window, Texture& image, Texture& image2)
//{
//	Sgrid.setOrigin(5, 5);
//	for (int i = 0; i < 82; i++)
//		for (int j = 0; j < 62; j++)
//		{
//
//			if (grid[i][j] == 0)
//			{
//				continue;
//			}
//			if (grid[i][j] == 1)
//			{
//				Sgrid.setColor(Color::White);
//
//				Sgrid.setTexture(image2);
//			}
//			if (grid[i][j] == 2)
//			{
//				Sgrid.setColor(Color::White);
//
//				Sgrid.setTexture(image);
//			}
//			if (grid[i][j] == 3)
//			{
//				Sgrid.setColor(Color::Yellow);
//				Sgrid.setTexture(image);
//			}
//			Sgrid.setPosition(i * 10, j * 10);
//
//			window.draw(Sgrid);
//
//		}
//}
//int checkBoundaries()
//{
//	int percent = 0;
//	for (int i = 0; i < 82; i++)
//	{
//		for (int j = 0; j < 62; j++)
//		{
//			if (i == 0 || i == 81 || j == 0 || j == 61 || i == 1 || i == 80 || j == 1 || j == 60)
//			{
//				grid[i][j] = 1;
//			}
//			else if (grid[i][j] == 1)
//			{
//				percent++;
//				score++;
//			}
//
//		}
//	}
//	return percent;
//}
//void check_images_borders_load(Texture& image, Texture& image2, Texture& image3);
//
//void check_font_load(Font& number_font, Font& Arial_font);
//
//
//void part_level_one(int number_level);
//
//void part_level_two(int number_level);
//
//void part_level_three(int number_level);
//void part_level_four(int level_number);
//void part_level_five(int level_number);
//void part_level_six(int level_number);
//void part_level_seven(int level_number);
//void part_level_eight(int level_number);
//void Custom_make_level(int page_Custom);
//
//void part_level_Custom(int& level_number, string* name);
//
////int Custom_load_levels(int page_Custom);
//void part_play(int page_number);
//
//void part_Credits(int page_number);
//void part_option(int page_number);
//void load_custom_level(int& CLevelnumber, string& levelgrid, FilesHandler& levelsFile);
////int entername()
////{
////	RenderWindow window2(VideoMode(300, 300), "X_onix", Style::None);
////	Event event;
////	Font font;
////	if (!font.loadFromFile("Data/arial.ttf"))
////		return EXIT_FAILURE;
////
////	String   playername;
////	Text playertext("", font, size);
////	playertext.setPosition(Vector2f(10, 10));
////	playertext.setFillColor(Color::Green);
////	while (window2.isOpen())
////	{
////		while (window2.pollEvent(event))
////		{
////			if (event.type == Event::TextEntered)
////			{
////				if (event.text.unicode < 128)
////				{
////					playername +=event.text.unicode;
////					playertext.setString(playername);
////
////				}
////			}
////			
////		}
////		window2.clear();
////		window2.draw(playertext);
////		window2.display();
////	}
////	return 0;
////}
//int main()
//{
//	bool end_levels = true, end_levels_2 = true;
//	while (true)   //this move on all pages
//	{
//
//		RenderWindow window(VideoMode(ScreenWidth, ScreenHeight), "Xonix", Style::Close);//render window 
//		menu menuu(ScreenWidth, ScreenHeight);  //to take object from class 
//
//		Font font;
//		if (!font.loadFromFile("Data/arial.ttf"))
//			return EXIT_FAILURE;
//		Text t;
//		t.setFillColor(Color::White);
//		t.setFont(font);
//
//		t.setString(playername);
//
//
//		//background of game 
//		Texture background;
//		if (!background.loadFromFile("Data/picture6.png"))
//			cout << "error in load photo of shape" << endl;
//		RectangleShape photo;
//		photo.setSize(Vector2f(820, 680));
//		photo.setPosition(0, 0);
//		photo.setTexture(&background);
//		Texture logo;
//		if (!logo.loadFromFile("Data/enemy.png"))
//			cout << "error in load photo of shape" << endl;
//		RectangleShape photo2;
//		photo2.setSize(Vector2f(50, 50));
//		photo2.setPosition(760, 580);
//		photo2.setTexture(&logo);
//		while (window.isOpen())
//		{
//			Event event;
//			while (window.pollEvent(event))
//			{
//				if (event.type == Event::Closed)
//					window.close();
//				if (event.type == Event::TextEntered) {
//					//s.append(std::to_string(event.key.code));
//					if (event.text.unicode < 128 && event.text.unicode != 8)
//					{
//						playername += static_cast<char>(event.text.unicode);
//					}
//					else if (event.text.unicode == 8)
//					{
//						//s += static_cast<char>(event.text.unicode);
//						playername.erase(playername.end() - 1);
//					}
//
//				}
//				if (event.type == Event::KeyReleased)
//				{
//					if (event.key.code == Keyboard::Up)
//					{
//						menuu.moveup();
//						break;
//					}
//					if (event.key.code == Keyboard::Down)
//					{
//						menuu.moveDown();
//						break;
//					}
//				}
//				//choose page
//				if (event.key.code == Keyboard::Return)   // Return == I pressed enter
//				{
//					if (menuu.mainmenuPressed() == 0)    //  play
//					{
//						window.close();				//close the main window and open window.play
//						page_number = 0;
//					}
//					if (menuu.mainmenuPressed() == 1)    //  credits
//					{
//						window.close();				//close the main window and open window.credits
//						page_number = 1;
//
//					}
//					if (menuu.mainmenuPressed() == 2)    //  options
//					{
//						window.close();				//close the main window and open window.option
//						page_number = 2;
//
//					}
//					if (menuu.mainmenuPressed() == 3)    //  exit
//					{
//						window.close();				//close the main window and open window.exit
//						page_number = 3;
//					}
//				}
//			}
//			switch (event.type)
//			{
//			case Event::MouseButtonPressed:
//				switch (event.mouseButton.button)
//				{
//				case Mouse::Button::Left:
//					if (event.mouseButton.x >= 760 && event.mouseButton.x <= 805 && event.mouseButton.y >= 580 && event.mouseButton.y <= 626)
//					{
//						defaultmode = true;
//					}
//					break;
//				}
//				break;
//			}
//
//			t.setString(playername);
//			window.clear();
//
//			window.draw(photo);
//			window.draw(photo2);
//			menuu.draw(window);
//			window.draw(t);
//			window.display();
//			//entername();
//		}
//
//		part_play(page_number);
//		if (end_levels == false)
//			continue;
//		if (end_levels_2 == false)
//			continue;
//		part_Credits(page_number);
//		part_option(page_number);
//		if (page_number == 3)
//			break; // exit
//
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//void part_level_one(int number_level)
//{
//	if (level_number == 0)
//	{
//
//		heart = 3;
//		//score system
//		int highscore = 20;
//
//		//level one  --- 
//		//set_grid_0();
//		short nEnemy = 4;//number of enemy of selected level
//		//level one  
//		RenderWindow window_Level_one(VideoMode(ScreenWidth, ScreenHeight), "level one", Style::Close);//render window_play 
//		window_Level_one.setFramerateLimit(30);//set frames to 60 per second 
//		bool play = true;// play variable 
//
//		int xpos = 0, ypos = 0; //playes position
//		short dir = -1;//direction of the player  -1 means no direction in the start it can be anything
//
//		//images 
//		Texture image, image2, image3;
//		check_images_borders_load(image, image2, image3);
//		Sprite  sprite3(image3);
//		sprite3.setPosition(Vector2f((ScreenWidth / 3 - 50), 633));
//		//font 
//		Font number_font, Arial_font;
//		check_font_load(number_font, Arial_font);
//		setScoreText(Arial_font);
//
//		RectangleShape enemies_shapes[10];
//		setEnemiesShapes(nEnemy, enemies_shapes);
//		// time 
//		time_t first_second, this_second;
//		time(&first_second);
//		int second = 0, minute = 0;
//		//time text
//		Text time_text, PercentText, heartText, nametext;
//		if (Arial_font.loadFromFile("Data/arial.ttf") == false)
//			std::cout << "erorr in loading Font";
//		nametext.setFont(Arial_font);
//		nametext.setFillColor(Color::Green);
//		nametext.setPosition(570, 630);
//		nametext.setCharacterSize(30);
//		setTimeText(number_font, time_text);
//		//Percent Text
//		setPercentText(Arial_font, PercentText);
//		//heart Text
//		setHeartText(Arial_font, heartText);
//		//player rectangle
//		RectangleShape player;
//		player_rectangle(player);
//		//under bound rectangle 
//		RectangleShape bound;
//		bound.setFillColor(Color::Red);
//		bound.setPosition(0, 620);
//		bound.setSize(Vector2f(820, 5));
//		// event
//		Event event;
//		//sound
//		// sound track while the game is playing
//		Music music;
//		if (!music.openFromFile("Data/soundtrack.ogg"))
//			cout << "error in load sound";
//		music.play();
//		SoundBuffer sound;
//		Sound collisionSound;
//		if (sound.loadFromFile("Data/impact.wav"))
//			cout << "collision done " << endl;
//		collisionSound.setBuffer(sound);
//
//		while (play)     //this move one page
//		{
//
//			Sprite Sgrid;
//			int percent = 0;
//			percent = checkBoundaries() / (44);
//			updateScore();
//			calculateScore(minute, second, percent);
//
//			// time string 
//			stringstream time_string, areaString, heartString, nameString;
//			nameString << playername;
//			nametext.setString(nameString.str());
//			heartString << heart;
//			heartText.setString(heartString.str());
//			areaString << "You Finished " << percent << "%";
//			PercentText.setString(areaString.str());
//			//setting time 
//			setTime(this_second, second, minute, first_second, time_string);
//
//			while (window_Level_one.pollEvent(event))
//			{
//				if (event.type == Event::Closed)
//				{
//					window_Level_one.close();
//					start = 0;
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Escape))
//				{
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Up)) 		dir = Up;
//				else if (Keyboard::isKeyPressed(Keyboard::Down))	dir = Down;
//				else if (Keyboard::isKeyPressed(Keyboard::Right))	dir = Right;
//				else if (Keyboard::isKeyPressed(Keyboard::Left))	dir = Left;
//				/*	for (int l = 0; l < nEnemy; l++)
//				{
//				for (int k = 1; k < nEnemy; k++)
//				if (enemies_shapes[l].getGlobalBounds().intersects(enemies_shapes[k].getGlobalBounds()))
//				{
//				enemies_struct[l].expostion = -enemies_struct[l].expostion;
//				enemies_struct[l].eypostion = -enemies_struct[l].eypostion;
//				enemies_struct[k].expostion = -enemies_struct[k].expostion;
//				enemies_struct[k].eypostion = -enemies_struct[k].eypostion;
//				}
//				}*/
//			}
//			//enemy move
//			moveEnemy(nEnemy);// activate it when you want to cut pieces of the pink line and remove it below :)
//			// boundaries that anything can't go after it like player
//			//player movement in the Grid 
//			movePlayer(xpos, ypos, dir);
//			player.setPosition(xpos * 10, ypos * 10);
//			time_text.setString(time_string.str());
//			//check player-enemy collision
//			checkCollision(nEnemy, enemies_shapes, collisionSound);
//			//moveEnemy(nEnemy);
//
//			/*	for (int i = 0; i < 82; i++)
//			{
//			for (int j = 0; j < 62; j++)
//			{
//			if (player.getPosition().x == grid[i][j] == 2 || player.getPosition().y == grid[i][j] == 2)
//			play = false;
//			}
//			}*/
//			setsBrush(xpos, ypos);
//			//draw
//			Texture image1;
//			if (image1.loadFromFile("Data/picture1.png") == false)
//			{
//				cout << "image is not here";
//			}
//			Sprite picture1(image1);
//			window_Level_one.clear();
//			if (defaultmode == true)
//			{
//				for (int i = 0; i <= 82; i++)
//				{
//					for (int j = 0; j <= 62; j++)
//					{
//						if (grid[i][j] == 1 || grid[i][j] == 2)
//						{
//							picture1.setTextureRect(IntRect(i * 10, j * 10, 10, 10));
//							picture1.setPosition(i * 10, j * 10);
//							window_Level_one.draw(picture1);
//						}
//					}
//				}
//			}
//			else
//			{
//				drawArea(Sgrid, window_Level_one, image, image2);
//			}
//
//			window_Level_one.draw(player);
//			window_Level_one.draw(sprite3);
//			window_Level_one.draw(bound);
//			for (int i = 0; i < nEnemy; i++) {
//				window_Level_one.draw(enemies_shapes[i]);
//			}
//			window_Level_one.draw(time_text);
//			window_Level_one.draw(heartText);
//			window_Level_one.draw(nametext);
//			window_Level_one.draw(PercentText);
//			window_Level_one.draw(labelscore);
//
//
//
//			window_Level_one.display();
//			///////////////////////
//			reply_level(play, music, xpos, ypos);
//
//		}
//		win(window_Level_one);
//		/*	if (replay == true)
//		{
//		replay = false;
//		set_grid_0();
//		///needs more expermenting now it has been fixed :)
//		part_level_one(level_number);
//		}*/
//	}
//}
//
//void part_level_two(int number_level)
//{
//	if (level_number == 1)
//	{
//		heart = 3;
//		//level two  
//		set_grid_0();
//		short nEnemy = 6;//number of enemy of selected level
//		//level one  
//		RenderWindow window_Level_two(VideoMode(ScreenWidth, ScreenHeight), "level two", Style::Close);//render window_play 
//		window_Level_two.setFramerateLimit(30);//set frames to 60 per second 
//		bool play = true; // play variable 
//		int xpos = 0, ypos = 0; //playes position
//		short dir = -1;//direction of the player  -1 means no direction in the start it can be anything
//		//images 
//		Texture image, image2, image3;
//		check_images_borders_load(image, image2, image3);
//		Sprite  sprite3(image3);
//		sprite3.setPosition(Vector2f((ScreenWidth / 3 - 50), 633));
//		//font 
//		Font number_font, Arial_font;
//		check_font_load(number_font, Arial_font);
//		setScoreText(Arial_font);
//
//		Texture texture;
//		if (!texture.loadFromFile("Data/enemy.png"))
//			cout << "error in load photo of enemy ";
//		RectangleShape enemies_shapes[10];
//		setEnemiesShapes(nEnemy, enemies_shapes);
//		// time 
//		time_t first_second, this_second;
//		time(&first_second);
//		int second = 0, minute = 0;
//		//time text
//		Text time_text, PercentText, heartText;
//		setTimeText(number_font, time_text);
//		//Percent Text
//		setPercentText(Arial_font, PercentText);
//		//heart Text
//		setHeartText(Arial_font, heartText);
//		//player rectangle 
//		RectangleShape player;
//		player_rectangle(player);
//		//under bound rectangle 
//		RectangleShape bound;
//		bound.setFillColor(Color::Red);
//		bound.setPosition(0, 620);
//		bound.setSize(Vector2f(820, 5));
//		// event
//		Event event;
//		//sound
//		// sound track while the game is playing
//		Music music;
//		if (!music.openFromFile("Data/soundtrack.ogg"))
//			cout << "error in load sound";
//		music.play();
//		SoundBuffer sound;
//		Sound collisionSound;
//		if (sound.loadFromFile("Data/impact.wav"))
//			cout << "collision done " << endl;
//		collisionSound.setBuffer(sound);
//		while (play)     //this move one page
//		{
//			Sprite Sgrid;
//			int percent = 0;
//			percent = checkBoundaries() / (44);
//			updateScore();
//			// time string 
//			stringstream time_string, areaString, heartString;
//			heartString << heart;
//			heartText.setString(heartString.str());
//			areaString << "You Finished " << percent << "%";
//			PercentText.setString(areaString.str());
//			//setting time 
//			setTime(this_second, second, minute, first_second, time_string);
//
//
//			while (window_Level_two.pollEvent(event))
//			{
//				if (event.type == Event::Closed)
//				{
//					window_Level_two.close();
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Escape))
//				{
//					window_Level_two.close();
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Up)) 		dir = Up;
//				else if (Keyboard::isKeyPressed(Keyboard::Down))	dir = Down;
//				else if (Keyboard::isKeyPressed(Keyboard::Right))	dir = Right;
//				else if (Keyboard::isKeyPressed(Keyboard::Left))	dir = Left;
//
//			}
//			//enemy move
//			moveEnemy(nEnemy);
//			// boundaries that anything can't go after it like player
//			//player movement in the Grid 
//			movePlayer(xpos, ypos, dir);
//			player.setPosition(xpos * 10, ypos * 10);
//			time_text.setString(time_string.str());
//			checkCollision(nEnemy, enemies_shapes, collisionSound);
//			/*	for (int i = 0; i < 82; i++)
//			{
//			for (int j = 0; j < 62; j++)
//			{
//			if (player.getPosition().x == grid[i][j] == 2 || player.getPosition().y == grid[i][j] == 2)
//			play = false;
//			}
//			}*/
//
//			setsBrush(xpos, ypos);
//			Texture image2;
//			if (image2.loadFromFile("Data/picture2.png") == false)
//			{
//				cout << "image is not here";
//			}
//			Sprite picture2(image2);
//			//draw 
//			window_Level_two.clear();
//			if (defaultmode == true)
//			{
//				for (int i = 0; i <= 82; i++)
//				{
//					for (int j = 0; j <= 62; j++)
//					{
//						if (grid[i][j] == 1 || grid[i][j] == 2)
//						{
//							picture2.setTextureRect(IntRect(i * 10, j * 10, 10, 10));
//							picture2.setPosition(i * 10, j * 10);
//							window_Level_two.draw(picture2);
//						}
//					}
//				}
//			}
//			else
//			{
//				drawArea(Sgrid, window_Level_two, image, image2);
//			}
//
//			window_Level_two.draw(player);
//			window_Level_two.draw(sprite3);
//			window_Level_two.draw(bound);
//			for (int i = 0; i < nEnemy; i++) {
//				window_Level_two.draw(enemies_shapes[i]);
//			}
//			window_Level_two.draw(time_text);
//			window_Level_two.draw(PercentText);
//			window_Level_two.draw(heartText);
//
//			window_Level_two.draw(labelscore);
//
//			window_Level_two.display();
//			/////////////////////
//			reply_level(play, music, xpos, ypos);
//		}
//	}
//}
//
//void part_level_three(int number_level)
//{
//	if (level_number == 2)
//	{//level three
//		set_grid_0();
//		short nEnemy = 4;//number of enemy of selected level
//		//level one  
//		RenderWindow window_Level_Three(VideoMode(ScreenWidth, ScreenHeight), "level three", Style::Close);//render window_play 
//		window_Level_Three.setFramerateLimit(30);//set frames to 60 per second 
//		bool play = true, endgame = false;; // play variable 
//		int xpos = 0, ypos = 0; //playes position
//		short dir = -1;//direction of the player  -1 means no direction in the start it can be anything
//		//images 
//		//images 
//		Texture image, image2, image3;
//		check_images_borders_load(image, image2, image3);
//		Sprite  sprite3(image3);
//		sprite3.setPosition(Vector2f((ScreenWidth / 3 - 50), 633));
//		//font 
//		Font number_font, Arial_font;
//		check_font_load(number_font, Arial_font);
//		setScoreText(Arial_font);
//
//		RectangleShape enemies_shapes[10];
//		setEnemiesShapes(nEnemy, enemies_shapes);
//		// time 
//		time_t first_second, this_second;
//		time(&first_second);
//		int second = 0, minute = 0;
//		//time text
//		Text time_text, PercentText, heartText;
//		setTimeText(number_font, time_text);
//		//Percent Text
//		setPercentText(Arial_font, PercentText);
//		//heart Text
//		setHeartText(Arial_font, heartText);
//		//player rectangle 
//		RectangleShape player;
//		player_rectangle(player);
//		//under bound rectangle 
//		RectangleShape bound;
//		bound.setFillColor(Color::Red);
//		bound.setPosition(0, 620);
//		bound.setSize(Vector2f(820, 5));
//		// event
//		Event event;
//		//sound
//		// sound track while the game is playing
//		Music music;
//		if (!music.openFromFile("Data/soundtrack.ogg"))
//			cout << "error in load sound";
//		music.play();
//		SoundBuffer sound;
//		Sound collisionSound;
//		if (sound.loadFromFile("Data/impact.wav"))
//			cout << "collision done " << endl;
//		collisionSound.setBuffer(sound);
//		while (play)     //this move one page
//		{
//			Sprite Sgrid;
//			int percent = 0;
//			percent = checkBoundaries() / (44);
//			updateScore();
//			// time string 
//			stringstream time_string, areaString, heartString;
//			heartString << heart;
//			heartText.setString(heartString.str());
//			areaString << "You Finished " << percent << "%";
//			PercentText.setString(areaString.str());
//			//setting time 
//			setTime(this_second, second, minute, first_second, time_string);
//
//			while (window_Level_Three.pollEvent(event))
//			{
//				if (event.type == Event::Closed)
//				{
//					window_Level_Three.close();
//					play = false;
//					//endgame = true;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Escape))
//				{
//					window_Level_Three.close();
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Up)) 		dir = Up;
//				else if (Keyboard::isKeyPressed(Keyboard::Down))	dir = Down;
//				else if (Keyboard::isKeyPressed(Keyboard::Right))	dir = Right;
//				else if (Keyboard::isKeyPressed(Keyboard::Left))	dir = Left;
//
//			}
//			//enemy move
//			moveEnemy(nEnemy);
//			// boundaries that anything can't go after it like player
//			//player movement in the Grid 
//			movePlayer(xpos, ypos, dir);
//			player.setPosition(xpos * 10, ypos * 10);
//			time_text.setString(time_string.str());
//			checkCollision(nEnemy, enemies_shapes, collisionSound);
//
//			setsBrush(xpos, ypos);
//			//draw
//			Texture image3;
//			if (image3.loadFromFile("Data/picture3.png") == false)
//			{
//				cout << "image is not here";
//			}
//			Sprite picture3(image3);
//			window_Level_Three.clear();
//			if (defaultmode == true)
//			{
//				for (int i = 0; i <= 82; i++)
//				{
//					for (int j = 0; j <= 62; j++)
//					{
//						if (grid[i][j] == 1 || grid[i][j] == 2)
//						{
//							picture3.setTextureRect(IntRect(i * 10, j * 10, 10, 10));
//							picture3.setPosition(i * 10, j * 10);
//							window_Level_Three.draw(picture3);
//						}
//					}
//				}
//			}
//			else
//			{
//				drawArea(Sgrid, window_Level_Three, image, image2);
//			}
//			window_Level_Three.draw(player);
//			window_Level_Three.draw(sprite3);
//
//			window_Level_Three.draw(bound);
//			for (int i = 0; i < nEnemy; i++) {
//				window_Level_Three.draw(enemies_shapes[i]);
//			}
//			window_Level_Three.draw(time_text);
//			window_Level_Three.draw(PercentText);
//			window_Level_Three.draw(heartText);
//
//			window_Level_Three.draw(labelscore);
//
//			window_Level_Three.display();
//		}
//	}
//}
//void part_level_four(int level_number) {
//
//
//	heart = 3;
//	if (level_number == 3)
//	{//level three
//		heart = 3;
//		//score system
//		int highscore = 20;
//
//		//level one  --- 
//		//set_grid_0();
//		short nEnemy = 4;//number of enemy of selected level
//		//level one  
//		RenderWindow window_Level_one(VideoMode(ScreenWidth, ScreenHeight), "level four", Style::Close);//render window_play 
//		window_Level_one.setFramerateLimit(30);//set frames to 60 per second 
//		bool play = true;// play variable 
//
//		int xpos = 0, ypos = 0; //playes position
//		short dir = -1;//direction of the player  -1 means no direction in the start it can be anything
//
//		//images 
//		Texture image, image2, image3;
//		check_images_borders_load(image, image2, image3);
//		Sprite  sprite3(image3);
//		sprite3.setPosition(Vector2f((ScreenWidth / 3 - 50), 633));
//		//font 
//		Font number_font, Arial_font;
//		check_font_load(number_font, Arial_font);
//		setScoreText(Arial_font);
//
//		RectangleShape enemies_shapes[10];
//		setEnemiesShapes(nEnemy, enemies_shapes);
//		// time 
//		time_t first_second, this_second;
//		time(&first_second);
//		int second = 0, minute = 0;
//		//time text
//		Text time_text, PercentText, heartText, nametext;
//		if (Arial_font.loadFromFile("Data/levels.ttf") == false)
//			std::cout << "erorr in loading Font";
//		nametext.setFont(Arial_font);
//		nametext.setFillColor(Color::Green);
//		nametext.setPosition(570, 630);
//		nametext.setCharacterSize(30);
//		setTimeText(number_font, time_text);
//		//Percent Text
//		setPercentText(Arial_font, PercentText);
//		//heart Text
//		setHeartText(Arial_font, heartText);
//		//player rectangle
//		RectangleShape player;
//		player_rectangle(player);
//		//under bound rectangle 
//		RectangleShape bound;
//		bound.setFillColor(Color::Red);
//		bound.setPosition(0, 620);
//		bound.setSize(Vector2f(820, 5));
//		// event
//		Event event;
//		//sound
//		// sound track while the game is playing
//		Music music;
//		if (!music.openFromFile("Data/soundtrack.ogg"))
//			cout << "error in load sound";
//		music.play();
//		SoundBuffer sound;
//		Sound collisionSound;
//		if (sound.loadFromFile("Data/impact.wav"))
//			cout << "collision done " << endl;
//		collisionSound.setBuffer(sound);
//
//		while (play)     //this move one page
//		{
//
//			Sprite Sgrid;
//			int percent = 0;
//			percent = checkBoundaries() / (44);
//			updateScore();
//			calculateScore(minute, second, percent);
//
//			// time string 
//			stringstream time_string, areaString, heartString, nameString;
//			nameString << playername;
//			nametext.setString(nameString.str());
//			heartString << heart;
//			heartText.setString(heartString.str());
//			areaString << "You Finished " << percent << "%";
//			PercentText.setString(areaString.str());
//			//setting time 
//			setTime(this_second, second, minute, first_second, time_string);
//
//			while (window_Level_one.pollEvent(event))
//			{
//				if (event.type == Event::Closed)
//				{
//					window_Level_one.close();
//					start = 0;
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Escape))
//				{
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Up)) 		dir = Up;
//				else if (Keyboard::isKeyPressed(Keyboard::Down))	dir = Down;
//				else if (Keyboard::isKeyPressed(Keyboard::Right))	dir = Right;
//				else if (Keyboard::isKeyPressed(Keyboard::Left))	dir = Left;
//				/*	for (int l = 0; l < nEnemy; l++)
//				{
//				for (int k = 1; k < nEnemy; k++)
//				if (enemies_shapes[l].getGlobalBounds().intersects(enemies_shapes[k].getGlobalBounds()))
//				{
//				enemies_struct[l].expostion = -enemies_struct[l].expostion;
//				enemies_struct[l].eypostion = -enemies_struct[l].eypostion;
//				enemies_struct[k].expostion = -enemies_struct[k].expostion;
//				enemies_struct[k].eypostion = -enemies_struct[k].eypostion;
//				}
//				}*/
//			}
//			//enemy move
//			moveEnemy(nEnemy);// activate it when you want to cut pieces of the pink line and remove it below :)
//			// boundaries that anything can't go after it like player
//			//player movement in the Grid 
//			movePlayer(xpos, ypos, dir);
//			player.setPosition(xpos * 10, ypos * 10);
//			time_text.setString(time_string.str());
//			//check player-enemy collision
//			checkCollision(nEnemy, enemies_shapes, collisionSound);
//			//moveEnemy(nEnemy);
//
//			/*	for (int i = 0; i < 82; i++)
//			{
//			for (int j = 0; j < 62; j++)
//			{
//			if (player.getPosition().x == grid[i][j] == 2 || player.getPosition().y == grid[i][j] == 2)
//			play = false;
//			}
//			}*/
//			setsBrush(xpos, ypos);
//			//draw
//			Texture image1;
//			if (image1.loadFromFile("Data/picture4.png") == false)
//			{
//				cout << "image is not here";
//			}
//			Sprite picture1(image1);
//			window_Level_one.clear();
//			if (defaultmode == true)
//			{
//				for (int i = 0; i <= 82; i++)
//				{
//					for (int j = 0; j <= 62; j++)
//					{
//						if (grid[i][j] == 1 || grid[i][j] == 2)
//						{
//							picture1.setTextureRect(IntRect(i * 10, j * 10, 10, 10));
//							picture1.setPosition(i * 10, j * 10);
//							window_Level_one.draw(picture1);
//						}
//					}
//				}
//			}
//			else
//			{
//				drawArea(Sgrid, window_Level_one, image, image2);
//			}
//
//			window_Level_one.draw(player);
//			window_Level_one.draw(sprite3);
//			window_Level_one.draw(bound);
//			for (int i = 0; i < nEnemy; i++) {
//				window_Level_one.draw(enemies_shapes[i]);
//			}
//			window_Level_one.draw(time_text);
//			window_Level_one.draw(heartText);
//			window_Level_one.draw(nametext);
//			window_Level_one.draw(PercentText);
//			window_Level_one.draw(labelscore);
//
//
//
//			window_Level_one.display();
//			///////////////////////
//			reply_level(play, music, xpos, ypos);
//
//		}
//		win(window_Level_one);
//		/*	if (replay == true)
//		{
//		replay = false;
//		set_grid_0();
//		///needs more expermenting now it has been fixed :)
//		part_level_one(level_number);
//		}*/
//	}
//}
//void part_level_five(int level_number) {
//
//
//	if (level_number == 4)
//	{//level three
//		heart = 3;
//		//score system
//		int highscore = 20;
//
//		//level one  --- 
//		//set_grid_0();
//		short nEnemy = 4;//number of enemy of selected level
//		//level one  
//		RenderWindow window_Level_one(VideoMode(ScreenWidth, ScreenHeight), "level five", Style::Close);//render window_play 
//		window_Level_one.setFramerateLimit(30);//set frames to 60 per second 
//		bool play = true;// play variable 
//
//		int xpos = 0, ypos = 0; //playes position
//		short dir = -1;//direction of the player  -1 means no direction in the start it can be anything
//
//		//images 
//		Texture image, image2, image3;
//		check_images_borders_load(image, image2, image3);
//		Sprite  sprite3(image3);
//		sprite3.setPosition(Vector2f((ScreenWidth / 3 - 50), 633));
//		//font 
//		Font number_font, Arial_font;
//		check_font_load(number_font, Arial_font);
//		setScoreText(Arial_font);
//
//		RectangleShape enemies_shapes[10];
//		setEnemiesShapes(nEnemy, enemies_shapes);
//		// time 
//		time_t first_second, this_second;
//		time(&first_second);
//		int second = 0, minute = 0;
//		//time text
//		Text time_text, PercentText, heartText, nametext;
//		if (Arial_font.loadFromFile("Data/levels.ttf") == false)
//			std::cout << "erorr in loading Font";
//		nametext.setFont(Arial_font);
//		nametext.setFillColor(Color::Green);
//		nametext.setPosition(570, 630);
//		nametext.setCharacterSize(30);
//		setTimeText(number_font, time_text);
//		//Percent Text
//		setPercentText(Arial_font, PercentText);
//		//heart Text
//		setHeartText(Arial_font, heartText);
//		//player rectangle
//		RectangleShape player;
//		player_rectangle(player);
//		//under bound rectangle 
//		RectangleShape bound;
//		bound.setFillColor(Color::Red);
//		bound.setPosition(0, 620);
//		bound.setSize(Vector2f(820, 5));
//		// event
//		Event event;
//		//sound
//		// sound track while the game is playing
//		Music music;
//		if (!music.openFromFile("Data/soundtrack.ogg"))
//			cout << "error in load sound";
//		music.play();
//		SoundBuffer sound;
//		Sound collisionSound;
//		if (sound.loadFromFile("Data/impact.wav"))
//			cout << "collision done " << endl;
//		collisionSound.setBuffer(sound);
//
//		while (play)     //this move one page
//		{
//
//			Sprite Sgrid;
//			int percent = 0;
//			percent = checkBoundaries() / (44);
//			updateScore();
//			calculateScore(minute, second, percent);
//
//			// time string 
//			stringstream time_string, areaString, heartString, nameString;
//			nameString << playername;
//			nametext.setString(nameString.str());
//			heartString << heart;
//			heartText.setString(heartString.str());
//			areaString << "You Finished " << percent << "%";
//			PercentText.setString(areaString.str());
//			//setting time 
//			setTime(this_second, second, minute, first_second, time_string);
//
//			while (window_Level_one.pollEvent(event))
//			{
//				if (event.type == Event::Closed)
//				{
//					window_Level_one.close();
//					start = 0;
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Escape))
//				{
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Up)) 		dir = Up;
//				else if (Keyboard::isKeyPressed(Keyboard::Down))	dir = Down;
//				else if (Keyboard::isKeyPressed(Keyboard::Right))	dir = Right;
//				else if (Keyboard::isKeyPressed(Keyboard::Left))	dir = Left;
//				/*	for (int l = 0; l < nEnemy; l++)
//				{
//				for (int k = 1; k < nEnemy; k++)
//				if (enemies_shapes[l].getGlobalBounds().intersects(enemies_shapes[k].getGlobalBounds()))
//				{
//				enemies_struct[l].expostion = -enemies_struct[l].expostion;
//				enemies_struct[l].eypostion = -enemies_struct[l].eypostion;
//				enemies_struct[k].expostion = -enemies_struct[k].expostion;
//				enemies_struct[k].eypostion = -enemies_struct[k].eypostion;
//				}
//				}*/
//			}
//			//enemy move
//			moveEnemy(nEnemy);// activate it when you want to cut pieces of the pink line and remove it below :)
//			// boundaries that anything can't go after it like player
//			//player movement in the Grid 
//			movePlayer(xpos, ypos, dir);
//			player.setPosition(xpos * 10, ypos * 10);
//			time_text.setString(time_string.str());
//			//check player-enemy collision
//			checkCollision(nEnemy, enemies_shapes, collisionSound);
//			//moveEnemy(nEnemy);
//
//			/*	for (int i = 0; i < 82; i++)
//			{
//			for (int j = 0; j < 62; j++)
//			{
//			if (player.getPosition().x == grid[i][j] == 2 || player.getPosition().y == grid[i][j] == 2)
//			play = false;
//			}
//			}*/
//			setsBrush(xpos, ypos);
//			//draw
//			Texture image1;
//			if (image1.loadFromFile("Data/picture5.png") == false)
//			{
//				cout << "image is not here";
//			}
//			Sprite picture1(image1);
//			window_Level_one.clear();
//			if (defaultmode == true)
//			{
//				for (int i = 0; i <= 82; i++)
//				{
//					for (int j = 0; j <= 62; j++)
//					{
//						if (grid[i][j] == 1 || grid[i][j] == 2)
//						{
//							picture1.setTextureRect(IntRect(i * 10, j * 10, 10, 10));
//							picture1.setPosition(i * 10, j * 10);
//							window_Level_one.draw(picture1);
//						}
//					}
//				}
//			}
//			else
//			{
//				drawArea(Sgrid, window_Level_one, image, image2);
//			}
//
//			window_Level_one.draw(player);
//			window_Level_one.draw(sprite3);
//			window_Level_one.draw(bound);
//			for (int i = 0; i < nEnemy; i++) {
//				window_Level_one.draw(enemies_shapes[i]);
//			}
//			window_Level_one.draw(time_text);
//			window_Level_one.draw(heartText);
//			window_Level_one.draw(nametext);
//			window_Level_one.draw(PercentText);
//			window_Level_one.draw(labelscore);
//
//
//
//			window_Level_one.display();
//			///////////////////////
//			reply_level(play, music, xpos, ypos);
//
//		}
//		win(window_Level_one);
//		/*	if (replay == true)
//		{
//		replay = false;
//		set_grid_0();
//		///needs more expermenting now it has been fixed :)
//		part_level_one(level_number);
//		}*/
//	}
//}
//void part_level_six(int level_number) {
//
//
//	if (level_number == 5)
//	{//level three
//		heart = 3;
//		//score system
//		int highscore = 20;
//
//		//level one  --- 
//		//set_grid_0();
//		short nEnemy = 4;//number of enemy of selected level
//		//level one  
//		RenderWindow window_Level_one(VideoMode(ScreenWidth, ScreenHeight), "level six", Style::Close);//render window_play 
//		window_Level_one.setFramerateLimit(30);//set frames to 60 per second 
//		bool play = true;// play variable 
//
//		int xpos = 0, ypos = 0; //playes position
//		short dir = -1;//direction of the player  -1 means no direction in the start it can be anything
//
//		//images 
//		Texture image, image2, image3;
//		check_images_borders_load(image, image2, image3);
//		Sprite  sprite3(image3);
//		sprite3.setPosition(Vector2f((ScreenWidth / 3 - 50), 633));
//		//font 
//		Font number_font, Arial_font;
//		check_font_load(number_font, Arial_font);
//		setScoreText(Arial_font);
//
//		RectangleShape enemies_shapes[10];
//		setEnemiesShapes(nEnemy, enemies_shapes);
//		// time 
//		time_t first_second, this_second;
//		time(&first_second);
//		int second = 0, minute = 0;
//		//time text
//		Text time_text, PercentText, heartText, nametext;
//		if (Arial_font.loadFromFile("Data/levels.ttf") == false)
//			std::cout << "erorr in loading Font";
//		nametext.setFont(Arial_font);
//		nametext.setFillColor(Color::Green);
//		nametext.setPosition(570, 630);
//		nametext.setCharacterSize(30);
//		setTimeText(number_font, time_text);
//		//Percent Text
//		setPercentText(Arial_font, PercentText);
//		//heart Text
//		setHeartText(Arial_font, heartText);
//		//player rectangle
//		RectangleShape player;
//		player_rectangle(player);
//		//under bound rectangle 
//		RectangleShape bound;
//		bound.setFillColor(Color::Red);
//		bound.setPosition(0, 620);
//		bound.setSize(Vector2f(820, 5));
//		// event
//		Event event;
//		//sound
//		// sound track while the game is playing
//		Music music;
//		if (!music.openFromFile("Data/soundtrack.ogg"))
//			cout << "error in load sound";
//		music.play();
//		SoundBuffer sound;
//		Sound collisionSound;
//		if (sound.loadFromFile("Data/impact.wav"))
//			cout << "collision done " << endl;
//		collisionSound.setBuffer(sound);
//
//		while (play)     //this move one page
//		{
//
//			Sprite Sgrid;
//			int percent = 0;
//			percent = checkBoundaries() / (44);
//			updateScore();
//			calculateScore(minute, second, percent);
//
//			// time string 
//			stringstream time_string, areaString, heartString, nameString;
//			nameString << playername;
//			nametext.setString(nameString.str());
//			heartString << heart;
//			heartText.setString(heartString.str());
//			areaString << "You Finished " << percent << "%";
//			PercentText.setString(areaString.str());
//			//setting time 
//			setTime(this_second, second, minute, first_second, time_string);
//
//			while (window_Level_one.pollEvent(event))
//			{
//				if (event.type == Event::Closed)
//				{
//					window_Level_one.close();
//					start = 0;
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Escape))
//				{
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Up)) 		dir = Up;
//				else if (Keyboard::isKeyPressed(Keyboard::Down))	dir = Down;
//				else if (Keyboard::isKeyPressed(Keyboard::Right))	dir = Right;
//				else if (Keyboard::isKeyPressed(Keyboard::Left))	dir = Left;
//				/*	for (int l = 0; l < nEnemy; l++)
//				{
//				for (int k = 1; k < nEnemy; k++)
//				if (enemies_shapes[l].getGlobalBounds().intersects(enemies_shapes[k].getGlobalBounds()))
//				{
//				enemies_struct[l].expostion = -enemies_struct[l].expostion;
//				enemies_struct[l].eypostion = -enemies_struct[l].eypostion;
//				enemies_struct[k].expostion = -enemies_struct[k].expostion;
//				enemies_struct[k].eypostion = -enemies_struct[k].eypostion;
//				}
//				}*/
//			}
//			//enemy move
//			moveEnemy(nEnemy);// activate it when you want to cut pieces of the pink line and remove it below :)
//			// boundaries that anything can't go after it like player
//			//player movement in the Grid 
//			movePlayer(xpos, ypos, dir);
//			player.setPosition(xpos * 10, ypos * 10);
//			time_text.setString(time_string.str());
//			//check player-enemy collision
//			checkCollision(nEnemy, enemies_shapes, collisionSound);
//			//moveEnemy(nEnemy);
//
//			/*	for (int i = 0; i < 82; i++)
//			{
//			for (int j = 0; j < 62; j++)
//			{
//			if (player.getPosition().x == grid[i][j] == 2 || player.getPosition().y == grid[i][j] == 2)
//			play = false;
//			}
//			}*/
//			setsBrush(xpos, ypos);
//			//draw
//			Texture image1;
//			if (image1.loadFromFile("Data/picture6.png") == false)
//			{
//				cout << "image is not here";
//			}
//			Sprite picture1(image1);
//			window_Level_one.clear();
//			if (defaultmode == true)
//			{
//				for (int i = 0; i <= 82; i++)
//				{
//					for (int j = 0; j <= 62; j++)
//					{
//						if (grid[i][j] == 1 || grid[i][j] == 2)
//						{
//							picture1.setTextureRect(IntRect(i * 10, j * 10, 10, 10));
//							picture1.setPosition(i * 10, j * 10);
//							window_Level_one.draw(picture1);
//						}
//					}
//				}
//			}
//			else
//			{
//				drawArea(Sgrid, window_Level_one, image, image2);
//			}
//
//			window_Level_one.draw(player);
//			window_Level_one.draw(sprite3);
//			window_Level_one.draw(bound);
//			for (int i = 0; i < nEnemy; i++) {
//				window_Level_one.draw(enemies_shapes[i]);
//			}
//			window_Level_one.draw(time_text);
//			window_Level_one.draw(heartText);
//			window_Level_one.draw(nametext);
//			window_Level_one.draw(PercentText);
//			window_Level_one.draw(labelscore);
//
//
//
//			window_Level_one.display();
//			///////////////////////
//			reply_level(play, music, xpos, ypos);
//
//		}
//		win(window_Level_one);
//		/*	if (replay == true)
//		{
//		replay = false;
//		set_grid_0();
//		///needs more expermenting now it has been fixed :)
//		part_level_one(level_number);
//		}*/
//	}
//}
//void part_level_seven(int level_number) {
//
//
//	if (level_number == 6)
//	{//level three
//		heart = 3;
//		//score system
//		int highscore = 20;
//
//		//level one  --- 
//		//set_grid_0();
//		short nEnemy = 4;//number of enemy of selected level
//		//level one  
//		RenderWindow window_Level_one(VideoMode(ScreenWidth, ScreenHeight), "level seven", Style::Close);//render window_play 
//		window_Level_one.setFramerateLimit(30);//set frames to 60 per second 
//		bool play = true;// play variable 
//
//		int xpos = 0, ypos = 0; //playes position
//		short dir = -1;//direction of the player  -1 means no direction in the start it can be anything
//
//		//images 
//		Texture image, image2, image3;
//		check_images_borders_load(image, image2, image3);
//		Sprite  sprite3(image3);
//		sprite3.setPosition(Vector2f((ScreenWidth / 3 - 50), 633));
//		//font 
//		Font number_font, Arial_font;
//		check_font_load(number_font, Arial_font);
//		setScoreText(Arial_font);
//
//		RectangleShape enemies_shapes[10];
//		setEnemiesShapes(nEnemy, enemies_shapes);
//		// time 
//		time_t first_second, this_second;
//		time(&first_second);
//		int second = 0, minute = 0;
//		//time text
//		Text time_text, PercentText, heartText, nametext;
//		if (Arial_font.loadFromFile("Data/levels.ttf") == false)
//			std::cout << "erorr in loading Font";
//		nametext.setFont(Arial_font);
//		nametext.setFillColor(Color::Green);
//		nametext.setPosition(570, 630);
//		nametext.setCharacterSize(30);
//		setTimeText(number_font, time_text);
//		//Percent Text
//		setPercentText(Arial_font, PercentText);
//		//heart Text
//		setHeartText(Arial_font, heartText);
//		//player rectangle
//		RectangleShape player;
//		player_rectangle(player);
//		//under bound rectangle 
//		RectangleShape bound;
//		bound.setFillColor(Color::Red);
//		bound.setPosition(0, 620);
//		bound.setSize(Vector2f(820, 5));
//		// event
//		Event event;
//		//sound
//		// sound track while the game is playing
//		Music music;
//		if (!music.openFromFile("Data/soundtrack.ogg"))
//			cout << "error in load sound";
//		music.play();
//		SoundBuffer sound;
//		Sound collisionSound;
//		if (sound.loadFromFile("Data/impact.wav"))
//			cout << "collision done " << endl;
//		collisionSound.setBuffer(sound);
//
//		while (play)     //this move one page
//		{
//
//			Sprite Sgrid;
//			int percent = 0;
//			percent = checkBoundaries() / (44);
//			updateScore();
//			calculateScore(minute, second, percent);
//
//			// time string 
//			stringstream time_string, areaString, heartString, nameString;
//			nameString << playername;
//			nametext.setString(nameString.str());
//			heartString << heart;
//			heartText.setString(heartString.str());
//			areaString << "You Finished " << percent << "%";
//			PercentText.setString(areaString.str());
//			//setting time 
//			setTime(this_second, second, minute, first_second, time_string);
//
//			while (window_Level_one.pollEvent(event))
//			{
//				if (event.type == Event::Closed)
//				{
//					window_Level_one.close();
//					start = 0;
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Escape))
//				{
//					play = false;
//				}
//				if (Keyboard::isKeyPressed(Keyboard::Up)) 		dir = Up;
//				else if (Keyboard::isKeyPressed(Keyboard::Down))	dir = Down;
//				else if (Keyboard::isKeyPressed(Keyboard::Right))	dir = Right;
//				else if (Keyboard::isKeyPressed(Keyboard::Left))	dir = Left;
//				/*	for (int l = 0; l < nEnemy; l++)
//				{
//				for (int k = 1; k < nEnemy; k++)
//				if (enemies_shapes[l].getGlobalBounds().intersects(enemies_shapes[k].getGlobalBounds()))
//				{
//				enemies_struct[l].expostion = -enemies_struct[l].expostion;
//				enemies_struct[l].eypostion = -enemies_struct[l].eypostion;
//				enemies_struct[k].expostion = -enemies_struct[k].expostion;
//				enemies_struct[k].eypostion = -enemies_struct[k].eypostion;
//				}
//				}*/
//			}
//			//enemy move
//			moveEnemy(nEnemy);// activate it when you want to cut pieces of the pink line and remove it below :)
//			// boundaries that anything can't go after it like player
//			//player movement in the Grid 
//			movePlayer(xpos, ypos, dir);
//			player.setPosition(xpos * 10, ypos * 10);
//			time_text.setString(time_string.str());
//			//check player-enemy collision
//			checkCollision(nEnemy, enemies_shapes, collisionSound);
//			//moveEnemy(nEnemy);
//
//			/*	for (int i = 0; i < 82; i++)
//			{
//			for (int j = 0; j < 62; j++)
//			{
//			if (player.getPosition().x == grid[i][j] == 2 || player.getPosition().y == grid[i][j] == 2)
//			play = false;
//			}
//			}*/
//			setsBrush(xpos, ypos);
//			//draw
//			Texture image1;
//			if (image1.loadFromFile("Data/picture7.png") == false)
//			{
//				cout << "image is not here";
//			}
//			Sprite picture1(image1);
//			window_Level_one.clear();
//			if (defaultmode == true)
//			{
//				for (int i = 0; i <= 82; i++)
//				{
//					for (int j = 0; j <= 62; j++)
//					{
//						if (grid[i][j] == 1 || grid[i][j] == 2)
//						{
//							picture1.setTextureRect(IntRect(i * 10, j * 10, 10, 10));
//							picture1.setPosition(i * 10, j * 10);
//							window_Level_one.draw(picture1);
//						}
//					}
//				}
//			}
//			else
//			{
//				drawArea(Sgrid, window_Level_one, image, image2);
//			}
//
//			window_Level_one.draw(player);
//			window_Level_one.draw(sprite3);
//			window_Level_one.draw(bound);
//			for (int i = 0; i < nEnemy; i++) {
//				window_Level_one.draw(enemies_shapes[i]);
//			}
//			window_Level_one.draw(time_text);
//			window_Level_one.draw(heartText);
//			window_Level_one.draw(nametext);
//			window_Level_one.draw(PercentText);
//			window_Level_one.draw(labelscore);
//
//
//
//			window_Level_one.display();
//			///////////////////////
//			reply_level(play, music, xpos, ypos);
//
//		}
//		win(window_Level_one);
//		/*	if (replay == true)
//		{
//		replay = false;
//		set_grid_0();
//		///needs more expermenting now it has been fixed :)
//		part_level_one(level_number);
//		}*/
//	}
//}
//
//void part_level_eight(int level_number) {
//
//	{
//		if (level_number == 7)
//		{//level three
//			heart = 3;
//			//score system
//			int highscore = 20;
//
//			//level one  --- 
//			//set_grid_0();
//			short nEnemy = 4;//number of enemy of selected level
//			//level one  
//			RenderWindow window_Level_one(VideoMode(ScreenWidth, ScreenHeight), "level eight", Style::Close);//render window_play 
//			window_Level_one.setFramerateLimit(30);//set frames to 60 per second 
//			bool play = true;// play variable 
//
//			int xpos = 0, ypos = 0; //playes position
//			short dir = -1;//direction of the player  -1 means no direction in the start it can be anything
//
//			//images 
//			Texture image, image2, image3;
//			check_images_borders_load(image, image2, image3);
//			Sprite  sprite3(image3);
//			sprite3.setPosition(Vector2f((ScreenWidth / 3 - 50), 633));
//			//font 
//			Font number_font, Arial_font;
//			check_font_load(number_font, Arial_font);
//			setScoreText(Arial_font);
//
//			RectangleShape enemies_shapes[10];
//			setEnemiesShapes(nEnemy, enemies_shapes);
//			// time 
//			time_t first_second, this_second;
//			time(&first_second);
//			int second = 0, minute = 0;
//			//time text
//			Text time_text, PercentText, heartText, nametext;
//			if (Arial_font.loadFromFile("Data/levels.ttf") == false)
//				std::cout << "erorr in loading Font";
//			nametext.setFont(Arial_font);
//			nametext.setFillColor(Color::Green);
//			nametext.setPosition(570, 630);
//			nametext.setCharacterSize(30);
//			setTimeText(number_font, time_text);
//			//Percent Text
//			setPercentText(Arial_font, PercentText);
//			//heart Text
//			setHeartText(Arial_font, heartText);
//			//player rectangle
//			RectangleShape player;
//			player_rectangle(player);
//			//under bound rectangle 
//			RectangleShape bound;
//			bound.setFillColor(Color::Red);
//			bound.setPosition(0, 620);
//			bound.setSize(Vector2f(820, 5));
//			// event
//			Event event;
//			//sound
//			// sound track while the game is playing
//			Music music;
//			if (!music.openFromFile("Data/soundtrack.ogg"))
//				cout << "error in load sound";
//			music.play();
//			SoundBuffer sound;
//			Sound collisionSound;
//			if (sound.loadFromFile("Data/impact.wav"))
//				cout << "collision done " << endl;
//			collisionSound.setBuffer(sound);
//
//			while (play)     //this move one page
//			{
//
//				Sprite Sgrid;
//				int percent = 0;
//				percent = checkBoundaries() / (44);
//				updateScore();
//				calculateScore(minute, second, percent);
//
//				// time string 
//				stringstream time_string, areaString, heartString, nameString;
//				nameString << playername;
//				nametext.setString(nameString.str());
//				heartString << heart;
//				heartText.setString(heartString.str());
//				areaString << "You Finished " << percent << "%";
//				PercentText.setString(areaString.str());
//				//setting time 
//				setTime(this_second, second, minute, first_second, time_string);
//
//				while (window_Level_one.pollEvent(event))
//				{
//					if (event.type == Event::Closed)
//					{
//						window_Level_one.close();
//						start = 0;
//						play = false;
//					}
//					if (Keyboard::isKeyPressed(Keyboard::Escape))
//					{
//						play = false;
//					}
//					if (Keyboard::isKeyPressed(Keyboard::Up)) 		dir = Up;
//					else if (Keyboard::isKeyPressed(Keyboard::Down))	dir = Down;
//					else if (Keyboard::isKeyPressed(Keyboard::Right))	dir = Right;
//					else if (Keyboard::isKeyPressed(Keyboard::Left))	dir = Left;
//					/*	for (int l = 0; l < nEnemy; l++)
//					{
//					for (int k = 1; k < nEnemy; k++)
//					if (enemies_shapes[l].getGlobalBounds().intersects(enemies_shapes[k].getGlobalBounds()))
//					{
//					enemies_struct[l].expostion = -enemies_struct[l].expostion;
//					enemies_struct[l].eypostion = -enemies_struct[l].eypostion;
//					enemies_struct[k].expostion = -enemies_struct[k].expostion;
//					enemies_struct[k].eypostion = -enemies_struct[k].eypostion;
//					}
//					}*/
//				}
//				//enemy move
//				moveEnemy(nEnemy);// activate it when you want to cut pieces of the pink line and remove it below :)
//				// boundaries that anything can't go after it like player
//				//player movement in the Grid 
//				movePlayer(xpos, ypos, dir);
//				player.setPosition(xpos * 10, ypos * 10);
//				time_text.setString(time_string.str());
//				//check player-enemy collision
//				checkCollision(nEnemy, enemies_shapes, collisionSound);
//				//moveEnemy(nEnemy);
//
//				/*	for (int i = 0; i < 82; i++)
//				{
//				for (int j = 0; j < 62; j++)
//				{
//				if (player.getPosition().x == grid[i][j] == 2 || player.getPosition().y == grid[i][j] == 2)
//				play = false;
//				}
//				}*/
//				setsBrush(xpos, ypos);
//				//draw
//				Texture image1;
//				if (image1.loadFromFile("Data/picture8.jpg") == false)
//				{
//					cout << "image is not here";
//				}
//				Sprite picture1(image1);
//				window_Level_one.clear();
//				if (defaultmode == true)
//				{
//					for (int i = 0; i <= 82; i++)
//					{
//						for (int j = 0; j <= 62; j++)
//						{
//							if (grid[i][j] == 1 || grid[i][j] == 2)
//							{
//								picture1.setTextureRect(IntRect(i * 10, j * 10, 10, 10));
//								picture1.setPosition(i * 10, j * 10);
//								window_Level_one.draw(picture1);
//							}
//						}
//					}
//				}
//				else
//				{
//					drawArea(Sgrid, window_Level_one, image, image2);
//				}
//
//				window_Level_one.draw(player);
//				window_Level_one.draw(sprite3);
//				window_Level_one.draw(bound);
//				for (int i = 0; i < nEnemy; i++) {
//					window_Level_one.draw(enemies_shapes[i]);
//				}
//				window_Level_one.draw(time_text);
//				window_Level_one.draw(heartText);
//				window_Level_one.draw(nametext);
//				window_Level_one.draw(PercentText);
//				window_Level_one.draw(labelscore);
//
//
//
//				window_Level_one.display();
//				///////////////////////
//				reply_level(play, music, xpos, ypos);
//
//			}
//			win(window_Level_one);
//			/*	if (replay == true)
//			{
//			replay = false;
//			set_grid_0();
//			///needs more expermenting now it has been fixed :)
//			part_level_one(level_number);
//			}*/
//		}
//	}
//}
//
//void part_level_Custom(int& level_number, string* name) {
//	string levelgrid = "$";
//	FilesHandler levelsFile;
//	{
//		if (level_number == 8)
//		{
//			bool level_play = true, end_levels_2 = true, end_levels = true;
//			while (level_play)   //this move on all levels
//			{
//				//custom
//				RenderWindow window_Custom(VideoMode(ScreenWidth, ScreenHeight), "Custom", Style::Close);//render window_play 
//				Custom custom(ScreenWidth, ScreenHeight);  //to take object from class  
//				while (window_Custom.isOpen())
//				{
//					Event event2;
//					while (window_Custom.pollEvent(event2))
//					{
//						if (event2.type == Event::Closed)
//						{
//							window_Custom.close();
//							level_play = false;
//							end_levels = false;
//
//						}
//						if (Keyboard::isKeyPressed(Keyboard::Escape))
//						{
//							level_play = false;
//							end_levels = false;
//						}
//						if (event2.type == Event::KeyReleased)
//						{
//							if (event2.key.code == Keyboard::Up)
//							{
//								custom.moveUp();
//								break;
//							}
//							if (event2.key.code == Keyboard::Down)
//							{
//								custom.moveDown();
//								break;
//							}
//						}
//
//						//choice level
//						if (event2.key.code == Keyboard::Enter)   // Return == I pressed enter
//						{
//							for (int i = 0; i < 3; i++)
//							{
//								if (custom.mainCustomPressed() == i && i == 2)
//								{
//									//page_Custom = 3;
//									level_number = 9;
//								}
//								else {
//									if (custom.mainCustomPressed() == i)    //  level 1
//									{
//										window_Custom.close();				//close the main window and open window.1
//										page_Custom = i;
//
//									}
//								}
//							}
//
//						}
//						if (end_levels == false)
//							break;
//					}
//
//					window_Custom.clear();
//					if (page_Custom == 2)
//					{
//						//main menu
//						end_levels_2 = false;
//						end_levels = false;
//						break;
//					}
//					else {
//						custom.draw(window_Custom);
//						window_Custom.display();
//					}
//
//
//					if (end_levels == false)
//						break;
//				}
//				if (end_levels == false)
//					break;
//				if (page_Custom == 0)
//					Custom_make_level(page_Custom);
//				if (page_Custom == 1)
//				{
//					window_Custom.close();
//					break;
//				}
//			}
//			if (page_Custom == 1)
//			{
//				//load custom level page
//				string levelgrid = "$";
//				FilesHandler levelsFile;
//				bool level_play = true, end_levels_2 = true, end_levels = true;
//				name = levelsFile.check_levels("levels.txt");
//				name[0] = "Test yamooo";
//				while (level_play)   //this move on all levels
//				{
//					//play levels
//					RenderWindow window_Levels(VideoMode(ScreenWidth, ScreenHeight), " Custom Levels", Style::Close);//render window_play 
//					levels Levels(ScreenWidth, ScreenHeight, 1, window_Levels, name);  //to take object from class  
//
//					while (window_Levels.isOpen())
//					{
//						Event event2;
//						while (window_Levels.pollEvent(event2))
//						{
//							if (event2.type == Event::Closed)
//							{
//								window_Levels.close();
//								level_play = false;
//								end_levels = false;
//
//							}
//							if (Keyboard::isKeyPressed(Keyboard::Escape))
//							{
//								level_play = false;
//								end_levels = false;
//							}
//							if (event2.type == Event::KeyPressed)
//							{
//								if (event2.key.code == Keyboard::Up)
//								{
//									Levels.moveUp(1);
//									break;
//								}
//								if (event2.key.code == Keyboard::Down)
//								{
//									Levels.moveDown(1);
//									break;
//								}
//								if (event2.key.code == Keyboard::Enter)   // Return == I pressed enter
//								{
//									for (int i = 0; i < 10; i++)
//									{
//
//
//										if (Levels.mainClevelsPressed() == i)    //  level 1
//										{
//											if (i == 9)
//											{
//												//level_number = 3;
//												page_number = 9;
//											}
//											window_Levels.close();				//close the main window and open window.1
//											Clevel_number = i;
//											break;
//
//										}
//
//									}
//								}
//
//								//choice level
//
//
//							}
//							if (end_levels == false)
//								break;
//						}
//
//						window_Levels.clear();
//						//if (page_number == 9)
//						//{
//						//	//main menu
//						//	end_levels_2 = false;
//						//	end_levels = false;
//						//	break;
//						//}
//						Levels.display_customLevels(name, window_Levels);
//
//						window_Levels.display();
//
//
//
//						if (end_levels == false)
//							break;
//					}
//					if (end_levels == false)
//						break;
//					if (Clevel_number != -1)
//						break;
//					/*part_level_one(level_number);
//					part_level_two(level_number);
//					part_level_three(level_number);
//					part_level_four(level_number);
//					part_level_five(level_number);
//					part_level_six(level_number);
//					part_level_seven(level_number);
//					part_level_eight(level_number);
//					part_level_Custom(level_number, name);*/
//
//
//				}
//				if (Clevel_number != -1)
//				{
//					load_custom_level(Clevel_number, levelgrid, levelsFile);
//					level_number = 0;
//					part_level_one(level_number);
//				}
//
//			}
//
//		}
//	}
//}
//
//void part_play(int page_number)
//{
//
//	FilesHandler scores;
//	FilesHandler standardLevels;
//	if (page_number == 0)
//	{
//		//score system
//
//
//
//		bool level_play = true, end_levels_2 = true, end_levels = true;
//		while (level_play)   //this move on all levels
//		{
//			//play levels
//			RenderWindow window_Levels(VideoMode(ScreenWidth, ScreenHeight), "Levels", Style::Close);//render window_play 
//			levels Levels(ScreenWidth, ScreenHeight, 0, window_Levels, name);  //to take object from class  
//			while (window_Levels.isOpen())
//			{
//				Event event2;
//				while (window_Levels.pollEvent(event2))
//				{
//					if (event2.type == Event::Closed)
//					{
//						window_Levels.close();
//						level_play = false;
//						end_levels = false;
//
//					}
//					if (Keyboard::isKeyPressed(Keyboard::Escape))
//					{
//						level_play = false;
//						end_levels = false;
//					}
//					if (event2.type == Event::KeyPressed)
//					{
//						if (event2.key.code == Keyboard::Up)
//						{
//							Levels.moveup();
//							break;
//						}
//						if (event2.key.code == Keyboard::Down)
//						{
//							Levels.moveDown();
//							break;
//						}
//						//choice level
//						if (event2.key.code == Keyboard::Enter)   // Return == I pressed enter
//						{
//							for (int i = 0; i < 10; i++)
//							{
//
//
//								if (Levels.mainlevelsPressed() == i)    //  level 1
//								{
//									if (i == 9)
//									{
//										//level_number = 3;
//										page_number = 9;
//									}
//									window_Levels.close();				//close the main window and open window.1
//									level_number = i;
//
//								}
//
//							}
//
//						}
//					}
//
//
//					if (end_levels == false)
//						break;
//				}
//
//				window_Levels.clear();
//				if (page_number == 9)
//				{
//					//main menu
//					end_levels_2 = false;
//					end_levels = false;
//					break;
//				}
//				else {
//					Levels.draw(window_Levels);
//					window_Levels.display();
//				}
//
//
//				if (end_levels == false)
//					break;
//			}
//			if (end_levels == false)
//				break;
//			switch (level_number)
//			{
//			case 0:
//				set_grid_0();
//				name = standardLevels.check_levels("standardLevels.txt");
//				standardLevels.load_level("level 1", "standardLevels.txt");
//				part_level_one(level_number);
//				break;
//			case 1:
//				set_grid_0();
//				name = standardLevels.check_levels("standardLevels.txt");
//				standardLevels.load_level("level 2", "standardLevels.txt");
//				part_level_two(level_number);
//				break;
//			case 2:
//				set_grid_0();
//
//				name = standardLevels.check_levels("standardLevels.txt");
//
//				standardLevels.load_level("level 3", "standardLevels.txt");
//				part_level_three(level_number);
//
//				break;
//			case 3:
//				//name = standardLevels.check_levels("standardLevels.txt");
//
//				//standardLevels.load_level("level 4", "standardLevels.txt");
//				part_level_four(level_number);
//				break;
//			case 4:
//				name = standardLevels.check_levels("standardLevels.txt");
//
//				standardLevels.load_level("level 5", "standardLevels.txt");
//				part_level_five(level_number);
//				break;
//			case 5:
//				name = standardLevels.check_levels("standardLevels.txt");
//
//				standardLevels.load_level("level 6", "standardLevels.txt");
//				part_level_six(level_number);
//				break;
//			case 6:
//				name = standardLevels.check_levels("standardLevels.txt");
//
//				standardLevels.load_level("level 7", "standardLevels.txt");
//				part_level_seven(level_number);
//				break;
//			case 7:
//				name = standardLevels.check_levels("standardLevels.txt");
//				standardLevels.load_level("level 8", "standardLevels.txt");
//				part_level_eight(level_number);
//				break;
//
//			default:
//				break;
//			}
//
//			if (level_number == 8)
//			{
//				window_Levels.close();
//				break;
//			}
//
//		}
//		if (level_number == 8)
//			part_level_Custom(level_number, name);
//
//	}
//}
//
//
//
//
//
//void part_Credits(int page_number)
//{
//	if (page_number == 1)
//	{
//		//credits
//		sf::RenderWindow window_Credits(VideoMode(ScreenWidth, ScreenHeight), "credits", sf::Style::Close);
//		bool play = true;
//		Texture background;
//		if (!background.loadFromFile("Data/logo2.jpg"))
//			std::cout << "error in load photo of shape" << std::endl;
//		RectangleShape photo;
//		photo.setSize(Vector2f(820, 680));
//		photo.setPosition(0, 0);
//		photo.setTexture(&background);
//		Font levels;
//		Text member[10];
//		for (int i = 0; i < 7; i++)
//		{
//			//member
//
//
//			if (levels.loadFromFile("Data/menu.ttf") == false)
//				std::cout << "erorr in loading Font";
//			member[i].setFont(levels);
//			member[i].setFillColor(Color::White);
//
//			member[i].setCharacterSize(50);
//		}
//		member[0].setPosition(20, 50);
//		member[1].setPosition((ScreenWidth / 3), 150);
//		member[2].setPosition((ScreenWidth / 3), 200);
//		member[3].setPosition((ScreenWidth / 3), 250);
//		member[4].setPosition((ScreenWidth / 3), 300);
//		member[5].setPosition((ScreenWidth / 3), 350);
//		member[6].setPosition((ScreenWidth / 3), 400);
//
//		while (play)
//		{
//
//			stringstream  memberString[10];
//			memberString[0] << "X_onix Was made by:";
//			member[0].setString(memberString[0].str());
//			memberString[1] << "Sulieman Snossy";
//			member[1].setString(memberString[1].str());
//			memberString[2] << "Ahmed Mohamed Hassan";
//			member[2].setString(memberString[2].str());
//			memberString[3] << "Ahmed Abulfarh";
//			member[3].setString(memberString[3].str());
//			memberString[4] << "Ahmed Hussien";
//			member[4].setString(memberString[4].str());
//			memberString[5] << "Al-Walid Oumouri";
//			member[5].setString(memberString[5].str());
//
//
//			while (window_Credits.isOpen())
//			{
//				sf::Event event;
//				while (window_Credits.pollEvent(event))
//				{
//					if (event.type == sf::Event::Closed)
//						window_Credits.close();
//					if (Keyboard::isKeyPressed(Keyboard::Escape))
//						play = false;
//				}
//				window_Credits.clear();
//				//window_Credits.draw(photo);
//				for (int i = 0; i < 6; i++)
//				{
//					window_Credits.draw(member[i]);
//				}
//				window_Credits.display();
//			}
//		}
//	}
//}
//
//void part_option(int page_number)
//{
//	if (page_number == 2)
//	{
//		//option
//		sf::RenderWindow window_option(VideoMode(ScreenWidth, ScreenHeight), "option", sf::Style::Close);
//		bool play = true;
//		while (play)
//		{
//			while (window_option.isOpen())
//			{
//				sf::Event event;
//				while (window_option.pollEvent(event))
//				{
//					if (event.type == sf::Event::Closed)
//						window_option.close();
//					if (Keyboard::isKeyPressed(Keyboard::Escape))
//						play = false;
//				}
//				window_option.clear();
//
//				window_option.display();
//			}
//		}
//	}
//}
//
//void load_custom_level(int& CLevelnumber, string& levelgrid, FilesHandler& levelsFile)
//{
//
//	int i = 0;
//	string levels[9] = {};
//	//CustomLevels.nCustom_level = 5;
//	name = levelsFile.check_levels("levels.txt");
//	for (i = 0; i < 9; i++)
//	{
//
//		levels[i] = *(name + i);
//		cout << "level" << i << ":" << levels[i] << "\n";
//	}
//	levelgrid = levelsFile.load_level(name[Clevel_number], "levels.txt");
//	cout << "THe grid  : ";
//	int k = 0;
//	for (int i = 0; i < 82; i++)
//	{
//
//		for (int j = 0; j < 62; j++)
//		{
//
//
//			if (levelgrid[k] == '1')
//			{
//				grid[i][j] = 1;
//			}
//
//			else if (levelgrid[k] == '0')
//			{
//				grid[i][j] = 0;
//
//			}
//			else if (levelgrid[k] == '3')
//				grid[i][j] = 3;
//
//			cout << "" << grid[i][j];
//			k++;
//		}
//		//cout << endl; 
//	}
//}
//
//void set_grid_0()
//{
//	//nested loop to set grid to 0
//	for (int i = 0; i < Rows; i++)
//		for (int j = 0; j < Coulmns; j++)
//			grid[i][j] = 0;
//}
//void check_images_borders_load(Texture& image, Texture& image2, Texture& image3) {
//	if (image.loadFromFile("Data/borders.png") == false)
//		cout << "image is not here";
//	if (image2.loadFromFile("Data/borders1.png") == false)
//		cout << "image2 is not here";
//	if (image3.loadFromFile("Data/heart.png") == false)
//		cout << "image3 is not here";
//}
//
//void check_font_load(Font& number_font, Font& Arial_font) {
//	//font  
//	if (number_font.loadFromFile("Data/numbers_font.ttf") == false)
//		cout << "font is not here";
//	if (Arial_font.loadFromFile("Data/arial.ttf") == false)
//		exit(1);
//
//}
//void player_rectangle(RectangleShape& player) {
//	//player rectangle 
//
//	player.setFillColor(Color::Magenta);
//	player.setPosition(0, 0);
//	player.setSize(Vector2f(10, 10));
//	player.setOrigin(5, 5);
//
//}
//
//void Custom_make_level(int page_Custom) {
//	set_grid_0();
//	string levelgrid = "$";
//	sf::RenderWindow window(sf::VideoMode(820, 680), "Xonix");//render window
//	window.setFramerateLimit(30);//set frames to 60 per second
//	bool play = true;
//	bool top = false, down = false, right = false, left = false; //key pressed bools
//	bool paint = false, clear = false, trap = false;
//	int xpos = 0, ypos = 0; //playes position
//	int x_paint = 0, y_paint = 0;
//
//	Texture image3;
//	if (image3.loadFromFile("Data/borders3.png") == false)
//	{
//		cout << "image is not here";
//		return; // end the program
//	}
//	Texture image2;
//	if (image2.loadFromFile("Data/borders1.png") == false)
//	{
//		cout << "image is not here";
//		return; // end the program
//	}
//
//	//font
//	Font number_font;
//	if (number_font.loadFromFile("Data/numbers_font.ttf") == false)
//	{
//		cout << "font is not here";
//		return; // end the program
//	}
//	sf::RectangleShape enemies_shapes[8];
//	for (int i = 0; i < 8; i++) {
//		enemies_shapes[i].setSize(Vector2f(10, 10));
//		enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
//
//	}
//	///////
//
//	//time
//	time_t first_second, this_second;
//	time(&first_second);
//	int second = 0, minute = 0;
//	//Instructions Text: 
//	Text instructions; Font levels;
//	if (levels.loadFromFile("Data/ARIALNI.ttf") == false)
//		std::cout << "erorr in loading Font";
//	instructions.setFont(levels);
//	instructions.setFillColor(Color::Green);
//	instructions.setPosition(0, 640);
//	instructions.setCharacterSize(20);
//	//time text
//	Text time_text;
//	time_text.setFont(number_font);
//	time_text.setFillColor(Color::Red);
//	time_text.setPosition(0, 640);
//	time_text.setCharacterSize(20);
//	//player rectangle
//	RectangleShape player;
//	player.setFillColor(Color::Magenta);
//	player.setPosition(400, 300);
//	player.setSize(Vector2f(10, 10));
//	//under bound rectangle
//	RectangleShape bound;
//	bound.setFillColor(Color::Red);
//	bound.setPosition(0, 620);
//	bound.setSize(Vector2f(820, 5));
//	// event
//	Event event;
//	FilesHandler levelsFile;
//	Sprite Sgrid;
//	stringstream time_string;
//	while (play)
//	{
//		stringstream instructString;
//		instructString << "Blue Color :: press b		Red Color :: press r	 save/print :: press p	Clear :: press c	  draw :: press Enter";
//		instructions.setString(instructString.str());
//		setTime(this_second, second, minute, first_second, time_string);
//
//		while (window.pollEvent(event))
//		{
//			time_string.clear();
//			if (event.type == Event::Closed)
//			{
//				play = false;
//			}
//			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
//				top = true;
//			}
//			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down)
//			{
//				down = true;
//			}
//			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right)
//			{
//				right = true;
//			}
//			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
//			{
//				left = true;
//			}
//			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
//			{
//				top = false;
//			}
//
//			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
//			{
//				down = false;
//			}
//			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
//			{
//				right = false;
//			}
//
//			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
//			{
//				left = false;
//			}
//			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::B)
//			{
//				if (paint == true)
//					paint = false;
//				else
//				{
//					paint = true;
//					clear = false;
//					trap = false;
//				}
//			}
//			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::C)
//			{
//				if (clear == true)
//					clear = false;
//				else
//				{
//					clear = true;
//					paint = false;
//					trap = false;
//				}
//			}
//			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R)
//			{
//				if (trap == true)
//					trap = false;
//				else
//				{
//					trap = true;
//					paint = false;
//					clear = false;
//				}
//			}
//			string levelname = "";
//
//			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::P)
//			{
//				for (int i = 0; i < 82; i++)
//				{
//					for (int j = 0; j < 62; j++)
//					{
//						levelgrid += to_string(grid[i][j]);
//
//					}
//					cout << endl;
//
//				}
//				cout << levelgrid;
//				levelgrid += "$";
//				cout << "Enter level name here : ";
//				cin >> levelname;
//				levelsFile.write_custom_Level(levelgrid, levelname, "standardLevels.txt");
//			}
//			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D)
//			{
//				set_grid_0();
//			}
//		}
//		if (event.type == sf::Event::MouseMoved)
//		{
//
//			if (paint == true)
//			{
//				xpos = event.mouseMove.x / 10;
//				ypos = event.mouseMove.y / 10;
//			}
//			else if (clear == true)
//			{
//				xpos = event.mouseMove.x / 10;
//				ypos = event.mouseMove.y / 10;
//			}
//			else if (trap == true)
//			{
//				xpos = event.mouseMove.x / 10;
//				ypos = event.mouseMove.y / 10;
//			}
//		}
//		int numberofenemy = 7;
//		//player move
//		if (top == true)
//		{
//			ypos -= 1;
//		}
//		else if (down == true)
//		{
//			ypos += 1;
//		}
//		else if (right == true)
//		{
//			xpos += 1;
//		}
//		else if (left == true)
//		{
//			xpos -= 1;
//		}
//		if (x_paint != xpos)
//			x_paint = xpos;
//		if (y_paint != ypos)
//			y_paint = ypos;
//		if (paint == true)
//		{
//			grid[xpos][ypos] = 1;
//		}
//		else if (clear == true)
//		{
//			grid[x_paint][y_paint] = 0;
//		}
//		else if (trap == true)
//		{
//			grid[xpos][ypos] = 3;
//		}
//		// bound moving
//		if (xpos >= 82)
//			xpos -= 1;
//		if (xpos < 0)
//			xpos += 1;
//		if (ypos >= 62)
//			ypos -= 1;
//		if (ypos < 0)
//			ypos += 1;
//		player.setPosition(xpos * 10, ypos * 10);
//		time_text.setString(time_string.str());
//
//		//draw
//		window.clear();
//		window.draw(instructions);
//		for (int i = 0; i < 82; i++)
//			for (int j = 0; j < 62; j++)
//			{
//				if (grid[i][j] == 0)
//				{
//					continue;
//				}
//				if (grid[i][j] == 1)
//				{
//					Sgrid.setTexture(image2);
//				}
//				if (grid[i][j] == 3)
//				{
//					Sgrid.setTexture(image3);
//				}
//				Sgrid.setPosition(i * 10, j * 10);
//				window.draw(Sgrid);
//			}
//
//		window.draw(player);
//		window.draw(bound);
//
//		//window.draw(time_text);
//		window.display();
//	}
//}
//
//
//
//
