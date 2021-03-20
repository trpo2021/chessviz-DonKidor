#pragma once

struct move {
	char fig;
	char split;
	int x;
	int y;
	int x2;
	int y2;
};

void printBoard(char table[8][8]);
move getMove(char* s);
bool checkMove(move m, int bw);
