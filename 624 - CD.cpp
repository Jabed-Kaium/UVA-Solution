#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ll long long

int N,M,best,sum,x;
int num[30];
vector <int> bestpath;

void dfs(vector<int>path, int sum, int n){
    sum += num[n];
    path.pb(num[n]);

    if(sum > best || (sum == best && path.size()>bestpath.size())){
        best = sum;
        bestpath = path;
    }

    for(int i=n+1; i<M; i++){
        if(sum + num[i] <= N){
            dfs(path,sum,i);
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(scanf("%d %d", &N,&M) != EOF){

        for(int i=0; i<M; i++){
            scanf("%d", &num[i]);
        }

        best = 0;

        for(int i=0; i<M; i++){
            vector <int> path;
            dfs(path,0,i);
        }

        for(int i=0; i<bestpath.size(); i++){
            printf("%d ", bestpath[i]);
        }
        printf("sum:%d\n", best);
    }

    return 0;
}