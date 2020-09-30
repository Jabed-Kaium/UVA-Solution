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

const int MX = 205;
map<string,int> mp;
vector<int> vec[MX];
bool vis[MX];
int dis[MX];

void bfs(int src){
    vis[src] = 1;
    dis[src] = 0;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto p : vec[node]){
            if(!vis[p]){
                vis[p] = 1;
                dis[p] = dis[node] + 1;
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
    
    int t;
    cin>>t;
    while(t--){
        mp.clear();
        string s;
        int c=1;
        while(cin>>s){
            if(s == "*")break;

            mp[s]  = c++;
        }

        for(int i=0; i<MX; i++){
            vec[i].clear();
        }

        for(auto it=mp.begin(); it!=mp.end(); it++){
            for(auto it2=mp.begin(); it2!=mp.end(); it2++){
                if(it != it2){
                    string s1 = it->first , s2 = it2->first;
                    int a = it->second , b = it2->second;

                    if(s1.size() != s2.size())continue;

                    int i,j,diff=0;
                    for(i=0,j=0; i<s1.size() && j<s2.size(); i++,j++){
                        if(s1[i] != s2[j])diff++;
                    }
                    if(diff == 1){
                        vec[a].pb(b);
                    }
                }
            }
        }

        string in,start,end;
        cin.ignore();
        while(getline(cin,in) && in != ""){
            stringstream str(in);
            str >> start >> end;
            clr(dis);
            clr(vis);
            int a = mp[start] , b = mp[end];
            bfs(a);

            cout << start << " " << end << " " << dis[b] << "\n";
        }
        if(t)cout << "\n";
    }

    return 0;
}