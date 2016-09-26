#ifndef AThreat_HPP
# define AThreat_HPP

# include <iostream>
# include <string>
# include <unordered_map>
using namespace std;

# define MAX_VALUE 1000000
# define NUMBER_THREATS 6

class Board;
class AThreat {
public:
	unordered_map<string, int> blackThreats;
	unordered_map<string, int> whiteThreats;

	AThreat(void);
	AThreat(AThreat &rhs);
	~AThreat(void);
	void clearThreats(void);
	bool isPlacedAtEnd(Board &b, int x, int y, string ori);
	bool isXStraight(Board &board, int x, int y, int nb);
	void arrangeThreats(unordered_map<string, int> *t);
	void findThreats(Board &b, int x, int y, unordered_map<string, int> *threats);
	void computeScore(Board &b);
	void computeThreats(Board &b);
	void printThreats(void);
	bool isBrokenThree(Board &b, int x, int y);
	void countThreats(Board &b, int x, int y, unordered_map<string, int> *t);

	static string 						threatsName[NUMBER_THREATS];
	static unordered_map<string, int>	threatsScore;

	static unordered_map<string, int> initThreat() {
		unordered_map<string, int> threatMap;
		threatMap["CAPTURE"] = 2300;
		threatMap["THREE"] = 1300;
		threatMap["BROKEN_THREE"] = 1300;
		threatMap["FOUR"] = 2700;
		threatMap["STRAIGHT_FOUR"] = 10000;
		threatMap["FIVE"] = MAX_VALUE;
		return threatMap;
	}
};
#endif
