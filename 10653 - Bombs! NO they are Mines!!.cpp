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
int a[MX][MX],dis[MX][MX];
bool vis[MX][MX];
int r,c;

bool isValid(int x,int y){
    if(x<1 || x>r || y<1 || y>c)return false;

    if(vis[x][y] == 1 || a[x][y] == 0)return false;

    return true;
}

void bfs(int srcX,int srcY){
    vis[srcX][srcY] = 1;
    dis[srcX][srcY] = 0;
    queue<pair<int,int > > q;
    q.push({srcX,srcY});

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();

        int currX = p.first , currY = p.second;
        for(int i=0; i<4; i++){
            if(isValid(currX + dx[i] , currY + dy[i])){
                int newX = currX + dx[i] , newY = currY + dy[i];
                dis[newX][newY] = dis[currX][currY] + 1;
                vis[newX][newY] = 1;
                q.push({newX,newY});
            }
        }
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    fastio
    
    while(cin>>r>>c){
        if(r == 0 && c == 0)break;
        for(int i=0; i<=r; i++){
            for(int j=0; j<=c; j++){
                a[i][j] = 1;
                vis[i][j] = 0;
                dis[i][j] = 0;
            }
        }
        int n;
        cin>>n;
        while(n--){
            int row,bomb,col;
            cin>>row>>bomb;
            while(bomb--){
                cin>>col;
                a[row+1][col+1] = 0;
            }
        }
        int startX,startY,endX,endY;
        cin>>startX>>startY;
        cin>>endX>>endY;
        startX++,startY++,endX++,endY++;
        bfs(startX,startY);

        cout << dis[endX][endY] << "\n";

    }

    return 0;
}