#ifndef AThreat_HPP
# define AThreat_HPP

# include <iostream>
# include <string>
# include <unordered_map>
using namespace std;

# define MAX_VALUE 1000000

class Board;
class AThreat {
public:
	unordered_map<string, int> blackThreats;
	unordered_map<string, int> whiteThreats;

	AThreat(void);
	AThreat(AThreat &rhs);
	~AThreat(void);
	void clearThreats(void);
	bool isPlacedAtEnd(Board *b, int x, int y, string ori);
	bool isXStraight(Board *board, int x, int y, int nb);
	void arrangeThreats(Board *b, unordered_map<string, int> *t);
	void findThreats(Board *b, int x, int y, unordered_map<string, int> *threats);
	void computeScore(Board *b);
	void computeThreats(Board *b);
	void printThreats(Board *b);
	bool isBrokenThree(Board *b, int x, int y);
	void countThreats(Board *b, int x, int y, unordered_map<string, int> *t);

	static string 						*threatsName;
	static unordered_map<string, int>	threatsScore;

	static string *initThreatsNames() {
		string *names = new string[7];
		string threats[7] = {"CAPTURE", "TWO", "THREE", "BROKEN_THREE", "FOUR", "STRAIGHT_FOUR", "FIVE"};

		for (int i = 0; i < 7; i++) {
			names[i] = threats[i];
		}
		return names;
	}

	static unordered_map<string, int> initThreat() {
		unordered_map<string, int> threatMap;
		threatMap["CAPTURE"] = 1300;
		threatMap["TWO"] = 300;
		threatMap["THREE"] = 1300;
		threatMap["BROKEN_THREE"] = 1200;
		threatMap["FOUR"] = 2700;
		threatMap["STRAIGHT_FOUR"] = 4000;
		threatMap["FIVE"] = MAX_VALUE;
		return threatMap;
	}
};
#endif
