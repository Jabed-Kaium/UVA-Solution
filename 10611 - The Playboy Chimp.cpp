#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
  vector <ll> v;
  vector <ll>::iterator it;
  vector <ll>::iterator it2;
  ll x,n,q,value;
  cin>>n;
  for(ll i=0; i<n; i++){
    cin>>x;
    v.pb(x);
  }
  cin>>q;
  while(q--){
    cin>>value;
    it = lower_bound(v.begin(),v.end(),value);
    it2 = upper_bound(v.begin(),v.end(),value);

    if(it==v.begin() && it2==v.end()){
      cout<<"X"<<" "<<"X"<<endl;
    }
    else if(it==v.begin() && it2!=v.end()){
      cout<<"X"<<" "<<*it2<<endl;
    }
    else if(it==v.end() && it2==v.end()){
      cout<<v[n-1]<<" "<<"X"<<endl;
    }
    else if(it!=v.end() && it2==v.end()){
      cout<<v[(it-v.begin())-1]<<" "<<"X"<<endl;
    }
    else if(it!=v.end() && it2!=v.end()){
      cout<<v[(it-v.begin())-1]<<" "<<*it2<<endl;
    }

  }

  return 0;
}
