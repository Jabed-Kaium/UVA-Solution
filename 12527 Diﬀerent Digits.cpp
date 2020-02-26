#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,r,temp,c,i,num;
  set <int> s;
  while(cin>>n>>m){
    temp = (m-n)+1;
    for(i=n; i<=m; i++){
      num=i;
      c=0;
      while(num!=0){
        r = num%10;
        s.insert(r);
        num/=10;
        c++;
      }
      if(s.size()<c){
        temp--;
      }
      s.clear();
    }
    cout<<temp<<endl;
  }

  return 0;
}
