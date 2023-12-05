#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Day3
{
public:
	int main();

private:
	struct Position {
		int x;
		int y;
	};

	struct Symbol {
		Position pos;
		vector<Position> adjacentNPos;
		string value;
	};

	struct Part {
		int number;
		string value;
		Position pos;
		bool isValid = false;
		bool isValid2 = false;
	};

	struct Gear {
		char value;
		vector<Position> aPos;
		vector<int> parts;
		int gearRatio;
	};

	struct Engine {
		vector<Part> parts;
		vector<Symbol> symbols;
		vector<Gear> gears;
	};

	vector<Position> CheckAdjacentNumber(int y, int x, vector<string> scheme);
};

