#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> v;
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n,x;
        cin>>n;
        for(int j=1; j<=n; j++)
        {
            cin>>x;
            v.push_back(x);
        }
        int maximum = v[0];
        for(int i=1; i<v.size(); i++)
        {
            if(v[i]>maximum)
            {
                maximum = v[i];
            }
        }
        cout<<"Case "<<i<<": "<<maximum<<endl;

        v.clear();
    }

    return 0;
}
