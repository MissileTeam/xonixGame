#include "Level.h"
#define ScreenWidth 820
#define ScreenHeight 680

Level::Level(short nEnemy)
{
	//Rendering level window
	load_fonts();
	load_images();
	load_sounds();
	IntialiseLevel("standardLevels.txt", "two");
	RenderWindow levelWindow(VideoMode(ScreenWidth, ScreenHeight),"Level",Style::Default);
	//sprite3(image3);
	sprite3.setPosition(Vector2f((ScreenWidth / 3 - 50), 633));
	setTimeText();
	//Percent Text
	setPercentText(arial, PercentText);
	//heart Text
	setHeartText(arial, heartText);
	setScoreText(arial);
	//player rectangle
	
	setPlayerShape();
	setEnemiesShapes(nEnemy, enemies_shapes,10);

	//drawing boundry 
	setBoundaries();
	levelWindow.setFramerateLimit(60);
	sprite3.setTexture(image3);
	music.play();
	music.setLoop(true);
	while (play)
	{
		
		//to clear time string 
		time_string.str("");
		areaString.str("");
		heartString.str("");
		while (levelWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				levelWindow.close();
				play = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				levelWindow.close();
				play = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Up)) 		    dir = 'U';
			else if (Keyboard::isKeyPressed(Keyboard::Down))	dir ='D';
			else if (Keyboard::isKeyPressed(Keyboard::Right))	dir = 'R';
			else if (Keyboard::isKeyPressed(Keyboard::Left))	dir ='L';
		}
	//	setTimer(seconds,minute,time_string)
		setTimer(seconds, minutes, time_string);
		checkCompletion(percent, old_percent);
		CalculateScore();
		
		moveEnemy(nEnemy);
		for(int i=0;i<nEnemy;i++)
		rules_of_draw(enemies_struct[i].expostion / 10, enemies_struct[i].eypostion / 10);
		movePlayer(xpos, ypos, dir);
		player.setPosition(xpos * 10, ypos * 10);
		checkCollision(nEnemy, enemies_shapes, xpos, ypos, play);
		//time_string.clear();
		
		setBrush(xpos, ypos);
		//player movement in the Grid 
		scorecalc(score, seconds);
		//time_text.setString(time_string.str());
		levelWindow.clear();
		drawArea(Sgrid, levelWindow, image1, image2,grid);
		updatePercenetText();
		updateHeartText();
		levelWindow.draw(player);
	levelWindow.draw(sprite3);
		levelWindow.draw(bound);
		for (int i = 0; i < nEnemy; i++) {
			levelWindow.draw(enemies_shapes[i]);
		}
		levelWindow.draw(time_text);
		levelWindow.draw(heartText);
		levelWindow.draw(PercentText);
		levelWindow.draw(labelscore);
		levelWindow.draw(sprite3);
		
		levelWindow.display();

	}
	
	
}


