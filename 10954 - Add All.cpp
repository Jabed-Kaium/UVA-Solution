#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp;
    while(scanf("%d",&n) && n!=0){
        priority_queue< int, vector<int>, greater<int> > pq;
        while(n--){
            int x;
            scanf("%d", &x);
            pq.push(x);
        }
        int total=0,cost=0;
        while(pq.size()>1){
            total=pq.top();
            pq.pop();
            temp = total+pq.top();
            cost+=(temp);
            pq.pop();
            pq.push(temp);
        }

        printf("%d\n", cost);
    }

    return 0;
}