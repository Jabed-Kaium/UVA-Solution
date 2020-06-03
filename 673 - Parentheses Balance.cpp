#include<bits/stdc++.h>
using namespace std;
int main()
{
  int len,i,j,n;
  scanf("%d", &n);
  cin.ignore();
  while(n--){
    stack <char> s;
    string str;
    getline(cin,str);
    len = str.length();
    for(i=0; i<len; i++){
      if(str[i]=='[' || str[i]=='('){
        s.push(str[i]);
      }
      else if(str[i]==')'){
        if(s.empty() || s.top()!='('){
          s.push(str[i]);
          break;
        }
        else{
          s.pop();
        }
      }
      else if(str[i]==']'){
        if(s.empty() || s.top()!='['){
          s.push(str[i]);
          break;
        }
        else{
          s.pop();
        }
      }
    }
    if(s.empty()){
      printf("Yes\n");
    }
    else{
      printf("No\n");
    }
  }

  return 0;
}
