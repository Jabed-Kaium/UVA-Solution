#include<bits/stdc++.h>
using namespace std;
int main()
{
  list <char> list1;
  list <char> list2;
  string s;
  while(getline(cin,s)){
    if(s=="DONE")break;
    int len = s.length();
    for(int i=0; i<len; i++){
      if(s[i]>='A' && s[i]<='Z'){
        list1.push_back(s[i]-'A'+'a');
      }
      else if(s[i]>='a' && s[i]<='z'){
        list1.push_back(s[i]);
      }
    }
    list2 = list1;
    list1.reverse();
    if(list2==list1)cout<<"You won't be eaten!"<<endl;
    else cout<<"Uh oh.."<<endl;

    list1.clear();
    list2.clear();
  }

  return 0;

}
