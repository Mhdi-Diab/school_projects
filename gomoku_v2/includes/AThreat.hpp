#ifndef AThreat_HPP
# define AThreat_HPP

# include <iostream>
# include <string>
using namespace std;
# include <unordered_map>
using namespace std;

# define MAX_VALUE 1000000

class AThreat {
public:
	unordered_map<string, int> threatsCount;

	AThreat(void);
	virtual ~AThreat(void);
	virtual void computeThreats(int x, int y) = 0;

	static string *threatsName;
	static unordered_map<string, int> threatsScore;

	static string *initThreatsNames() {
		string *names = new string[6];
		string threats[6] = {"CAPTURE", "THREE", "BROKEN_THREE", "FOUR", "STRAIGHT_FOUR", "FIVE"};

		for (int i = 0; i < 6; i++) {
			names[i] = threats[i];
		}
		return names;
	}

	static unordered_map<string, int> initThreat() {
		 unordered_map<string, int> threatMap;
		 threatMap["CAPTURE"] = 1200;
		 threatMap["THREE"] = 1600;
		 threatMap["BROKEN_THREE"] = 1300;
		 threatMap["FOUR"] = 1300;
		 threatMap["STRAIGHT_FOUR"] = 4000;
		 threatMap["FIVE"] = MAX_VALUE;
		 return threatMap;
	 }
};
#endif
