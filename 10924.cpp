#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[22];

    while(scanf("%s", &str)!=EOF)
    {
        int len = strlen(str);
        int sum=0,c1=0;

        for(int i=0; i<len; i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                sum += str[i]-96;
            }
            else
            {
                sum += str[i]-38;
            }
        }

        int sq = sqrt(sum);

        for(int i=2; i<=sq; i++)
        {
            if(sum%i==0)
            {
                ++c1;
                cout<<"It is not a prime word."<<endl;
                break;
            }
        }
        if(c1==0)
        {
            cout<<"It is a prime word."<<endl;
        }
    }


    return 0;
}
