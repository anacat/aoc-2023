#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Day2
{
public:
	int main();

private:
	enum Colors
	{
		Red, Green, Blue
	};
	struct Cube
	{
		Colors color;
		int number;
		bool isValid;
	};
	struct Set
	{
		vector<Cube> cubes;
	};
	struct Game
	{
		int gameNr;
		vector<Set> sets;

		vector<Cube> blueCubes;
		vector<Cube> greenCubes;
		vector<Cube> redCubes;

		int nBlue = 0;
		int nGreen = 0;
		int nRed = 0;
	};
};

