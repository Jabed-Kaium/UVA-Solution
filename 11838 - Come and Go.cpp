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

const int MX = 2005;
vector<int> vec[MX];
vector<int> tr[MX];
int vis[MX];
vector<int> order;
int n,m,a,b,p;

void all_clear(){
    for(int i=0; i<MX; i++){
        vec[i].clear();
        tr[i].clear();
        vis[i] = 0;
    }
    order.clear();
}

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
    for(int child : tr[node]){
        if(vis[child] == 0){
            dfs1(child);
        }
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    //fastio

    while(scanf("%d %d", &n,&m) == 2 && n!=0 && m!=0){
        all_clear();

        while(m--){
            cin>>a>>b>>p;
            if(p == 1){
                vec[a].pb(b);
                tr[b].pb(a);
            }
            else{
                vec[a].pb(b);
                vec[b].pb(a);
                tr[a].pb(b);
                tr[b].pb(a);
            }
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

        if(cnt == 1)cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}