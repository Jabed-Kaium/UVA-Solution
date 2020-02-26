#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll reversing(ll n)
{
    ll temp=n,r,sum=0;
    while(temp!=0)
    {
        r = temp%10;
        sum = sum*10 + r;
        temp /= 10;
    }

    return sum;
}

int main()
{
    ll n;

    while(scanf("%lld", &n)!=EOF)
    {
        ll c1=0,c2=0;
        ll sq = sqrt(n);

        for(ll i=2; i<=sq; i++)
        {
            if(n%i==0)
            {
                ++c1;
                cout<<n<<" is not prime."<<endl;
                break;
            }
        }
        if(c1==0)
        {
            ll rev = reversing(n);
            if(rev!=n)
            {
            ll sq2 = sqrt(rev);
            for(ll i=2; i<=sq2; i++)
            {
                if(rev%i==0)
                {
                    ++c2;
                    cout<<n<<" is prime."<<endl;
                    break;
                }
            }
            }
            else
            {
                    ++c2;
                    cout<<n<<" is prime."<<endl;
            }
        }

        if(c1==0 && c2==0)
        {
            cout<<n<<" is emirp."<<endl;
        }

    }


    return 0;
}
