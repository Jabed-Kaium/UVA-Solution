#include<bits/stdc++.h>
using namespace std;

string add(string a,string b)
{
  char r[1005];
  int i,j,c=0,l1,l2,s,k;
  l1 = a.length();
  l2 = b.length();
  i = l1-1;
  j = l2-1;
  if(l1>l2) k=l1;
  else k=l2;
  r[k] = '\0';
  k--;

  while(i>=0 && j>=0)
  {
      s = (a[i]-48)+(b[j]-48)+c;
      r[k] = s%10 + 48;
      c = s/10;
      i--;
      j--;
      k--;
  }

  if(i>=0)
  {
      while(i>=0)
      {
          s = (a[i]-48)+c;
          r[k] = s%10 + 48;
          c = s/10;
          i--;
          k--;
      }
  }
  else if(j>=0)
  {
      while(j>=0)
      {
          s = (b[j]-48)+c;
          r[k] = s%10 + 48;
          c = s/10;
          j--;
          k--;
      }
  }

  if(c>0)
  {
      int len = strlen(r);
      for(i=len; i>=0; i--)
      {
          r[i+1] = r[i];
      }
      r[0] = c+48;
  }

  return r;
}

int main()
{
  string s1,s2,s3;
  int n,i;
  while(cin>>n){
    s1="1";
    s2="1";
    for(i=3; i<=n; i++){
    s3 = add(s1,s2);
    s1=s2;
    s2=s3;
  }

  cout<<s3<<endl;

  }
  return 0;
}
