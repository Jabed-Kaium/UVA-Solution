#include<bits/stdc++.h>
using namespace std;
#define db double
db p,q,r,s,t,u,mid;

db f(db x)
{
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{

  int i,j,k;
  while(cin>>p>>q>>r>>s>>t>>u){
    db lower=0.0;
    db higher=1.0;
    db f1 = f(0.0);
    db f2 = f(1.0);
    if(f1*f2>0){
      cout<<"No solution"<<endl;
    }
    else{
      while(higher-lower>0.0000001){
        mid = (higher+lower)/2;
        if(f(lower)*f(mid)<=0){
          higher=mid;
        }
        else{
          lower=mid;
        }
      }
      printf("%.4lf\n", mid);
    }
   }

  return 0;
}
