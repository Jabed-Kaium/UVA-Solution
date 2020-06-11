#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        bool flag = false;
        for(int x=-100; x<=100 && !flag; x++){
            for(int y=-100; y<=100 && !flag; y++){
                for(int z=-100; z<=100 && !flag; z++){
                    if(x!=y && y!=z && x!=z && x+y+z==a && x*y*z==b && x*x+y*y+z*z==c){
                        printf("%d %d %d\n", x,y,z);
                        flag = true;
                    }
                }
            }
        }
        if(!flag){
            printf("No solution.\n");
        }
    }
    
    return 0;
}