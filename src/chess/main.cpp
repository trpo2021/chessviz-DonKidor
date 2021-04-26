#include <chesslib/board_print.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

int main(int argvn, char* arg[])
{
    std::ifstream f;
    bool inputFile = false;
    for (int i = 1; i < argvn; ++i) {
        if (arg[i] == std::string("-I")) {
            if (argvn > i + 1) {
                f.open(arg[i + 1]);
                inputFile = true;
            }
        }
    }
    game game;
    char table[8][8];
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            table[i][j] = ' ';
    for (int i = 0; i < 8; ++i) {
        table[1][i] = 'p';
        table[6][i] = 'P';
    }
    table[0][0] = 'r';
    table[0][7] = 'r';
    table[7][0] = 'R';
    table[7][7] = 'R';
    table[0][1] = 'n';
    table[0][6] = 'n';
    table[7][1] = 'N';
    table[7][6] = 'N';
    table[0][2] = 'b';
    table[0][5] = 'b';
    table[7][2] = 'B';
    table[7][5] = 'B';
    table[0][3] = 'q';
    table[7][3] = 'Q';
    table[0][4] = 'k';
    table[7][4] = 'K';

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            game.board[i][j] = table[i][j];
    game.colorMove = 0;
    do {
        printBoard(game.board);
        char s[20];
        if (inputFile) {
            f.getline(s, 20);
        } else
            std::cin.getline(s, 20);

        move m[2];
        getMoves(s, m[0], m[1]);
        for (int i = 0; i < 2; ++i) {
            if (checkMove(m[i], game)) {
                game.board[m[i].y2][m[i].x2] = game.board[m[i].y][m[i].x];
                game.board[m[i].y][m[i].x] = ' ';
            } else
                return 1;
            game.colorMove = (game.colorMove + 1) % 2;
        }
        std::cout << "\nPress any key...\n";
        std::cin.get();
    } while (true);
    return 0;
}
