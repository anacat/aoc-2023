#include "Day3.h"

int Day3::main()
{
	ifstream myFile("input3.txt");
	string line;

	vector<string> scheme;

	if (myFile.is_open()) {
		while (getline(myFile, line)) {
			scheme.push_back(line);
		}
	}
	else {
		cout << "Unable to open file." << endl;
	}

	string temp;

	Engine engine;

	for (int y = 0; y < scheme.size(); y++)
	{
		for (int x = 0; x < scheme[y].size(); x++)
		{
			char c = scheme[y][x];

			if (!isalpha(c) && !isdigit(c) && c != '.') //is symbol
			{
				//cout << c;

				Symbol symbol;
				Position pos;
				pos.x = x;
				pos.y = y;

				symbol.pos = pos;
				symbol.adjacentNPos = CheckAdjacentNumber(y, x, scheme);
				symbol.value = c;

				engine.symbols.push_back(symbol);

				if (c == '*')
				{
					Gear gear;
					gear.value = c;
					gear.aPos = symbol.adjacentNPos;

					engine.gears.push_back(gear);
				}
			}
			else if (isdigit(c)) //is number
			{
				temp += c;

				if (x <= scheme[y].size() - 1 && !isdigit(scheme[y][x + 1]) && temp.size() > 0)
				{
					Position pos;
					pos.x = x;
					pos.y = y;

					Part part;
					part.number = atoi(temp.c_str());
					part.value = temp;
					part.pos = pos;

					engine.parts.push_back(part);

					//cout << temp << endl;

					temp = "";
				}

				//cout << c;
			}
		}

		//cout << endl;
	}

	int sum = 0;
	int sum2 = 0;

	for (int j = 0; j < engine.symbols.size(); j++)
	{
		Symbol symbol = engine.symbols[j];

		//cout << endl << symbol.value << endl << endl;

		for (int k = 0; k < symbol.adjacentNPos.size(); k++)
		{
			//forgive me

			Position aPos = symbol.adjacentNPos[k];
			//cout << aPos.y << "," << aPos.x << endl;

			for (int i = 0; i < engine.parts.size(); i++)
			{
				//cout << part.value << endl;

				if (engine.parts[i].pos.y == aPos.y && !engine.parts[i].isValid)
				{
					int begin = engine.parts[i].pos.x - engine.parts[i].value.size() + 1;

					if (begin <= aPos.x && engine.parts[i].pos.x >= aPos.x)
					{
						engine.parts[i].isValid = true;

						//cout << engine.parts[i].number << " ";

						sum += engine.parts[i].number;

						break;
					}
				}
				else {
					continue;
				}
			}
		}

		//cout << endl;
	}

	for (int i = 0; i < engine.gears.size(); i++)
	{
		for (Position aPos : engine.gears[i].aPos)
		{
			for (int j = 0; j < engine.parts.size(); j++ )
			{
				if (engine.parts[j].pos.y == aPos.y && !engine.parts[j].isValid2)
				{
					int begin = engine.parts[j].pos.x - engine.parts[j].value.size() + 1;

					if (begin <= aPos.x && engine.parts[j].pos.x >= aPos.x)
					{
						engine.parts[j].isValid2 = true;

						cout << engine.parts[j].number << " ";

						engine.gears[i].parts.push_back(engine.parts[j].number);

						//sum += part.number;

						break;
					}
				}
				else {
					continue;
				}
			}
		}
	}

	for (Gear gear : engine.gears)
	{
		if (gear.parts.size() == 2)
		{
			gear.gearRatio = gear.parts[0] * gear.parts[1];
			sum2 += gear.gearRatio;
		}
	}

	cout << endl << sum << endl;
	cout << endl << sum2 << endl;

	return 0;
}

vector<Day3::Position> Day3::CheckAdjacentNumber(int y, int x, vector<string> scheme)
{
	/*scheme[y + 1][x];
	scheme[y - 1][x];
	scheme[y][x + 1];
	scheme[y][x - 1];
	scheme[y + 1][x + 1];
	scheme[y + 1][x - 1];
	scheme[y - 1][x + 1];
	scheme[y - 1][x - 1];*/

	vector<Position> adjacentPos;

	for (int i = y - 1; i <= y + 1; i++)
	{
		for (int j = x - 1; j <= x + 1; j++)
		{
			if ((y > 0 && y < scheme.size() - 1 && x > 0 && x < scheme[y].size() - 1) ||
				(y == 0 && i > 0) || (y == scheme.size() && i < scheme.size()) ||
				(x == 0 && j > 0) || (x == scheme.size() && j < scheme[y].size()))
			{
				if (isdigit(scheme[i][j]))
				{
					Position pos;
					pos.x = j;
					pos.y = i;

					adjacentPos.push_back(pos);
				}
			}
		}
	}

	return adjacentPos;
}