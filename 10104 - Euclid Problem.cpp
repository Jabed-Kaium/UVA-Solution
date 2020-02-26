#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,r1,r2,q,r,s1,s2,s,t1,t2,t,x,y,gcd;

    while(cin>>a>>b){
    r1=a;
    r2=b;

    r=1,s1=1,s2=0,t1=0,t2=1;

    while(r!=0)
    {
        q = r1/r2;
        r = r1%r2;

        s = s1-s2*q;
        t = t1-t2*q;

        r1=r2;
        r2=r;
        s1=s2;
        s2=s;
        t1=t2;
        t2=t;
    }
    x = s1;
    y = t1;
    gcd = r1;
    cout<<x<<" "<<y<<" "<<gcd<<endl;
}

    return 0;
}
