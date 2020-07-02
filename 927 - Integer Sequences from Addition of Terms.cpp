#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
	cin>>t;
	while(t--){
		ll a[30];
		ll n,d,k,m,ans,counter;
		cin>>m;
		for(int i=0; i<=m; i++){
			cin>>a[i];
		}
		cin>>d>>k;
		ans=0,counter=0;
		for(n=1; ;n++){
			counter += n*d;
			if(counter >= k)break;
		}

		for(int i=0; i<=m; i++){
			ans += a[i]*pow(n,i);
		}

		cout << ans << "\n";
	}
    
    return 0;
}