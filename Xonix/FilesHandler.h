#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<sstream>
using namespace std;
class FilesHandler
{
public:
	string load_level(string levelName,string fileName);
	string* check_levels(string fileName);
	void write_custom_Level(string grid, string levelName,string fileName);
	void writeScore(int &score, int &highscore, string levelName);
	void checkScores();
private:
	ifstream inputFile;
	ofstream outputFile;
	string levelName[50] = {};
	string* levelptr = levelName;
	string grid;
};


