#include<iostream>

using namespace std;

int main()

{
    int n;

    for(int i=1; i<=2000; i++)
    {
        cin>>n;
        int c=0;
        if(n<0)break;
        else if(n==1)
        {
            cout<<"Case "<<i<<": "<<c<<endl;
        }

        else
        {

            for(int sum=1; sum<=n; )
            {
                sum=sum+sum;
                c++;
                if(sum>=n)break;
            }


            cout<<"Case "<<i<<": "<<c<<endl;
        }
    }


    return 0;
}

