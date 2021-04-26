#pragma once

struct move {
    char fig;
    char split;
    int x;
    int y;
    int x2;
    int y2;
};

struct game {
    char board[8][8];
    int colorMove;
};

void printBoard(char table[8][8]);
move getMove(char* s);
bool checkMove(move m, game game);
void getMoves(char* s, move& m1, move& m2);
