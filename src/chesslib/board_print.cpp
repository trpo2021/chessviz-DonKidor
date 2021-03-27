#include "board_print.h"
#include <stdio.h>


using namespace std;
#define ABS(X) ((X)>=0)?(X):(-(X))

void printBoard(char table[8][8])
{
    for (int i = 0; i < 8; ++i) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; ++j) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

bool checkMove(move m, game game)
{
	int bw=game.colorMove;
	printf("\n%d %d %d %d\n",m.x,m.y,m.x2,m.y2);
    if (!(m.x >= 0 && m.x <= 7) || !(m.y2 >= 0 && m.y2 <= 7)
        || !(m.y >= 0 && m.y <= 7) || !(m.x2 >= 0 && m.x2 <= 7))
        return false;
    
    if(m.fig+bw*('a'-'A')!=game.board[m.y][m.x]) return false;
    
    switch (m.fig) {
    	case 'P':
        	
       		if(m.split=='-')
       		{
       			if(bw==0) {
       				for(int i=m.y-1;i>=m.y2;--i) if(game.board[i][m.x]!=' ') return false;
       			}
       			else
        			for(int i=m.y+1;i<=m.y2;++i) {
        				if(game.board[i][m.x]!=' ') return false;
        			}
        		printf("%d \n",(ABS(m.y2-m.y)));
        		return m.x==m.x2 && ( ((m.y==6-bw*5)&&(ABS(m.y2-m.y)==2))||(ABS(m.y2-m.y)==1)  );
        	}
        	else if(m.split=='x'){
        		if(!((game.board[m.y2][m.x2]>=('a'-bw*('a'-'A')))&&(game.board[m.y2][m.x2]<=('z'-bw*('a'-'A'))))) return false;
        		
        		return (ABS(m.x-m.x2)==1)&&(m.y==m.y2+1-bw*2);
        	}	
        	
    	default:
        	return false;
    }
}

move getMove(char* s)
{
    move res;
    char r[20];
    int length = 0;
    for (int i = 0; i < 20; i++) {
        if (s[i] == ' ')
            continue;
        ;
        r[length++] = s[i];
        if (r[length - 1] == 0 || r[length - 1] == '\n') {
            break;
        }
    }
    if (length == 6)
        res.fig = 'P';
    else {
        res.fig = r[0];
        length--;
        for (int i = 0; i < length; ++i)
            r[i] = r[i + 1];
    }
    res.split = r[2];
    res.x = r[0] - 'a';
    res.x2 = r[3] - 'a';
    res.y = 7 - r[1] + '1';
    res.y2 = 7 - r[4] + '1';

    return res;
}
