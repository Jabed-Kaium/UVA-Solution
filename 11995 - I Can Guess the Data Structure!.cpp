#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        int x,y;
        stack <int> s;
        queue <int> q;
        priority_queue <int> pq;
        bool isStack = true;
        bool isQueue = true;
        bool isPriority_Queue = true;
        for(int i=1; i<=n; i++){
            scanf("%d %d", &x,&y);
            switch(x){
                case 1 : if(isStack)s.push(y);
                         if(isQueue)q.push(y);
                         if(isPriority_Queue)pq.push(y);
                         break;
                case 2 : if(s.empty() || y!=s.top())
                         isStack = false;
                         else s.pop();

                         if(q.empty() || y!=q.front())
                         isQueue = false;
                         else q.pop();

                         if(pq.empty() || y!=pq.top())
                         isPriority_Queue = false;
                         else pq.pop();

                         break;

            }
        }

        if(isStack == true && isQueue == false && isPriority_Queue == false){
            printf("stack\n");
        }
        else if(isStack == false && isQueue == true && isPriority_Queue == false){
            printf("queue\n");
        }
        else if(isStack == false && isQueue == false && isPriority_Queue == true){
            printf("priority queue\n");
        }
        else if(isStack == false && isQueue == false && isPriority_Queue == false){
            printf("impossible\n");
        }
        else{
            printf("not sure\n");
        }
        
    }

    return 0;
}