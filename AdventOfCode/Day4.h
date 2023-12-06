#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Day4
{
public:
	int main();

private:
	struct ScratchCard {
		int cardNr;
		int nCopies = 1;
		int score = 0;
		vector<int> winningNrs;
		vector<int> playedNrs;

		bool isCopy = false;
		vector<ScratchCard> winnings;
	};
};

