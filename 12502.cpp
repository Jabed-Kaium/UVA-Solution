#include<bits/stdc++.h>

using namespace std;

int main()
{
    double a,b,c,sum;

    int t;

    cin>>t;

    for(int i=1; i<=t; i++)
    {
        cin>>a>>b>>c;
        double temp=c/(a+b);
        if(a>b)
        {
             sum = temp*a + temp*(a-b);
        }
        else
        {
             sum = c - (temp*b + temp*(b-a));
        }

        cout<<sum<<endl;
    }

    return 0;
}
