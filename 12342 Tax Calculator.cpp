#include<bits/stdc++.h>

using namespace std;

int main()
{
    double k,tax;
    int t,i,j;

    cin>>t;

    for(i=1; i<=t; i++)
    {
        cin>>k;

        if(k<=180000)
        {
            tax = 0;
        }
        else if(k>180000 && k<=480000)
        {
            tax = (k-180000)*0.1;
        }
        else if(k>480000 && k<=880000)
        {
            tax = 30000 + ((k-480000)*0.15);
        }
        else if(k>880000 && k<=1180000)
        {
            tax = 90000 + ((k-880000)*0.2);
        }
        else if(k>1180000)
        {
            tax = 150000 + ((k-1180000)*0.25);
        }

        if(tax<=2000 && tax!=0)
        {
            tax=2000;
            cout<<"Case "<<i<<": "<<tax<<endl;
        }
        else
        {
            cout<<"Case "<<i<<": "<<(int)ceil(tax)<<endl;

        }
    }


    return 0;
}
