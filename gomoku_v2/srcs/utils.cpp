#include "utils.hpp"

bool superiorCmp(int a, int b) {
	return a >= b;
}

bool equalCmp(int a, int b) {
	return a == b;
}

string myHash(int x, int y) {
	return to_string(x) + to_string(y);
}
