#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll n,i;

    while(cin>>n)
    {

    if(n<0)
    {
        break;
    }

     vector <ll> m;
     vector <ll> f;

     m.push_back(0),f.push_back(1);
     m.push_back(1),f.push_back(1);
     m.push_back(2),f.push_back(2);

     for(i=3; i<=n; i++)
     {
         m.push_back(m[i-1]+m[i-2]+1);
         f.push_back(f[i-1]+f[i-2]);
     }

     cout<<m[n]<<" "<<m[n]+f[n]<<endl;

     m.clear();
     f.clear();

    }

    return 0;
}
