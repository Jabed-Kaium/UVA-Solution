
/// Maximum sub rectangle in a matrix using Kadane's Algorithm
/// Time Complexity : O(col*col*row)
/// Space Complexity : O(row)

#include<bits/stdc++.h>
using namespace std;
#define R 100
#define C 100
int input[R][C];

int MaxSubArray(int a[],int n,int &start,int &end)
{
   int max=0;
   int max_so_far = INT_MIN;  //initialize with very large negative value
   int s=0;  //starting index of a subarray
   start=0;  //left bound of subarray
   end=0;  //right bound of subarray
   for(int i=0; i<n; i++){
      max = max + a[i];
      if(max > max_so_far){
         max_so_far = max;
         start = s;
         end = i;
      }
      if(max < 0){
         max = 0;
         s = i+1; //starts a new subarray
      }
   }
   return max_so_far;
}

int MaxSum2D(int a[][C],int row,int col)
{
   int currentSum;  //hold the sum of current sub rectangle
   int maxSum = INT_MIN; //initialize maximum sum with very large negative value
   int maxLeft,maxRight,maxUp,maxDown;
   int left,right;  //for holding the left & right bound of maximum subarray of temp
   int temp[row];
   for(int i=0; i<col; i++){
      for(int j=0; j<row; j++){
         temp[j]=0;
      }
      for(int j=i; j<col; j++){   //traversing column by column
         for(int k=0; k<row; k++){
            temp[k] += a[k][j];
         }
         currentSum = MaxSubArray(temp,row,left,right);
         if(currentSum > maxSum){
            maxSum = currentSum;    //maximum sum 
            maxLeft = i;      //left bound of maximum sum submatrix
            maxRight = j;     //right bound of maximum sum submatrix
            maxUp = left;     //upper bound of maximum sum submatrix
            maxDown = right;  //lower bound of maximum sum submatrix
         }
      }
   }

   return maxSum;
}

int main()
{
   int n;
   cin>>n;

   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         cin>>input[i][j];
      }
   }

   cout<<MaxSum2D(input,n,n)<<"\n";

   return 0;
}