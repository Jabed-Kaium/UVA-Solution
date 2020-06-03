#include<bits/stdc++.h>
using namespace std;

int main()
{
    int testCase,i,j;
    double totalTrees;
    scanf("%d", &testCase);
    cin.ignore();
    cin.ignore();
    while(testCase--){
        map <string,int> tree;
        map<string,int>::iterator it;
        string treeName;
        totalTrees=0;
        while(getline(cin,treeName)){
            if(treeName=="")break;
            tree[treeName]++;
            totalTrees++;
        }
        for(it=tree.begin(); it!=tree.end(); it++){
            cout<<it->first<<" "<<fixed<<setprecision(4)<<it->second*100 / totalTrees<<"\n"; 
        }
        if(testCase)printf("\n");
    }

    return 0;
}