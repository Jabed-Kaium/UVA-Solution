#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

int a[15];

bool solve(int c,int d){
    memset(a,0,sizeof(a));
    if(c < 10000){
        c *= 10;
    }
    if(d < 10000){
        d *= 10;
    }
    while(c > 0){
        a[c%10]++;
        c /= 10;
    }
    while(d > 0){
        a[d%10]++;
        d /= 10;
    }

    for(int i=0; i<10; i++){
        if(a[i] > 1)return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,cases=0;
    while(cin>>n){
        if(n==0)break;
        if(cases++ > 0)printf("\n");
        bool flag = false;
        for(int i=1234; i<=98765/n; i++){
            if(solve(i,i*n)){
                printf("%05d / %05d = %d\n", i*n,i,n);
                flag = true;
            }
        }
        if(!flag){
            printf("There are no solutions for %d.\n", n);
        }
    }

    return 0;
}