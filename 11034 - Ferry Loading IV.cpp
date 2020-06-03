#include<bits/stdc++.h>
using namespace std;

class ferry{
public:
  int length;
  string direction;

  void set(int l,string s){
    length = l;
    direction = s;
  }
  int return_length();
  string return_direction();
};

int ferry::return_length(){
  return length;
}

string ferry::return_direction(){
  return direction;
}

int main()
{
  int x,t,l,m,count,sum,i,j;
  string str;
  bool flag;
  ferry temp,temp1;
  cin>>t;
  while(t--){
    queue <ferry> q1;
    queue <ferry> q2;
    count=0;
    flag = true;
    cin>>l>>m;
    l *= 100;

    while(m--){
      cin>>x>>str;
      if(str=="left"){
        temp.set(x,str);
        q1.push(temp);
      }
      else if(str=="right"){
        temp.set(x,str);
        q2.push(temp);
      }
    }

    while(!q1.empty() || !q2.empty()){
      sum=0;

      if(flag==true && q1.empty()){
        count++;
        flag=false;
        continue;
      }
      if(flag==false && q2.empty()){
        count++;
        flag=true;
        continue;
      }

      if(flag==true && !q1.empty()){
        temp1 = q1.front();
        while(!q1.empty() && sum+temp1.return_length()<=l){
          sum += temp1.return_length();
          q1.pop();
          if(!q1.empty()){
            temp1 = q1.front();
          }
        }
        count++;
        flag=false;
      }
      else if(flag==false && !q2.empty()){
        temp1 = q2.front();
        while(!q2.empty() && sum+temp1.return_length()<=l){
          sum += temp1.return_length();
          q2.pop();
          if(!q2.empty()){
            temp1 = q2.front();
          }
        }
        count++;
        flag=true;
      }
    }
    cout<<count<<"\n";
  }

  return 0;
}
