#include "Day1.h"

int Day1::main()
{
	vector<string> numbers = {
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	ifstream myFile("input.txt");
	string temp;
	string line;
	int sum = 0;
	int j;

	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			vector<int> list;

			for (int d = 0; d < line.size(); )
			{
				if (isdigit(line[d]) != 0)
				{
					list.push_back(line[d] - '0');
					//cout << line[d] << ' ';

					d++;
				}
				else
				{
					j = 0;

					for (int i = 0; i < numbers.size() && d < line.size(); i++)
					{
						size_t found = line.find(numbers[i], d);

						if (found == d && found != string::npos)
						{
							d = found + 1;

							list.push_back(i);

							//cout << i << ' ';

							j = 1;

							break;
						}
					}

					if (j == 0)
					{
						d++;
					}
				}
			}

			string tem = "";
			tem += to_string(list.at(0));
			tem += to_string(list.at(list.size() - 1));

			int val = stoi(tem);

			cout << val << '\n';
			//cout << line << endl;

			sum += val;
		}
		myFile.close();

		cout << sum << endl;
	}
	else {
		cout << "Unable to open file";
	}

	return 0;
}
