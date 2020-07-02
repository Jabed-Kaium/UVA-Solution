#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ll long long

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m;
    while(cin>>m){
        char c;
        vector <pair<int,int> > v1,v2;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                cin>>c;
                if(c == '1'){
                    v1.pb(make_pair(i,j));
                }
                else if(c == '3'){
                    v2.pb(make_pair(i,j));
                }
            }
        }

        int res = 0,mini;

        for(int i=0; i<v1.size(); i++){
            mini = INT_MAX;
            for(int j=0; j<v2.size(); j++){
                int temp = abs(v1[i].first - v2[j].first) + abs(v1[i].second - v2[j].second);
                if(temp < mini)mini = temp;
            }
            if(mini > res)res = mini;
        }

        cout << res << "\n";
    }

    return 0;
}