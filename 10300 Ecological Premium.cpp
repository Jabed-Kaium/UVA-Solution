#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,i,p,j;
    double a,b,c;
    vector <double> v;

    cin>>t;

    for(i=1; i<=t; i++)
    {
        cin>>p;

        double sum=0;

        for(j=1; j<=p; j++)
        {
            cin>>a>>b>>c;

            double temp = (a/b)*c*b;

            sum += temp;

        }


        cout<<(int)sum<<endl;

        v.clear();
    }


    return 0;
}
