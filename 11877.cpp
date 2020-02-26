#include<iostream>

using namespace std;

int main()
{
    int i,n;

    for(i=1; i<=10; i++)
    {
        cin>>n;

        if(n==0)break;

        int c = 0,num;
        num = n;

        while(num>=3)
        {
            c = c + num/3;
            num = ((num/3) + (num%3));
        }

        if(num==2)
        {
            cout<<c+1<<endl;
        }
        else
        {
            cout<<c<<endl;
        }

    }

    return 0;
}
