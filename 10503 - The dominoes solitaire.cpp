#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ll long long

int x[50],y[50];
int used[50];
int n,m,flag;

void solve(int cnt, int l){
    if(cnt == n){
        if(l == x[1])flag = 1;

        return;
    }

    for(int i=2; i<m+2; i++){
        if(used[i] == 0){
            if(x[i] == l){
                used[i] = 1;
                solve(cnt+1,y[i]);
                used[i] = 0;
            }
            else if(y[i] == l){
                used[i] = 1;
                solve(cnt+1,x[i]);
                used[i] = 0;
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

    while(scanf("%d", &n) == 1 && n){

        scanf("%d", &m);

        for(int i=0; i<m+2; i++){
            scanf("%d %d", &x[i],&y[i]);
            used[i] = 0;
        }

        flag = 0;

        solve(0,y[0]);

        if(flag == 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}