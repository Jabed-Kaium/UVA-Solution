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
    
    int n,m;
    while(cin>>n>>m){
        vector<double>v,v1,v2;
        for(int i=0; i<n; i++){
            double x;
            cin>>x;
            v.pb(x);
        }
        for(int i=0; i<m; i++){
            double x;
            cin>>x;
            v1.pb(x);
        }
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v1.size(); j++){
                v2.pb(v1[j]/v[i]);
            }
        }
        sort(v2.begin(), v2.end());
        double ans = INT_MIN;
        for(int i=0; i<v2.size()-1; i++){
            ans = max(ans,v2[i+1]/v2[i]);
        }

        printf("%0.2lf\n", ans);
    }

    return 0;
}