#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int MX = 105;
vector<int> vec[MX];
int in[MX] , low[MX] , vis[MX];
int timer;
set <int> ans;
int n,m,x;
char c;

void dfs(int node , int par = -1){
    vis[node] = 1;
    in[node] = low[node] = timer++;
    int children = 0;
    for(int child : vec[node]){
        if(child == par)continue;
        if(vis[child] == 1){
            low[node] = min(low[node] , in[child]);
        }
        else{
            dfs(child , node);
            low[node] = min(low[node] , low[child]);
            if(low[child] >= in[node] && par != -1){
                ans.insert(node);
            }
            ++children;
        }
    }
    if(par == -1 && children > 1){
        ans.insert(node);
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    fastio
    
    while(scanf("%d", &n) == 1 && n){
        ans.clear();
        for(int i=0; i<MX; i++){
            vec[i].clear();
            in[i] = 0;
            low[i] = 0;
            vis[i] = 0;
        }
        timer = 0;

        while(scanf("%d", &m) == 1 && m){
            while(scanf("%d%c", &x,&c) == 2){
                vec[m].pb(x);
                vec[x].pb(m);
                if(c == '\n')break;
            }
        }

        dfs(1);

        cout << ans.size() << "\n";
    }

    return 0;
}