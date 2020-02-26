#include<bits/stdc++.h>
using namespace std;
int main()
{
  double x,y,r,res;
  int t;
  cin>>t;
  while(t--){
    cin>>x>>y>>r;
    res = sqrt((x*x)+(y*y));
    printf("%.2lf %.2lf\n",r-res,r+res);
  }

  return 0;
}
