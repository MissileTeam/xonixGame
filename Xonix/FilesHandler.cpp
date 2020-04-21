#include "FilesHandler.h"
using namespace std;
string FilesHandler::load_level(string levelName)
{
	short i = 0;
	string data = ""; short dolarPosition = 0;
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

string* FilesHandler::check_levels()
{
	short i = 0,pos=0;
	
	inputFile.open("levels.txt");
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
