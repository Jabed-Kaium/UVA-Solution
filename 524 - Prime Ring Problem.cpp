
//method used : recursive backtracking

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ll long long

int check[20];
int mark[105];

int n;

void sieve(int n)
{
  int i,j,limit = sqrt(n*1.0)+2;
  mark[0]=1;
  mark[1]=1;
  for(i=4; i<=n; i+=2)mark[i]=1;

  for(i=3; i<=n; i+=2){
    if(!mark[i]){
      if(i<=limit){
        for(j=i*i; j<=n; j += 2*i){
          mark[j] = 1;
        }
      }
    }
  }
}

void printElement(stack<int> stk){
    vector<int> v;
    while(!stk.empty()){
        v.pb(stk.top());
        stk.pop();
    }

    for(int i=n-1; i>=0; i--){
        if(i == 0){
            printf("%d", v[i]);
        }
        else{
            printf("%d ", v[i]);
        }        
    }
    printf("\n");
}

void solve(stack<int> stk, int i, int cnt){
    if(cnt == n){           //base case : if we got a permutation of 1-n that fulfills the condition
        printElement(stk);
        return;
    }

    for(int j=2; j<=n; j++){
        if(mark[i+j] == 0 && check[j] == 0){    //if sum of two adjacent is prime and j is not present in the list
            if(cnt == n-1){
                if(mark[j+1] == 0){     //if j is last element and j+1 is prime
                    check[j] = 1;
                    stk.push(j);
                    solve(stk,j,cnt+1); //recursively check for next adjacent
                    check[j] = 0;
                    stk.pop();
                }
            }
            else{
                check[j] = 1;
                stk.push(j);
                solve(stk,j,cnt+1); //recursively check for next adjacent
                check[j] = 0;
                stk.pop();
            }
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(100);

    int t=1;

    while(scanf("%d", &n) != EOF){
        memset(check,0,sizeof(check));
        check[0] = 1;
        check[1] = 1;
        stack <int> stk;
        stk.push(1);

        if(t>1)printf("\n");

        printf("Case %d:\n", t++);
        solve(stk,1,1);
    }


    return 0;
}