#include<bits/stdc++.h>
using namespace std;
int main()
{
  string str;
  int counter=1;
  while(getline(cin,str) && str!="end"){
    vector < stack<char> > stacks;
    stack <char> s;
    int len = str.length();
    s.push(str[0]);
    stacks.push_back(s);
    s.pop();

    for(int i=1; i<len; i++){
      bool flag=true;
      for(int j=0; j<stacks.size(); j++){
        if(str[i]<=stacks[j].top()){
          stacks[j].push(str[i]);
          flag=false;
          break;
        }
      }
      if(flag){
        s.push(str[i]);
        stacks.push_back(s);
        s.pop();
      }
    }

    cout<<"Case "<<counter<<": "<<stacks.size()<<"\n";
    counter++;
    stacks.clear();
  }

  return 0;
}
