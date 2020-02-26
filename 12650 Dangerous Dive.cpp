#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,r,x;
  vector <int> l1;
  vector <int> l2;
  vector <int>::iterator it;
  vector <int>::iterator it1;


  while(cin>>n>>r){
    for(int i=1; i<=n; i++){
      l1.push_back(i);
    }
    for(int i=0; i<r; i++){
      cin>>x;
      l2.push_back(x);
    }
    for(it=l2.begin(); it!=l2.end(); it++){
      it1 = find(l1.begin(),l1.end(),*it);
      l1.erase(it1);
    }
    if(!l1.empty()){
      sort(l1.begin(),l1.end());
      for(int i=0; i!=l1.size(); i++)
      {
        cout<<l1[i]<<" ";
      }
     }
    else{
      cout<<"*";
    }
    l1.clear();
    l2.clear();
    cout<<endl;
  }
  return 0;
}
