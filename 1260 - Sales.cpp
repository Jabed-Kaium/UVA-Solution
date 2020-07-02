#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ll long long

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n;
    cin>>t;
    while(t--){
        int sum=0;
        cin>>n;
        int a[n+2];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=1; i<n; i++){
            int cnt=0;
            for(int j=0; j<i; j++){
                if(a[j] <= a[i])cnt++;
            }
            sum += cnt;
        }
        cout << sum << "\n";
    }

    return 0;
}