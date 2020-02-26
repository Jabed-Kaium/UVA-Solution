#include<bits/stdc++.h>
using namespace std;
int main()
{
  int p,h,o;
  while(cin>>p>>h>>o){
    int x = o-h;
    if(x==p)cout<<"Props win!"<<endl;
    else if(x>p){
      cout<<"Props win!"<<endl;
    }
    else{
      cout<<"Hunters win!"<<endl;
    }
  }
  return 0;
}
