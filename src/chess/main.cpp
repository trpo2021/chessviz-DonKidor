#include <chesslib/board_print.h>
#include <iostream>
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
        char s[20];
        std::cin.getline(s, 20);
        char in[2][10];
        
        for (int i = 0, k = -1, t = 0, f = 0; i < 20; ++i) {
            if (s[i] == '.') {
                k++;
                continue;
            }
            if (k < 0)
                continue;
            in[k][t++] = s[i];
            if ((s[i] >= 'a' && s[i] <= 'h') || (s[i] >= '1' && s[i] <= '8'))
                f++;
            if (f >= 4) {
                in[k][t] = 0;
                t = 0;
                k++;
                f = 0;
            }
        }
        std::cout << in[0] << " " << in[1] << '\n';
        move m[2];
        m[0] = getMove(in[0]);
        m[1] = getMove(in[1]);
        for (int i = 0; i < 2; ++i) {
        	std::cout << m[i].fig <<(char)(table[m[i].y][m[i].x])<<m[i].x << " "<< m[i].y << " "<< m[i].x2 << " "<< m[i].y2 << "\n";
        	std::cout << (m[i].fig==table[m[i].y][m[i].x]+(i>0)*('A'-'a'))<<"\n";
            if (m[i].fig==table[m[i].y][m[i].x]+(i>0)*('A'-'a') ) {//&&checkMove(m[i], i)
            	
   	           	table[m[i].y2][m[i].x2]=table[m[i].y][m[i].x];
   	           	table[m[i].y][m[i].x]=' ';
            }
        }
    } while (true);
    return 0;
}
