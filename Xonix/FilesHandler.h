#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<sstream>
using namespace std;
class FilesHandler
{
public:
	string load_level(string levelName);
	string* check_levels();
	void writeLevels(string grid,string levelName);

private:
	ifstream inputFile;
	ofstream outputFile;
	string levelName[9] = {};
	string* levelptr = &levelName[0];
	string grid;
};

