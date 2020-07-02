#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ll long long

struct car{
    string name;
    int low;
    int high;
};

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        ll n,q;
        cin>>n;
        struct car arr[n+1];
        for(int i=0; i<n; i++){
            cin>>arr[i].name>>arr[i].low>>arr[i].high;
        }
        cin>>q;
        while(q--){
            string ans;
            int cnt=0;
            int price;
            cin>>price;
            for(int i=0; i<n; i++){
                if(price >= arr[i].low && price <= arr[i].high){
                    ans = arr[i].name;
                    cnt++;
                }
            }
            if(cnt != 1){
                cout << "UNDETERMINED\n";
            }
            else{
                cout << ans << "\n";
            }
        }
        if(tt!=t)cout<<"\n";
    }
    
    return 0;
}