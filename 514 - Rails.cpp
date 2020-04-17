#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i,j;
  while(true){
    scanf("%d", &n);
    if(n==0)break;

    int b[1002];
    for(i=0; i<n; i++)b[i]=i+1;
    while(true){
      int a[1002];
      stack<int>s;
      int c=0;
      for(i=0; i<n; i++){
        scanf("%d", &a[i]);
        if(i==0 && a[i]==0){
          c++;
          printf("\n");
          break;
        }
      }
      if(c==0){
        i=0;
        j=0;
        while(i<n && j<n){
          if(!s.empty() && a[i]==s.top()){
            s.pop();
            i++;
          }
          else if(a[i]==b[j]){
            i++;
            j++;
          }
          else{
            s.push(b[j]);
            j++;
          }
        }
        if(s.empty())printf("Yes\n");
        else{
          while(!s.empty() && i<n){
            if(a[i]==s.top()){
              s.pop();
              i++;
            }
            else{
              break;
            }
          }
          if(s.empty())printf("Yes\n");
          else printf("No\n");
        }
      }
      else{
        break;
      }
    }
  }

  return 0;
}
