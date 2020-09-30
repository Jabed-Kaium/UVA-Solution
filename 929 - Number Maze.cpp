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

const int MAX = 1000000000;
const int MX = 1000005;
vector<pair<int,int> > vec[MX];
int a[1005][1005];
int dis[MX];
bool vis[MX];
int n,m;

bool isValid(int x,int y){
    if(x < 1 || x > n || y < 1 || y > m)
    return false;

    return true;
}

void dijkstra(int src){
    dis[src] = 0;
    priority_queue < pair<int,int> > pqq;
    pqq.push({0,src});
    while(!pqq.empty()){
        pair<int,int> p = pqq.top();
        pqq.pop();
        int a = p.second;
        if(vis[a] == 1)continue;
        vis[a] = 1;
        for(auto p : vec[a]){
            int b = p.first , w = p.second;
            int val = dis[a] + w;
            if(dis[b] > val){
                dis[b] = val;
                pqq.push(make_pair(-dis[b],b));
            }
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
    
    int t;
    cin>>t;
    while(t--){
        for(int i=0; i<MX; i++){
            vec[i].clear();
            dis[i] = MAX;
            vis[i] = 0;
        }
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>a[i][j];
            }
        }
        int idx=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(isValid(i-1 , j)){
                    vec[idx].pb({idx-m,a[i-1][j]});
                }
                if(isValid(i+1 , j)){
                    vec[idx].pb({idx+m,a[i+1][j]});
                }
                if(isValid(i , j+1)){
                    vec[idx].pb({idx+1,a[i][j+1]});
                }
                if(isValid(i , j-1)){
                    vec[idx].pb({idx-1,a[i][j-1]});
                }
                idx++;
            }
        }

        dijkstra(1);

        int ans = dis[n*m] + a[1][1];

        cout << ans << "\n";
    }

    return 0;
}