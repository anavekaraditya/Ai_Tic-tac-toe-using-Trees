#include<stdio.h>

struct tree{
    char b[3][3];
    struct tree *right;
    struct tree *left;
};

void displayBoard(char board[3][3]){
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n",board[0][0],board[0][1],board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n",board[1][0],board[1][1],board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n",board[2][0],board[2][1],board[2][2]);
    printf("     |     |     \n");
}
void clearBoard(char board[3][3]){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=' ';
}
int validMove(char board[3][3],int x,int y){
    if(board[x][y]==' ')
        return 1;
    else
        return 0;
}
int checkResult(char state[3][3]){
    char win_state[9][3] = {
        {state[0][0], state[0][1], state[0][2]},
        {state[1][0], state[1][1], state[1][2]},
        {state[2][0], state[2][1], state[2][2]},
        {state[0][0], state[1][0], state[2][0]},
        {state[0][1], state[1][1], state[2][1]},
        {state[0][2], state[1][2], state[2][2]},
        {state[0][0], state[1][1], state[2][2]},
        {state[2][0], state[1][1], state[0][2]},
    };
    for(int i=0;i<9;i++){
        if(win_state[i][0]==win_state[i][1] && win_state[i][1]==win_state[i][2] ){
                if(win_state[i][2]=='X'){
                    printf("Game Over Computer wins\n");
                    return 9;
                }
                else if(win_state[i][2]=='O'){
                    printf("Game Over Human wins\n");
                    return 9;
                }
                else
                    return 0;
        }
    }
}
void main(){
    int x;
    char board[3][3];
    int moves[9][2]={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
    int count=1;
    int n;
    clearBoard(board);
    while(count<=9){
        printf("enter the no.:");
        scanf("%d",&n);
        if(validMove(board,moves[n-1][0],moves[n-1][1]))
        {
            if(count%2==0)
                board[moves[n-1][0]][moves[n-1][1]]='X';
            else
                board[moves[n-1][0]][moves[n-1][1]]='O';
            count++;
            displayBoard(board);
        }
        count=count+checkResult(board);
    }
}
