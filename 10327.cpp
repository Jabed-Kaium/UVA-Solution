#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,j,x,temp;

    while(cin>>n)
    {
        int c=0;
        vector <int> v;
        for(i=0; i<n; i++)
        {
            cin>>x;
            v.push_back(x);
        }

        for(i=0; i<n-1; i++)
        {
            for(j=0; j<n-i-1; j++)
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

        cout<<"Minimum exchange operations : "<<c<<endl;

        v.clear();
    }

    return 0;
}
