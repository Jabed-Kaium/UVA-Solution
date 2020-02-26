#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>prime;

void sieve(ll n)
{
  ll mark[50000];
  ll i,j,limit = sqrt(n+1);
  mark[0]=1;
  mark[1]=1;
  for(i=4; i<=n; i+=2)mark[i]=1;

  prime.push_back(2);

  for(i=3; i<=n; i+=2){
    if(!mark[i]){
      prime.push_back(i);
      if(i<=limit){
        for(j=i*i; j<=n; j += 2*i){
          mark[j] = 1;
        }
      }
    }
  }
}

ll prime_factorization(ll n)
{
  ll i,j,ans,sum=0,flag=0;
  for(i=0; prime[i]*prime[i]<=n && i<prime.size(); i++){
    ans=1;
    if(n%prime[i]==0){
      flag++;
    while(n%prime[i]==0){
      n/=prime[i];
      ans *= prime[i];
    }
    sum += ans;
  }
  }

  if(flag==1 && n==1)sum++;
  if(n>1){
    if(flag==0){
      return n+1;
    }
    sum += n;
  }

  return sum;
}

int main()
{
  sieve(50000);
  ll n;
  ll i,j;
  ll cases=0;
  while(cin>>n){
    if(n==0)break;
    else if(n==1)printf("Case %lld: %lld\n", ++cases,n+1);
    else{
      printf("Case %lld: %lld\n", ++cases,prime_factorization(n));
    }
  }

  return 0;
}
