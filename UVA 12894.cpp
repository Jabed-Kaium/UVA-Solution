#include<iostream>
#include<cmath>
#define pi acos(-1)

using namespace std;

int main()
{
    int t;
    double x0,y0,x1,y1,c_x,c_y,r;
    cin>>t;

    for(int i=1; i<=t; i++)
    {
        cin>>x0>>y0>>x1>>y1>>c_x>>c_y>>r;

        double length = x1+x0;
        double distance = x1-x0;
        double width = y1+y0;
        double w = y1-y0;
        double w1 = w/2;
        double d = (distance/20)*9;
        double r1 = distance/5;

        if((distance/10)*6==w && r==r1 && c_x==d+x0 && c_y==w1+y0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}

