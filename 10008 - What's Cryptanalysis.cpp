#include<iostream>
#include<queue>
#include<cctype>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    int hashtable[26] = {0};
    string final;
    string text;
    priority_queue< pair<int,int> > pq;
    int testcase;

    scanf("%d", &testcase);

    cin.ignore();
    while(testcase--){
        getline(cin,text);
        final += text;
    }

    int length = final.length();

    for(int i=0; i<length; i++){
        if(isalpha(final[i])){ // check whether an alphabet or not
            hashtable[toupper(final[i])-'A']++;
        }
    }

    for(int i=0; i<26; i++){
        if(hashtable[i]>0){
            pq.push(make_pair(hashtable[i], -(i+'A')));
        }
    }

    while(!pq.empty()){
        printf("%c %d\n", -(pq.top().second) , pq.top().first);
        pq.pop();
    }
}