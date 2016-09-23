#include "AThreat.hpp"

string *AThreat::threatsName = initThreatsNames();
unordered_map<string, int>AThreat::threatsScore = initThreat();

AThreat::AThreat() {
	for (int i = 0; i <= threatsName->size(); i++) {
		this->threatsCount[threatsName[i]] = 0;
	}
}

AThreat::~AThreat(void) {
}
