#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX  20
ll a[MAX+1];

ll fact(ll n)
{
  if(n==1)return 1;
  else{
      return n*fact(n-1);
  }
}

ll ncr(ll n,ll r)
{
  return fact(n) / (fact(r)*fact(n-r));
}

int main()
{
  ll n,m;
  a[0]=1;
  a[1]=0;
  a[2]=1;
  for(int i=3; i<=MAX; i++){
    a[i] = (i-1)*(a[i-1]+a[i-2]);
  }

  while(cin>>n>>m){
    if(n==m){
      cout<<fact(n)<<endl;
    }
    else{
    ll sum=0;
    for(int i=0; i<=m; i++){
      if(i==0){
        sum = a[n];
      }
      else{
        sum += (ncr(n,i)*a[n-i]);
      }
    }

    cout<<sum<<endl;
  }
  }


  return 0;
}
