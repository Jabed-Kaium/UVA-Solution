#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int l,c=0,x,i,j,temp;
        cin>>l;
        vector <int> v;
        for(i=0; i<l; i++)
        {
            cin>>x;
            v.push_back(x);
        }
        for(i=0; i<l-1; i++)
        {
            for(j=0; j<l-i-1; j++)
            {
                if(v[j]>v[j+1])
                {
                    temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                    ++c;
                }
            }
        }

        cout<<"Optimal train swapping takes "<<c<<" swaps."<<endl;
    }

    return 0;
}
