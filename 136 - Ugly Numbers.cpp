#include<iostream>
#include<set>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<ll> ugly;

    ugly.insert(1); //first ugly number
    ll cnt = 0; //count for ugly number
    ll value;
    while(cnt<1500){
      value = *(ugly.begin());

      /*insert following ugly numbers*/
      ugly.insert(value*2);
      ugly.insert(value*3);
      ugly.insert(value*5);

      ugly.erase(ugly.begin());

      cnt++;

    }

    cout<<"The 1500'th ugly number is "<<value<<".\n";

  return 0;
}