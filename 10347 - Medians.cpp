#include<bits/stdc++.h>
using namespace std;
int main()
{
  double a,b,c,s,area,result;
  while(cin>>a>>b>>c){
    if(a+b>c && b+c>a && c+a>b){
    s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    result = (4*area)/3;

    printf("%.3lf\n", result);
  }
  else{
    cout<<"-1.000"<<endl;
  }

    }

  return 0;
}
