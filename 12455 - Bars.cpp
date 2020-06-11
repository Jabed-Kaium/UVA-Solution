
//Technique used: Subset using bitmask
//Complexity : O(2^n * n)

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

int a[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,x,n;
    cin>>t;
    while(t--){
        cin>>x>>n;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        bool flag = false;
        int sum;
        for(int i=0; i<(1<<n); i++){    //check all 2^n subset(2^n == 1<<n)
            sum = 0;
            for(int j=0; j<n; j++){
                if(i & (1<<j)){    //check whether that element present in subset or not
                    sum += a[j];
                }
            }
            if(sum == x){
                flag = true;
                break;
            }
        }

        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}