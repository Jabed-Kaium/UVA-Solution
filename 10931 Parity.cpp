#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> binary;

    long long x;

    while(cin>>x)
    {
        if(x==0)break;

        long long temp = x,c=0;
        while(temp!=0)
        {
            long long y = temp%2;
            binary.push_back(y);
            temp /= 2;
        }
        reverse(binary.begin(),binary.end());

        for(long long i=0; i<binary.size(); i++)
        {
            if(binary[i]==1)c++;
        }

        cout<<"The parity of ";
        for(long long i=0; i<binary.size(); i++)
        {
            cout<<binary[i];
        }

        cout<<" is "<<c<<" (mod 2)."<<endl;

        binary.clear();
    }


    return 0;
}
