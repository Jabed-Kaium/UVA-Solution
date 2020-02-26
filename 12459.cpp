#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    ll anchestor[100];
    ll i,j,n;

    while(scanf("%lld", &n) && n!=0)
    {
        i=2;
        anchestor[0]=1;
        anchestor[1]=1;
        while(i<=n)
        {
            anchestor[i]=anchestor[i-1]+anchestor[i-2];

            i++;
        }

        cout<<anchestor[n]<<endl;

    }



    return 0;
}
