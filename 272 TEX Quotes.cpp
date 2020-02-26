#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[10000];
    int i,j,c=0;
    while(gets(s))
    {
        for(i=0; i<strlen(s); i++)
        {
            if(s[i]=='"')
            {
                c++;
                if(c&1)
                {
                    int l=i;
                    for(j=strlen(s); j>=l; j--)
                    {
                        s[j+1]=s[j];
                    }
                    s[l]='`';
                    s[l+1]=s[l];
                }
                else
                {
                    int l=i;
                    for(j=strlen(s); j>=l; j--)
                    {
                        s[j+1]=s[j];
                    }
                    s[l]=s[l]-'"'+39;
                    s[l+1]=s[l];
                }
            }
        }

        printf("%s\n",s);
    }


    return 0;
}
