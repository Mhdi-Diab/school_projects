#ifndef AThreat_HPP
# define AThreat_HPP

# include <iostream>
# include <map>
using namespace std;

# define MAX_VALUE 1000000

typedef enum 	e_threat {
	CAPTURE = 0,
	THREE,
	BROKEN_THREE,
	FOUR,
	STRAIGHT_FOUR,
	FIVE
}				t_threat;

class AThreat {
public:
	map<t_threat, int> threatsCount;

	AThreat(void);
	virtual ~AThreat(void);
	virtual void computeThreats(int x, int y) = 0;

	static map<t_threat, int> threatsScore;
	static map<t_threat, int> initThreat() {
		 map<t_threat, int> threatMap;
		 threatMap[CAPTURE] = 1200;
		 threatMap[THREE] = 1600;
		 threatMap[BROKEN_THREE] = 1300;
		 threatMap[FOUR] = 1300;
		 threatMap[STRAIGHT_FOUR] = 4000;
		 threatMap[FIVE] = MAX_VALUE;
		 return threatMap;
	 }
};
#endif
