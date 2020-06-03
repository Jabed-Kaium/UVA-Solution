#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map < string,pair<string,int> > mp;
    map <string,int> mp2;

    string in;
    while(getline(cin,in)){
        if(in=="#")break;
        istringstream word(in);
        string w;
        while(word>>w){
            string temp = w;
            for(int i=0; i<w.length(); i++){
                w[i] = tolower(w[i]);
            }
            sort(w.begin(),w.end());
            string temp2 = w;
            pair<map< string,pair<string,int> >::iterator,bool> checker;
            checker = mp.insert(make_pair(temp2,make_pair(temp,1)));
            if(!checker.second){
                (checker.first)->second.second = 2;
            }
        }
    }
    for(map< string,pair<string,int> >::iterator it = mp.begin(); it!=mp.end(); it++){
        if(it->second.second == 1){
            mp2[it->second.first] = 0;
        }
    }
    for(map<string,int>::iterator it = mp2.begin(); it!=mp2.end(); it++){
        cout<<it->first<<"\n";
    }

    return 0;
}