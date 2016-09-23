#include "AThreat.hpp"

AThreat::AThreat() {
	for (int i = 0; i <= FIVE; i++) {
		this->threatsCount[(t_threat)i] = 0;
	}
}

AThreat::~AThreat(void) {
}
