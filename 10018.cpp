#include<iostream>

using namespace std;
typedef long long ll;

ll findrev(ll n)
{
    ll sum=0,r,temp;
    temp = n;
    while(temp!=0)
    {
        r=temp%10;
        sum=(sum*10)+r;
        temp=temp/10;
    }

    return sum;
}

int main()
{
    ll t,n,rev,c;

    cin>>t;

    while(t--)
    {
        cin>>n;
        c=0;
        rev = findrev(n);
        while(n!=rev)
        {
            n = n+rev;
            rev = findrev(n);
            c++;
        }

        cout<<c<<" "<<rev<<endl;
    }


    return 0;
}
