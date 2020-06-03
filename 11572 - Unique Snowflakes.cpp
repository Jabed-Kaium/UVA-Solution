#include<bits/stdc++.h>
using namespace std;
int id[1000002];

int main()
{
    int n,i,ans,begin,testCase;
    map <int,int> last;

    scanf("%d", &testCase);

    while(testCase--){  
        last.clear();
        ans=0,begin=1;
        scanf("%d", &n);
        for(i=1; i<=n; i++){
            scanf("%d", &id[i]);
            if(last[id[i]]>=begin){
                begin = last[id[i]] + 1;
            }
            last[id[i]] = i;
            if((i-begin+1) > ans)ans = (i-begin+1);
        }
        printf("%d\n", ans);
    }


    return 0;
}