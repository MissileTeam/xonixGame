#include "FilesHandler.h"
using namespace std;
string FilesHandler::load_level()
{
	short i = 0;
	string data = ""; short dolarPosition=0;
	inputFile.open("levels.txt");
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
				if (data.find_first_of("$") == -1)
				{
					continue;
				}
				else
				{
					dolarPosition = data.find_first_of("$");
					dolarPosition++;
					i++;
					data = data.substr(1, data.size() - 2); //Nice solving trying to understand
					cout << "Input:" << data;
					break;
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

string FilesHandler::choose_level(string levelName)
{
	
	while (inputFile.good())
	{
		inputFile >> levelName;
		if ((levelName.find('0') & levelName.find('1') & levelName.find('$')) == false)
			return levelName;

	}
}
void FilesHandler::writeLevels(string grid,string levelName)
{
	// grid is = "$grid$";
	std::ostringstream formatedText;
	formatedText << levelName;
	string copyOfText = formatedText.str();

	outputFile.open("levels.txt", ios::app);
	
	outputFile << "\n" << copyOfText << "\n" << grid;
	cout << "done writing";
	outputFile.close();
	
	

	
}

