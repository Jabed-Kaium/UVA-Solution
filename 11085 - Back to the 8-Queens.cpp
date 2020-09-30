#include<bits/stdc++.h>

using namespace std;

#define N 8
int result[92][8];
int k=0; 

void push_solution(int board[N][N]) 
{   int column=0;
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++) {
            if(board[j][i] == 1){
                result[k][column++] = j+1;
            }
        }
	}
    k++; 
} 

bool isSafe(int board[N][N], int row, int col) 
{ 
	int i, j; 

	/* Check this row on left side */
	for (i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 

	/* Check upper diagonal on left side */
	for (i=row, j=col; i>=0 && j>=0; i--, j--) 
		if (board[i][j]) 
			return false; 

	/* Check lower diagonal on left side */
	for (i=row, j=col; j>=0 && i<N; i++, j--) 
		if (board[i][j]) 
			return false; 

	return true; 
} 

bool solveNQUtil(int board[N][N], int col) 
{ 

	if (col == N) 
	{ 
		push_solution(board); 
		return true; 
	} 

	bool res = false; 
	for (int i = 0; i < N; i++) 
	{ 

		if ( isSafe(board, i, col) ) 
		{ 
			board[i][col] = 1; 

			res = solveNQUtil(board, col + 1) || res; 

			board[i][col] = 0; // BACKTRACK 
		} 
	} 

	return res; 
} 

void solveNQ() 
{ 
	int board[N][N]; 
	memset(board, 0, sizeof(board)); 

	solveNQUtil(board, 0);

	return ; 
} 

int main() 
{ 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	solveNQ();

    int arr[N];
    int cases = 1;
    int a,b,c,d,e,f,g,h;

    while(scanf("%d %d %d %d %d %d %d %d", &a,&b,&c,&d,&e,&f,&g,&h) != EOF){
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = d;
        arr[4] = e;
        arr[5] = f;
        arr[6] = g;
        arr[7] = h;
        int ans = INT_MAX;
        for(int i=0; i<92; i++){
            int temp_value = 0;
            for(int j=0; j<8; j++){
                if(arr[j] != result[i][j])temp_value++;
            }
            ans = min(ans,temp_value);
        }

        printf("Case %d: %d\n", cases++,ans);
    }

	return 0; 
} 
