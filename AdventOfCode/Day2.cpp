#include "Day2.h"

int Day2::main()
{
	ifstream myFile("input2.txt");
	string line;

	Cube redSet;
	Cube greenSet;
	Cube blueSet;

	redSet.color = Red;
	redSet.number = 12;

	greenSet.color = Green;
	greenSet.number = 13;

	blueSet.color = Blue;
	blueSet.number = 14;

	int sum = 0;
	int sum2 = 0;
	vector<Game> games;

	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			Game game;
			stringstream ss(line);

			string gameNr;
			string sets;
			getline(ss, gameNr, ':');

			sets = line;

			sets.erase(sets.begin(), sets.begin() + gameNr.size() + 2);

			char gameStr[] = "Game ";

			//parse game number
			for (int i = 0; i < strlen(gameStr); i++)
			{
				gameNr.erase(remove(gameNr.begin(), gameNr.end(), gameStr[i]), gameNr.end());
			}

			game.gameNr = stoi(gameNr);

			//cout << endl << game.gameNr << endl;

			vector<string> setList;
			int setNr = 0;

			setList.push_back("");

			vector<Set> cubeSets;

			//parse sets
			for (int i = 0; i < sets.size(); i++)
			{
				if (sets[i] == ';')
				{
					setNr++;
					setList.push_back("");
					continue;
				}

				if (sets[i] == ' ')
				{
					continue;
				}

				setList[setNr] += sets[i];
			}

			//parse cubes

			for (int i = 0; i < setList.size(); i++) //per set
			{
				//cout << endl << setList[i] << endl;

				vector<string> set;
				set.push_back("");
				setNr = 0;

				vector<Cube> cubes;

				for (int j = 0; j < setList[i].size(); j++) //per cube
				{
					if (setList[i][j] == ',')
					{
						setNr++;
						set.push_back("");
					}
					else {
						set[setNr] += setList[i][j];
					}
				}

				for (int k = 0; k < set.size(); k++) //per cube parsing
				{
					//cout << set[k] << endl;

					string n = set[k];
					size_t pos = set[k].find("blue");

					Cube cube;

					if (pos != string::npos)
					{
						n.erase(n.begin() + pos, n.end());
						//cout << n;

						int val = stoi(n);
						cube.number = val;
						cube.color = Blue;
					}
					
					pos = set[k].find("green");

					if (pos != string::npos)
					{
						n.erase(n.begin() + pos, n.end());
						//cout << n;

						int val = stoi(n);
						cube.number = val;
						cube.color = Green;
					}

					pos = set[k].find("red");

					if (pos != string::npos)
					{
						n.erase(n.begin() + pos, n.end());
						//cout << n;

						int val = stoi(n);
						cube.number = val;
						cube.color = Red;
					}

					cubes.push_back(cube);
				}
				Set s;
				s.cubes = cubes;

				cubeSets.push_back(s);
			}

			//cout << line << endl;
			game.sets = cubeSets;
			games.push_back(game);
		}

		myFile.close();
	}
	else {
		cout << "Unable to open file" << endl;
	}

	for (int i = 0; i < games.size(); i++)
	{
		//cout << games[i].gameNr << ": ";

		bool isGameValid = true;

		cout << "Game nr: " << games[i].gameNr << endl;

		for (Set set : games[i].sets)
		{
			for (Cube cube : set.cubes)
			{
				switch (cube.color)
				{
				case Red:
					cube.isValid = cube.number <= redSet.number;
					games[i].redCubes.push_back(cube);
					break;
				case Green:
					cube.isValid = cube.number <= greenSet.number;
					games[i].greenCubes.push_back(cube);
					break;
				case Blue:
					cube.isValid = cube.number <= blueSet.number;
					games[i].blueCubes.push_back(cube);
					break;
				}

				if (!cube.isValid)
				{
					//cout << "is invalid: ";
					isGameValid = false;

					//break;
				}

				//cout << cube.number << ", ";
			}

			if (!isGameValid)
			{
				//break;
			}

			//cout << "; ";
		}

		if (isGameValid)
		{
			sum += games[i].gameNr;
		}

		for (Cube green : games[i].greenCubes)
		{
			if (green.number > games[i].nGreen)
			{
				games[i].nGreen = green.number;
			}

			cout << green.number << ", ";
		}

		cout << ": " << games[i].nGreen << endl;

		for (Cube blue : games[i].blueCubes)
		{
			if (blue.number > games[i].nBlue)
			{
				games[i].nBlue = blue.number;
			}

			cout << blue.number << ", ";
		}

		cout << ": " << games[i].nBlue << endl;

		for (Cube red : games[i].redCubes)
		{
			if (red.number > games[i].nRed)
			{
				games[i].nRed = red.number;
			}

			cout << red.number << ", ";
		}

		cout << ": " << games[i].nRed << endl;

		int power = games[i].nRed * games[i].nGreen * games[i].nBlue;
		sum2 += power;

		//cout << endl;
	}

	//cout << sum << endl;
	cout << sum2 << endl;

	return 0;
}
