#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  int t;
  ll a[100005];
  ll n,diff;
  cin>>t;
  for(int i=1; i<=t; i++){
    cin>>n;
    a[0]=0;
    ll max=0;
    for(int j=1; j<=n; j++){
      cin>>a[j];
      if(a[j]-a[j-1]>max)max=a[j]-a[j-1];
    }
    ll res=max;
    for(int j=1; j<=n; j++){
      if(a[j]-a[j-1]==max)max--;
      else if(a[j]-a[j-1]>max){
      res++;
      break;
    }
    }
    cout<<"Case "<<i<<": "<<res<<endl;
  }

  return 0;
}
