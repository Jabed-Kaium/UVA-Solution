//Technique used: N-Queen problem using Backtracking

#include<bits/stdc++.h>

using namespace std;

#define N 8 

int k,x,y;

void printSolution(int board[N][N]) 
{ 
	printf("%2d     ",k++); 	
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++) 
			if(board[j][i] == 1){
				printf(" %d",j+1);
			} 
	} 
	printf("\n"); 
} 

bool isSafe(int board[N][N], int row, int col) 
{ 
	int i, j; 

	/* Check this row on left side */
	for (i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 

	/* Check this row on right side */
	for(i=col+1; i<N; i++)
		if(board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i=row-1, j=col-1; i>=0 && j>=0; i--, j--) 
		if (board[i][j]) 
			return false; 

	/* Check lower diagonal on left side */
	for (i=row+1, j=col-1; j>=0 && i<N; i++, j--) 
		if (board[i][j]) 
			return false; 
	
	/* Check upper diagonal on right side */
	for(i=row-1, j=col+1; i>=0 && j<N; i--,j++)
		if(board[i][j])
			return false;
	
	/* Check lower diagonal on right side */
	for(i=row+1, j=col+1; i<N && j<N; i++,j++)
		if(board[i][j])
			return false;

	return true; 
} 

/* A recursive utility function to solve N 
Queen problem */
bool solveNQUtil(int board[N][N], int col) 
{ 
	/* base case: If all queens are placed 
	then return true */
	if (col == N) 
	{ 
		printSolution(board); 
		return true; 
	} 
	if(col == y-1){
		solveNQUtil(board, col + 1);
		return true;
	} 

	/* Consider this column and try placing 
	this queen in all rows one by one */
	bool res = false; 
	for (int i = 0; i < N; i++) 
	{
		/* Check if queen can be placed on 
		board[i][col] */
		if ( isSafe(board, i, col) ) 
		{ 
			/* Place this queen in board[i][col] */
			board[i][col] = 1; 

			// Make result true if any placement 
			// is possible 
			res = solveNQUtil(board, col + 1) || res; 

			//if(i==x && col==y)continue;
			board[i][col] = 0; // BACKTRACK 
		} 
	} 

	
	return res; 
} 


void solveNQ() 
{ 
	int board[N][N];
	int m,t;

	cin>>t;
	
	for(m=1; m<=t; m++){
		memset(board, 0, sizeof(board)); 

		cin>>x>>y;
		board[x-1][y-1] = 1;
		k=1;

		if(m>1)printf("\n");

		printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
		
		solveNQUtil(board, 0);

	}
	 
} 

int main() 
{ 
	solveNQ(); 
	return 0; 
} 
