#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,m,x;
    while(scanf("%lld %lld", &n,&m)){
        if(n==0 && m==0)break;
        set <ll> s;
        ll count=0;
        for(int i=0; i<n; i++){
            scanf("%lld", &x);
            s.insert(x);
        }
        for(int i=0; i<m; i++){
            scanf("%lld", &x);
            if(!s.empty() && s.find(x)!=s.end())count++;
        }

        printf("%lld\n", count);
        s.clear();
    }

    return 0;
}