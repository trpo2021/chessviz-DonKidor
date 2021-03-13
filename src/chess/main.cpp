#include <chesslib/board_print.h>
#include <stdio.h>

int main(int argvn, char* arg[])
{
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

    do {
        printBoard(table);
        char x, y, x2, y2, t;
        scanf("%c%c%c%c%c%c", &x, &y, &t, &x2, &y2, &t);
        printf("\n");
        int tx1, tx2, ty1, ty2;
        tx1 = x - 'a';
        tx2 = x2 - 'a';
        ty1 = y - '1';
        ty2 = y2 - '1';
        ty1 = 7 - ty1;
        ty2 = 7 - ty2;
        if (tx1 == 0 && ty1 == 0 && tx2 == 0 && ty2 == 0)
            break;
        table[ty2][tx2] = table[ty1][tx1];
        table[ty1][tx1] = ' ';
    } while (true);
    return 0;
}
