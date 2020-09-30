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

vector<int> vec[30];
vector<int> tr[30];
int vis[30];
map<string,int> mp1;
string names[30];
vector<int> order;
vector<int> scc;
string str1 , str2;
int n,m;

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
    scc.pb(node);
}

void all_clear(){
    for(int i=0; i<30; i++){
        vec[i].clear();
        tr[i].clear();
        vis[i] = 0;
        names[i].clear();
    }
    order.clear();
    scc.clear();
    mp1.clear();
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    //fastio

    int tc = 1;
    while(scanf("%d %d", &n,&m) == 2 && n!=0 && m!=0){
        if(tc > 1)cout << "\n";

        all_clear();

        int id=1;
        while(m--){
            int x,y;
            //scanf("%s %s", &str1,&str2);
            cin>>str1>>str2;
            if(mp1.find(str1) == mp1.end()){
                mp1[str1] = id;
                names[id] = str1;
                x = id;
                id++;
            }
            else{
                x = mp1[str1];
            }

            if(mp1.find(str2) == mp1.end()){
                mp1[str2] = id;
                names[id] = str2;
                y = id;
                id++;
            }
            else{
                y = mp1[str2];
            }

            vec[x].pb(y);
            tr[y].pb(x);
        }

        for(int i=1; i<=n; i++){
            if(vis[i] == 0){
                dfs(i);
            }
        }
        clr(vis);

        printf("Calling circles for data set %d:\n", tc++);
        for(int i=1; i<=n; i++){
            if(vis[order[n-i]] == 0){
                scc.clear();
                dfs1(order[n-i]);

                int len = scc.size();
                for(int j=0; j<len; j++){
                    if(j == (len-1)){
                        cout << names[scc[j]];
                    }
                    else{
                        cout << names[scc[j]] << ", ";
                    }
                }
                cout << "\n";
            }
        }
    }
    
    return 0;
}