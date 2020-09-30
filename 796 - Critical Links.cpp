//Idea : Finding Bridge

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

const int MX = 10005;
vector<pair<int,int> > ans;
vector<int> vec[MX];
int in[MX] , low[MX] , vis[MX];
int timer;
int n,u,v,x;

void dfs(int node , int par = -1){
    vis[node] = 1;
    in[node] = low[node] = timer++;

    for(int child : vec[node]){
        if(child == par)continue;
        if(vis[child]==1){
            low[node] = min(low[node] , in[child]);
        }
        else{
            dfs(child,node);
            if(low[child] > in[node]){
                int mini = min(node,child);
                int maxi = max(node,child);
                ans.pb({mini,maxi});
            }
            low[node] = min(low[node] , low[child]);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    fastio
    
    while(scanf("%d", &n) != EOF){
        for(int i=0; i<MX; i++){
            vec[i].clear();
            low[i] = 0;
            in[i] = 0;
            vis[i] = 0;
        }
        ans.clear();
        timer=0;

        for(int i=0; i<n; i++){
            scanf("%d (%d)", &u,&v);
            for(int j=0; j<v; j++){
                scanf("%d", &x);
                vec[u].pb(x);
                vec[x].pb(u);
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,-1);
            }
        }
        sort(ans.begin() , ans.end());
        cout << ans.size() << " critical links\n";
        for(auto p=ans.begin() ; p!=ans.end(); p++){
            cout << p->first << " - " << p->second << "\n";
        }
        cout << "\n";
    }

    return 0;
}