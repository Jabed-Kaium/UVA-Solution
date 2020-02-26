#include<bits/stdc++.h>

using namespace std;

long long int add(long long int n)
{
    long long int sum=0;
    while(n!=0)
    {
        sum = sum+(n%10);
        n=n/10;
    }

    return sum;
}

int main()
{
    long long int n;

    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        else if(n>0 && n<=9)
        {
            cout<<n<<endl;
        }
        else
        {
            long long int temp = n;
            while(temp>9)
            {
                temp = add(temp);
            }

            cout<<temp<<endl;
        }
    }

    return 0;
}
