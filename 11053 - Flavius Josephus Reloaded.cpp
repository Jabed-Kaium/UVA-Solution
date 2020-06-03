#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,a,b;
    while(cin>>n){
        if(n==0)break;

        cin>>a>>b;
        map <ll,ll> mp;
        ll idx=0;
        mp[idx]=1;
        while(mp[idx]!=3){
            idx = ((a%n * (idx%n * idx%n)%n)%n + b%n)%n;
            if(mp.find(idx)==mp.end()){
                mp[idx]=1;
            }
            else{
                mp[idx]++;
            }
        }
        ll cnt = 0;
        for(map<ll,ll>::iterator it = mp.begin(); it!=mp.end(); it++){
            if(it->second > 1)cnt++;
        }

        cout<<n-cnt<<"\n";

    }
    
    return 0;
}