void Level::load_images()
{
	if (image1.loadFromFile("Data/borders.png") == false)
		cout << "image is not here";
	if (image2.loadFromFile("Data/borders1.png") == false)
		cout << "image2 is not here";
	if (image3.loadFromFile("Data/heart.png") == false)
		cout << "image3 is not here";
}
void Level::load_fonts()
{
	//font  
	if (number_font.loadFromFile("Data/numbers_font.ttf") == false)
		cout << "font is not here";
	if (arial.loadFromFile("Data/arial.ttf") == false)
		cout << "font is not here";
	if (menu.loadFromFile("Data/menu.ttf") == false)
		cout << "font is not here";
}
void Level::load_sounds()
{
	if (collisionBuf.loadFromFile("Data/impact.wav"))
		cout << "collision done " << endl;
	collisionSound.setBuffer(collisionBuf);

	if (completionBuf.loadFromFile("Extra_images/CompleteDraw.ogg"))
		cout << "collision done " << endl;
	completion.setBuffer(completionBuf);

	if (windowPressBuf.loadFromFile("Data/completion.wav"))
		cout << "collision done " << endl;
	windowPressed.setBuffer(windowPressBuf);

	if (music.openFromFile("Data/soundtrack.ogg"))
		cout << "collision done " << endl;
	

}
void Level::setTimer( int& second, int& minute, stringstream& time_string)
{
	//works great
	second = clock.getElapsedTime().asSeconds();
	/*time_string.clear();
	time_string << "Time " << "0" << minute << " :0 " << second;*/
	if (second >= 60)
	{
		minute++;
		second = clock.restart().asSeconds() - second;

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
		if (clock.getElapsedTime().asSeconds() < 10)
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

	time_text.setString(time_string.str());

}
void Level::setLives(short& hearts)
{
	heart = hearts;
}
void Level::setBoundaries()
{
	bound.setFillColor(Color::Red);
	bound.setPosition(0, 620);
	bound.setSize(Vector2f(820, 5));
}
int Level::getLives()
{
	return heart;
}
void Level::setTimeText()
{
	time_text.setFont(number_font);
	time_text.setFillColor(Color::Red);
	time_text.setPosition(0, 640);
	time_text.setCharacterSize(20);
}
void Level:: setScoreText(Font& Arial_font)
{
	score = 0;
	scoreString << "Score : " << score;
	labelscore.setCharacterSize(20);
	labelscore.setPosition({ 30, 50 });
	labelscore.setFont(Arial_font);
	labelscore.setString(scoreString.str());
	labelscore.setFillColor(Color::Green);


}
void Level::setHeartText(Font& Arial_font, Text& heartText)
{
	heartText.setFont(Arial_font);
	heartText.setFillColor(Color::Green);
	heartText.setPosition((820 / 4), 633);
	heartText.setCharacterSize(30);
}
void Level::setPercentText(Font& Arial_font, Text& PercentText)
{
	PercentText.setFont(Arial_font);
	PercentText.setFillColor(Color::Green);
	PercentText.setPosition(370, 630);
	PercentText.setCharacterSize(30);
}

void Level::updatePercenetText()
{
	areaString << "You Finished " << percent << "%";
	PercentText.setString(areaString.str());
}

void Level::updateHeartText()
{
	heartString << heart;
	heartText.setString(heartString.str());
}

void Level::moveEnemy(short nEnemy)
{

	for (int i = 0; i < nEnemy; i++) {
		enemies_struct[i].motion(grid);
		
	}
}
void Level::rules_of_draw(int ex, int ey)
{
	
		if (grid[ex][ey] == 0)
			grid[ex][ey] = -1;



		// strange error happens here becuase the random position of the enemy  y =- number;

		if (grid[ex - 1][ey] == 0)

			rules_of_draw(ex - 1, ey);

		if (grid[ex + 1][ey] == 0)

			rules_of_draw(ex + 1, ey);

		if (grid[ex][ey + 1] == 0)

			rules_of_draw(ex, ey + 1);

		if (grid[ex][ey - 1] == 0)

			rules_of_draw(ex, ey - 1);
	
		
}

void Level::setBrush(int& xpos, int& ypos)
{
	for (int i = 0; i < 82; i++)
		for (int j = 0; j < 62; j++)
		{
		

			if (grid[xpos][ypos] == 1)
			{

				if (grid[i][j] == -1)
					grid[i][j] = 0;
				else if (grid[i][j] == 3)
					grid[i][j] = 3;
				else
					grid[i][j] = 1;


			}
			else
			{
				if (grid[i][j] == -1)
					grid[i][j] = 0;

				else if (grid[i][j] == 2)
					grid[i][j] = 2;
				else if (grid[i][j] == 3)      ///new thing to add
					grid[i][j] = 3;
				else if (grid[i][j] == 0)
					grid[i][j] = 1;
			}
		}
}

void Level::setEnemiesShapes(short& nEnemy, RectangleShape enemies_shapes[], short scale)
{
	for (int i = 0; i < nEnemy; i++) {
		enemies_shapes[i].setSize(Vector2f(scale, scale));
		enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
		enemies_shapes[i].setFillColor(Color::Red);
	}
}

void Level::movePlayer(int& xpos, int& ypos, char& dir)
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
		if (dir == 'U')	ypos -= 1;

		else if (dir =='D')	ypos += 1;

		else if (dir =='R')	xpos += 1;

		else if (dir =='L')	xpos -= 1;
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

void Level::CalculateScore()
{
	FilesHandler scores;

	score = score / 44;
	do {

		if (((seconds < 40) || (heart == 3)) && (percent >= 70))
		{

			bonus = (score * 25 / 100);
			score = score + bonus;
			scores.writeScore(score, highscore, "Level 1 : ");
			cout << "You hit new score" << endl;
			break;
		}
		else
			break;

	} while (true);
}

void Level:: scorecalc(int& score, int time) {

	if (heart == 3) {
		/*if (time < 10)
			score = score + 100;
		if (time < 20 && time >10)
			score = score + 80;*/
		if (time <= 40 && time > 39)
			score = score + 60;
		/*	else
				score = score + 30;*/
	}
	else if (heart == 2) {

		if (time < 40 && time >38)
			score = score + 50;

		else if (heart == 1 && (time < 45 && time>43))
			score = score + 20;


	}
	scoreString.str("");
	scoreString << "Score:" << score;
	labelscore.setString(scoreString.str());
}

void Level::drawArea(Sprite &Sgrid, RenderWindow& window, Texture& image, Texture& image2, int grid[][62])
{
	Sgrid.setOrigin(5, 5);
	for (int i = 0; i < 82; i++)
		for (int j = 0; j < 62; j++)
		{

			if (grid[i][j] == 0)
			{
				continue;
			}
			if (grid[i][j] == 1)
			{
				Sgrid.setColor(Color::White);

				Sgrid.setTexture(image2);
			}
			if (grid[i][j] == 2)
			{
				Sgrid.setColor(Color::White);

				Sgrid.setTexture(image);
			}
			if (grid[i][j] == 3)
			{
				Sgrid.setColor(Color::Yellow);
				Sgrid.setTexture(image);
			}
			Sgrid.setPosition(i * 10, j * 10);

			window.draw(Sgrid);

		}
}

void Level::setPlayerShape()
{
	//player rectangle 

	player.setFillColor(Color::Magenta);
	player.setPosition(0, 0);
	player.setSize(Vector2f(10, 10));
	player.setOrigin(5, 5);

}

//void Level::setEnemiesShapes(short& nEnemy, RectangleShape enemies_shapes[], short scale,enemy enmies_struct[])
//{
//	for (int i = 0; i < nEnemy; i++) {
//		enemies_shapes[i].setSize(Vector2f(scale, scale));
//		enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);
//		enemies_shapes[i].setFillColor(Color::Red);
//	}
//}

void Level::IntialiseLevel(string levelsFile, string levelName)
{
	string levelgrid = "$";
	FilesHandler Level_loader;
	levelgrid = Level_loader.load_level(levelName, levelsFile);
	cout << "levelgrid:" << levelgrid;
	cout << "THe grid  : ";
	int k = 0;
	for (int i = 0; i < 82; i++)
	{

		for (int j = 0; j < 62; j++)
		{


			if (levelgrid[k] == '1')
			{
				grid[i][j] = 1;
			}

			else if (levelgrid[k] == '0')
			{
				grid[i][j] = 0;

			}
			else if (levelgrid[k] == '3')
				grid[i][j] = 3;

			cout << "" << grid[i][j];
			k++;
		}
		//cout << endl; 
	}
}

void Level::checkCollision(short nEnemy, RectangleShape enemies_shapes[], int& xpos, int& ypos, bool& play)
{
	for (int i = 0; i < nEnemy; i++)
	{
		enemies_shapes[i].setPosition(enemies_struct[i].expostion, enemies_struct[i].eypostion);


		if (grid[enemies_struct[i].expostion / 10][enemies_struct[i].eypostion / 10] == 2)
		{
			heart--;
			collisionSound.play();
			//make the enemy destroy your line "Nice"
			//grid[enemies_struct[i].expostion / 10][enemies_struct[i].eypostion / 10] = -1;
			//this_thread::sleep_for(.2s);
			for (int i = 0; i < 82; i++)
				for (int j = 0; j < 62; j++)
					if (grid[i][j] == 2)
						grid[i][j] = -1;

			//play = false;
		}
		if (grid[xpos][ypos] == 3)
		{
			heart = 0;
			//play = false;

		}

	}
}



int* Level::getGrid()
{
	int* gridptr = &grid[0][0];
	return gridptr;
}

//void Level::checkCollision(short nEnemy, RectangleShape enemies_shapes[], Sound& collisionSound, int& xpos, int& ypos, bool& play)

