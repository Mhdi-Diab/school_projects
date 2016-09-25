#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include "Board.hpp"

using namespace std;

bool superiorCmp(int a, int b);
bool equalCmp(int a, int b);
string myHash(int x, int y);
bool sortBoardsByScore(Board *a, Board *b);
bool sortBoardsByScoreRev(Board *a, Board *b);

#endif
