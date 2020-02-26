#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll phi(ll n)
{
  ll ret = n;
  for(ll i=2; i*i<=n; i++){
    if(n%i==0){
      //i is a prime dividing n
      while(n%i==0){
        //devide all the factors of i
        n /= i;
        }
        // same as ret*(1-1/p)
        ret -= ret/i;
      }
    }
    if(n>1){
      //there can be only one prime greater
      //than sqrt(n) that divides n
      ret -= ret/n;
    }
    return ret;
}

int main()
{
  ll n;
  while(scanf("%lld", &n)!=EOF){
    if(n==0)break;
    if(n==1){
      printf("0\n");
    }
    else{
    ll res = phi(n);
    printf("%lld\n", res);
  }
  }

  return 0;
}
