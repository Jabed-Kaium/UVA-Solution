#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int n,x;

    cin>>n;

    for(x=1; x<=n; x++)
    {
        int M=0,A=0,R=0,G=0,I=0,T=0,y,z;
        char s[601];

        cin>>s;

        for(y=0; y<strlen(s); y++)
        {
            if(s[y]=='M')M++;
            else if(s[y]=='A')A++;
            else if(s[y]=='R')R++;
            else if(s[y]=='G')G++;
            else if(s[y]=='I')I++;
            else if(s[y]=='T')T++;
        }

        for(z=0; z>=0; z++)
        {
            if(M<1 || A<3 || R<2 || G<1 || I<1 || T<1)break;

            M=M-1;
            A=A-3;
            R=R-2;
            G=G-1;
            I=I-1;
            T=T-1;
        }

        cout<<z<<endl;
    }


    return 0;
}
