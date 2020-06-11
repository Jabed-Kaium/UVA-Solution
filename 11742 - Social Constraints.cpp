#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

struct query{
    int a,b,c;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    while(cin>>n>>m){
        if(n==0 && m==0)break;
        int a[n];
        struct query q[m];
        for(int i=0; i<n; i++){
            a[i] = i;
        }
        for(int i=0; i<m; i++){
            cin>>q[i].a>>q[i].b>>q[i].c;
        }
        int cnt = 0;
        do{
            bool flag = true;
            for(int i=0; i<m && flag==true; i++){
                int x = q[i].a;
                int y = q[i].b;
                int z = q[i].c;
                int in_x,in_y;
                for(int i=0; i<n; i++){
                    if(a[i]==x)in_x = i;
                    if(a[i]==y)in_y = i;
                }
                int len = abs(in_x - in_y);
                if(z > 0){
                    if(len > z)flag = false;
                }
                else if(z < 0){
                    if(len < abs(z))flag = false;
                }
            }
            if(flag)cnt++;
        }while(next_permutation(a,a+n));

        cout << cnt << "\n";
    }
    
    return 0;
}