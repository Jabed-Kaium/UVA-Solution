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

const int MX = 100005;
vector<int> vec[MX];
int vis[MX];
vector<int> order;
int n,m,a,b;

void dfs(int node){
    vis[node] = 1;
    for(int child : vec[node]){
        if(vis[child] == 0){
            dfs(child);
        }
    }
    order.pb(node);
}

void dfs1(int node){
    vis[node] = 1;
    for(int child : vec[node]){
        if(vis[child] == 0){
            dfs1(child);
        }
    }
}

void all_clear(){
    for(int i=0; i<MX; i++){
        vec[i].clear();
        vis[i] = 0;
    }
    order.clear();
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    fastio

    int t;
    cin>>t;
    while(t--){

        all_clear();

        cin>>n>>m;
        for(int i=1; i<=m; i++){
            cin>>a>>b;
            vec[a].pb(b);
        }

        for(int i=1; i<=n; i++){
            if(vis[i] == 0){
                dfs(i);
            }
        }

        clr(vis);
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(vis[order[n-i]] == 0){
                dfs1(order[n-i]);
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}