#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int main()
{
    int n,q,p;
    string s;
    priority_queue< pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > pq;
    while(true){
        cin>>s;
        if(s=="Register"){
            scanf("%d %d", &q,&p);
            pq.push(pair<int, pair<int,int> >(p,pair<int,int>(q,p)));
        }
        else if(s=="#")break;
    }

    scanf("%d", &n);

    while(n--){
        pair<int, pair<int,int> > top = pq.top();
        cout<<top.second.first<<"\n";
        top.first += top.second.second;
        pq.pop();
        pq.push(top);
    }

    return 0;
}