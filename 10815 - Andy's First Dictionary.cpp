#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> s;
    string input;

    while(getline(cin,input)){
    int len = input.length();
    string temp = "";
    for(int i=0; i<len; i++){
        if(isalpha(input[i])){  //check whether an alphabet or not
            temp += (tolower(input[i]));
        }
        else{
            if(temp.length()!=0){
                s.insert(temp);
            }   
            temp = "";
        } 
    }
    if(temp.length()!=0){ //if there exist a last word in line
            s.insert(temp);
        }  
  }

    for(set<string>::iterator it = s.begin(); it!=s.end(); it++){
        cout<<*it<<"\n";
    }

    return 0;
}