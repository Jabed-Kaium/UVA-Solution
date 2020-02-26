#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t,n,r,result;
  cin>>t;
  while(t--){
    cin>>n;
    result = n*567;
    result /= 9;
    result += 7492;
    result *= 235;
    result /= 47;
    result -= 498;
    for(int i=0; i<2; i++){
       r=result%10;
      result /= 10;
    }
    cout<<abs(r)<<endl;
    }
  return 0;
}
