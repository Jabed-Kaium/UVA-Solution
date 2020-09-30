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

const int MX = 2510;
vector<int> vec[MX];
int dis[MX] , cnt[MX];
bool vis[MX];

void bfs(int src){
    vis[src] = 1;
    dis[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto p : vec[curr]){
            if(!vis[p]){
                vis[p] = 1;
                dis[p] = dis[curr] + 1;
                cnt[dis[p]]++;
                q.push(p);
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
    
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int num;
        cin>>num;
        while(num--){
            int x;
            cin>>x;
            vec[i].pb(x+1);
        }
    }
    int q;
    cin>>q;
    while(q--){
        clr(dis);
        clr(vis);
        clr(cnt);
        int a;
        cin>>a;
        a++;
        if(vec[a].size() == 0){
            cout << "0\n";
            continue;
        }
        bfs(a);

        int ans=INT_MIN , index=-1;
        for(int i=1; i<MX; i++){
            if(cnt[i] > ans){
                ans = cnt[i];
                index = i;
            }
        }

        cout << ans << " " << index << "\n";
    }

    return 0;
}