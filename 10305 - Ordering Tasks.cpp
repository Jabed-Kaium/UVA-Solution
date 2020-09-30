//Idea : Topological Sort

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
int in[MX];
vector<int> res;

void kahn(int n){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        res.pb(curr);
        q.pop();

        for(int node : vec[curr]){
            in[node]--;
            if(in[node]==0){
                q.push(node);
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
    
    int n,m;
    while(cin>>n>>m){
        if(n==0 && m==0)break;

        for(int i=0; i<MX; i++){
            vec[i].clear();
            in[i] = 0;
        }
        res.clear();

        int a,b;
        while(m--){
            cin>>a>>b;
            vec[a].pb(b);
            in[b]++;
        }

        kahn(n);

        for(int node : res){
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}