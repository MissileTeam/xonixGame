#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<sstream>
using namespace std;
class FilesHandler
{
public:
	string load_level();
	string choose_level(string levelName);
	void writeLevels(string grid,string levelName);
	void addLevels();

private:
	ifstream inputFile;
	ofstream outputFile;
	string grid;
};

