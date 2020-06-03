#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,m,value;
    while(scanf("%lld", &n)){
        if(n==0)break;
        multiset <ll> ms;
        multiset <ll>::iterator it;
        multiset <ll>::iterator it2;
        ll total = 0;
        while(n--){
            scanf("%lld", &m);
            
            while(m--){
                scanf("%lld", &value);
                ms.insert(value);
            }
            it = ms.begin();
            it2 = ms.end();
            it2--;
            total += (*it2 - *it);
            if(!ms.empty())ms.erase(it);
            if(!ms.empty())ms.erase(it2);
        }

        printf("%lld\n", total);
    }
}