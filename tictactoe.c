#include <stdio.h>

char board[9] = {'1','2','3','4','5','6','7','8','9'};

void printBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

int checkWin() {

    int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, 
        {0,3,6}, {1,4,7}, {2,5,8}, 
        {0,4,8}, {2,4,6}           
    };

    for (int i = 0; i < 8; i++) {
        int a = wins[i][0];
        int b = wins[i][1];
        int c = wins[i][2];
        if (board[a] == board[b] && board[b] == board[c])
            return 1;
    }
    return 0;
}

int main() {
    int move, turn = 0; 
    char mark;

    printf("🎮 Simple Tic Tac Toe (2 Players)\n");
    printBoard();

    for (int i = 0; i < 9; i++) {
        mark = (turn == 0) ? 'X' : 'O';
        printf("Player %c, enter a number (1-9): ", mark);
        scanf("%d", &move);

        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            printf("Invalid move! Try again.\n");
            i--; 
            continue;
        }

        board[move - 1] = mark;
        printBoard();

        if (checkWin()) {
            printf("🏆 Player %c wins!\n", mark);
            return 0;
        }

        turn = 1 - turn; 
    }

    printf("It's a draw!\n");
    return 0;
}
