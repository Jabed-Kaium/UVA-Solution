#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,n,idx,temp,i,j;

    cin>>t;
    for(i=1; i<=t; i++){
        cin>>n;
        ll cnt = 0; //counting round
        for(j=1; j>0; j++){
            temp = pow(2,j);
            if(temp>=n)break; //calculating highest 2^j <= n
        }
        if(temp>n){
            temp = pow(2,j-1);
        }
        idx = 2 * (n-temp) + 1; //index who survives

        //go to next round until idx==n
        while(idx!=n){
            cnt++;
            n = idx;
            for(j=1; j>0; j++){
                temp = pow(2,j);
                if(temp>=n)break;
            }
            if(temp>n){
                temp = pow(2,j-1);
            }
            idx = 2 * (n-temp) + 1;
        }

        printf("Case %lld: %lld %lld\n", i,cnt,idx);
    }

    return 0;
}