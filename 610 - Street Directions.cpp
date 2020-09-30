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

const int MX = 1005;
vector<int> vec[MX];
int low[MX] , in[MX] , vis[MX];
int timer;
vector<pair<int,int> > edgeList;
int n,m,a,b;

void dfs(int node , int par = -1){
    vis[node] = 1;
    in[node] = low[node] = timer++;

    for(int child : vec[node]){
        if(child == par)continue;
        if(vis[child] == 1){
            //back edge
            low[node] = min(low[node] , in[child]);
            if(in[node] > in[child]){
                edgeList.pb({node,child});
            }
        }
        else{
            dfs(child , node);
            if(low[child] > in[node]){
                //it's a bridge
                edgeList.pb({node,child});
                edgeList.pb({child,node});
            }
            else{
                //forward edge
                edgeList.pb({node,child});
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

    int tc=1;
    
    while(cin>>n>>m){
        if(n==0 && m==0)break;

        for(int i=0; i<MX; i++){
            vec[i].clear();
            low[i]=0;
            in[i]=0;
            vis[i]=0;
        }
        edgeList.clear();
        timer=0;

        for(int i=0; i<m; i++){
            cin>>a>>b;
            vec[a].pb(b);
            vec[b].pb(a);
        }

        dfs(1,-1);
        cout << tc++ << "\n\n";
        for(auto p : edgeList){
            cout << p.first << " " << p.second << "\n";
        }
        cout << "#\n";
    }

    return 0;
}