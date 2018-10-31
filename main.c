/* file: eightqueensproblem.c */
/* author: Caitlin Isabelle de Boer (caitlin.de.boer@gmail.com) */
/* date: 09 October 2016 */
/* version: 1.0 */
/* description: This program is to evaluate if the positions of the queens is safe*/


#include <stdio.h>
#include <stdlib.h>

#define ROWS    8
#define COLUMNS 8


int isColumnSafe (int board[][COLUMNS], int col)
{
    int i;
    int q = 0;
    
    for (i=0; i< ROWS ; i++)
        q = q + board[i][col];  // count the numnber of queens
    
    if (q == 1)
        // only 1 queen in column
        return 1;
    else
        return 0;
}

int isRowSafe (int board[][COLUMNS], int row)
{
    int i;
    int q = 0;
    
    for (i=0; i< COLUMNS ; i++)
        q = q + board[row][i];  // count the numnber of queens
    
    if (q == 1)
        // only 1 queen in column
        return 1;
    else
        return 0;
}

int isDiagonalSafeDown(int board[][COLUMNS], int row, int col){
    int i;
    int j;
    int q = 0;
    
    // find starting point
    if (row > col)
    {
        row = row - col;
        col = 0;
    }
    else
    {
        col = col - row;
        row = 0;
    }
    
    
    for (i=row ,j = col; i<ROWS && j<COLUMNS; i++,j++)
    {
        q = q + board[i][j];  // count the numnber of queens
        
    }
    
    if (q == 1)
        // only 1 queen in column
        return 1;
    else
        return 0;
    
}

int isDiagonalSafeUp(int board[][COLUMNS], int row, int col){
    int i;
    int j;
    int q = 0;
    
    // find starting point
    if ( (row+col) >= ROWS)
    {
        col = col - (ROWS-1-row);
        row = 7;
    }
    else
    {
        row = row+col;
        col = 0;
    }
    
    
    for (i=row ,j = col; i>=0 && j<COLUMNS; i--,j++)
    {
        q = q + board[i][j];  // count the numnber of queens
        
    }
    
    if (q == 1)
        // only 1 queen in column
        return 1;
    else
        return 0;
    
}

int isSafe (int board[][COLUMNS], int x, int y)
{
    if (isColumnSafe(board,y)!=0 &&
        isRowSafe(board,x)!=0 &&
        isDiagonalSafeDown(board,x,y)!=0 &&
        isDiagonalSafeUp(board,x,y)!=0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int main()
{
    int r;      // index for rows
    int c;      // index for columns
    int pos[ROWS];
    int board[ROWS][COLUMNS];
    int safecount =0;
    
    // read the queen locations and straight away initialise the board
    for (c=0; c<COLUMNS; c++)
    {
        // initiaise the row on the board to 0
        for (r=0; r<ROWS; r++)
            board[r][c] = 0;
        
        // read the queen position from the keyboard
        scanf(" %d", &pos[c]);
        // and place on the board
        board[pos[c]][c] = 1;
    }
    
    printf("\n");
    for(r=0; r<8; r++)
    {
        for(c=0; c<8; c++)
        {
            printf("%d ",board[r][c]);
        }
        printf("\n");
    }
    
    for (c=0;c<8;c++)
    {
        
        if ( isSafe(board, pos[c], c))
        {
            safecount++;
        }
    }
    
    if(safecount==8)
    {
        printf("valid\n");
    }
    else
    {
        printf("invalid\n");
    }
    
    
    return 0;
}
