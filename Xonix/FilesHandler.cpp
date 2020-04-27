#include "FilesHandler.h"
using namespace std;
string FilesHandler::load_level(string levelName,string fileName)
{
	short i = 0;
	string data = ""; short dolarPosition = 0;
	inputFile.open(fileName);
	if (grid.find('0') & grid.find('1'))
	{
		inputFile.seekg(dolarPosition);
		cout << "it is good  to load the file";
		while (inputFile.good())
		{
			if (i == 2)
				break;
			inputFile.seekg(dolarPosition);

			while (getline(inputFile, data))
			{
				if (data == levelName)
				{
					if (data.find_first_of("$") == -1)
					{
						inputFile.seekg((int)inputFile.tellg());
						inputFile >> data;
						if (data.find_first_of("$") >= 0)
						{
							dolarPosition = data.find_first_of("$");
							dolarPosition++;
							i++;
							data = data.substr(1, data.size() - 2); //Nice solving trying to understand
							cout << "Input:" << data.size();
							break;
						}

					}

				}


			}

			/*if (dolarPosition = data.find_first_of("$"))
			break;*/


		}



		return data;
	}
	else
	{
		cout << "levels file is'nt correct ";
		return "";
	}


}

string* FilesHandler::check_levels(string fileName)
{
	short i = 0, pos = 0;

	inputFile.open(fileName);
	while (inputFile.good())
	{

		while (getline(inputFile, levelName[i]))
		{
			pos = levelName[i].find("1");

			if (pos < 0)
			{
				i++;
				break;
			}

			else
			{
				continue;
			}
		}
	}

	inputFile.close();
	return levelptr;
}
void FilesHandler::write_custom_Level(string grid, string levelName,string fileName)
{
	// grid is = "$grid$";
	std::ostringstream formatedText;
	formatedText << levelName;
	string copyOfText = formatedText.str();

	outputFile.open(fileName, ios::app);

	outputFile << "\n" << copyOfText << "\n" << grid;
	cout << "done writing";
	outputFile.close();




}

void FilesHandler::writeScore(int &score,int &highscore,string levelName)
{
	int position = 0; string line,data="",targetLine; bool isFound = false;
	fstream scoreFile;
	scoreFile.open("Data/ScoreSaving.txt");
	if (scoreFile.is_open())
	{
		while (getline(scoreFile,line))
		{
			
			if (line.find(levelName)!=-1)
			{
				position = line.find("L");
				targetLine=line.replace(position, line.length(),levelName+to_string(score));
				cout << targetLine;
				cout << line;
				isFound = true;
				//break;
			}
			data += line;
			/*if (isFound)
				break;*/

		}
	}
	scoreFile.close();
	scoreFile.open("Data/ScoreSaving.txt",ios::out);
	if (isFound)
	{
		scoreFile.seekp(position);
		scoreFile << targetLine<<'\n' << data.substr(targetLine.length(),string::npos)<<'\n';
	}
	else
		scoreFile << levelName << highscore <<'\n';
	
}

void FilesHandler::checkScores()
{

}

//Experiment

//int position = 0; string line, data = ""; bool isFound = false;
//fstream scoreFile;
//scoreFile.open("Data/ScoreSaving.txt");
//if (scoreFile.is_open())
//{
//	while (getline(scoreFile, line))
//	{
//
//		if (line.find(levelName) != -1)
//		{
//
//			line.erase(line.find_first_of(":") + 2, line.find_first_of('\n'));
//
//			position = (int)scoreFile.tellg();
//			isFound = true;
//			//break;
//		}
//		data += line;
//		/*if (isFound)
//			break;*/
//
//	}
//}
//scoreFile.close();
//scoreFile.open("Data/ScoreSaving.txt", ios::out);
//if (isFound)
//{
//	scoreFile.seekp(position);
//	scoreFile << data << highscore;
//}
//else
//scoreFile << levelName << highscore;