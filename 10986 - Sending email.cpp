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

const int MX = 20005;
const int MAX = 1000000000;
vector <pair<int,int> > vec[MX];
int dis[MX];
bool vis[MX];
int n,m,s,t,a,b,w;

void dijkstra(int src)
{
    dis[src] = 0;
    priority_queue < pair < int , int > > pqq;
    pqq.push({0,src});
    while(!pqq.empty()){
        pair < int , int > p = pqq.top();
        pqq.pop();
        int a = p.second;
        if(vis[a] == 1) continue;
        vis[a] = 1;
        for(auto p:vec[a]){
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
    
    int tc;
    cin>>tc;
    for(int tt=1; tt<=tc; tt++){
        for(int i=0; i<MX; i++){
            vec[i].clear();
            dis[i] = MAX;
            vis[i] = 0;
        }
        cin>>n>>m>>s>>t;
        while(m--){
            cin>>a>>b>>w;
            vec[a+1].pb({b+1,w});
            vec[b+1].pb({a+1,w});
        }

        dijkstra(s+1);

        if(dis[t+1] == MAX){
            cout << "Case #" << tt << ": " << "unreachable\n";
        }
        else{
            cout << "Case #" << tt << ": " << dis[t+1] << "\n";
        }
    }

    return 0;
}