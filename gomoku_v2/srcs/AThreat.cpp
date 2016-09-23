#include "AThreat.hpp"

string *AThreat::threatsName = initThreatsNames();
unordered_map<string, int>AThreat::threatsScore = initThreat();

AThreat::AThreat() {
	clearThreats();
}

AThreat::~AThreat(void) {
}

void AThreat::clearThreats(void) {
	for (int i = 0; i <= 7; i++) {
		this->blackThreats[threatsName[i]] = 0;
		this->whiteThreats[threatsName[i]] = 0;
	}
}
