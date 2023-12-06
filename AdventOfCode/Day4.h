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
		vector<int> winningNrs;
		vector<int> playedNrs;
	};
};

