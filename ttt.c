#include<stdio.h>
#include <stdbool.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

struct tree{
    char b[3][3];
    struct tree *right;
    struct tree *left;
};

struct Move
{
    int row, col;
};

char player = 'O', opponent = 'X';

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
        printf("Invalid Move, Try another position.\n");
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
bool isMovesLeft(char board[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]=='_')
                return true;
    return false;
}
int evaluate(char b[3][3])
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] &&
            b[row][1]==b[row][2])
        {
            if (b[row][0]==player)
                return +10;
            else if (b[row][0]==opponent)
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]==player)
                return +10;

            else if (b[0][col]==opponent)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==player)
            return +10;
        else if (b[0][0]==opponent)
            return -10;
    }

    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==player)
            return +10;
        else if (b[0][2]==opponent)
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}
int minimax(char board[3][3], int depth, bool isMax)
{
    int score = evaluate(board);

    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(board)==false)
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]=='_')
                {
                    // Make the move
                    board[i][j] = player;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best,
                        minimax(board, depth+1, !isMax) );

                    // Undo the move
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]=='_')
                {
                    // Make the move
                    board[i][j] = opponent;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,minimax(board, depth+1, !isMax));

                    // Undo the move
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

// This will return the best possible move for the player
struct Move findBestMove(char board[3][3])
{
    int bestVal = -1000;
    struct Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if cell is empty
            if (board[i][j]=='_')
            {
                // Make the move
                board[i][j] = player;

                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);

                // Undo the move
                board[i][j] = '_';

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    printf("The value of the best Move is : %d\n\n",
            bestVal);
    return bestMove;
}
void main(){
    int x;
    char board[3][3];
    char board2[3][3];
    int moves[9][2]={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
    int count=1;
    int n;
    clearBoard(board);
    clearBoard(board2);
    while(count<=9){
        if(board==board2)
            printf("Yes");
        printf("Enter the no.:");
        scanf("%d",&n);
        if(validMove(board,moves[n-1][0],moves[n-1][1]))
        {
            board[moves[n-1][0]][moves[n-1][1]]='X';
            displayBoard(board);
        }
        struct Move bestMove = findBestMove(board);
        printf("The best Move is : %d %d\n\n",bestMove.row,bestMove.col);
        if(board==board2)
            printf("Yes");
        count=count+checkResult(board);
    }
}
