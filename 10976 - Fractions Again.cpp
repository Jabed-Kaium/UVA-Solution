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
    
    ll k;
    while(cin>>k){
        ll i,j;
        vector < pair<ll,ll> > v;
        for(i=k+1; i<=2*k; i++){
            double temp = 1.0*(i*k)/(i-k);
            if(floor(temp) == ceil(temp)){
                v.pb(make_pair((ll)temp,i));
            }
        }
        printf("%d\n", v.size());
        for(int i=0; i<v.size(); i++){
            printf("1/%lld = 1/%lld + 1/%lld\n", k,v[i].first,v[i].second);
        }
    }
    
    return 0;
}