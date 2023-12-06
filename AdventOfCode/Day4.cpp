#include "Day4.h"

int Day4::main()
{
	ifstream myFile("input4.txt");
	string line;

	vector<ScratchCard> cardList;

	if (myFile.is_open()) {
		while (getline(myFile, line)) {
			stringstream ss(line);

			char card[5];
			char char1;
			char char2;
			int game;
			int winningNrs[10];
			int playedNrs[25];

			//it is what it is, im not sorry

			ss >> card >> game >> char1 >> winningNrs[0] >> winningNrs[1] >> winningNrs[2] >> winningNrs[3] >>
				winningNrs[4] >> winningNrs[5]  >> winningNrs[6] >> winningNrs[7] >> winningNrs[8] >> winningNrs[9] >>
				char2 >> playedNrs[0] >> playedNrs[1] >> playedNrs[2] >> playedNrs[3] >> playedNrs[4] >>
				playedNrs[5] >> playedNrs[6] >> playedNrs[7] >> playedNrs[8] >> playedNrs[9] >> playedNrs[10] >>
				playedNrs[11] >> playedNrs[12] >> playedNrs[13] >> playedNrs[14] >> playedNrs[15] >> playedNrs[16] >>
				playedNrs[17] >> playedNrs[18] >> playedNrs[19] >> playedNrs[20] >> playedNrs[21] >> playedNrs[22] >>
				playedNrs[23] >> playedNrs[24];

			ScratchCard scratchCard;
			scratchCard.cardNr = game;

			for (int i = 0; i < 25; i++) {
				scratchCard.playedNrs.push_back(playedNrs[i]);
			}

			for (int i = 0; i < 10; i++) {
				scratchCard.winningNrs.push_back(winningNrs[i]);
			}

			cardList.push_back(scratchCard);
		}
	}
	else {
		cout << "Unable to open file." << endl;
	}

	cardList.shrink_to_fit();

	int sum = 0;

	for (int i = 0; i < cardList.size(); i++) {
		int score = 0;

		for (int k = 0; k < cardList[i].playedNrs.size(); k++)
		{
			for (int j = 0; j < cardList[i].winningNrs.size(); j++) {
				if (cardList[i].winningNrs[j] == cardList[i].playedNrs[k])
				{
					if (score == 0) {
						score = 1;
					}
					else {
						score *= 2;
					}
				}
			}
		}

		sum += score;

		cout << score << endl;
	}

	cout << sum << endl;

	return 0;
}