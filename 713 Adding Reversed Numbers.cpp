#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        char a[202],b[202],c[202],d[202],r[210],rev[210];
        int i,j,carry=0,l1,l2,s,k;
        scanf("%s", &a);
        scanf("%s", &b);
        l1 = strlen(a);
        l2 = strlen(b);
        for(i=l1-1,j=0; i>=0; i--,j++)
        {
            c[j]=a[i];
        }
        for(i=l2-1,j=0; i>=0; i--,j++)
        {
            d[j]=b[i];
        }
        i = l1-1;
        j = l2-1;
        if(l1>l2) k=l1;
        else k=l2;
        r[k] = '\0';
        k--;

        while(i>=0 && j>=0)
        {
            s = (c[i]-48)+(d[j]-48)+carry;
            r[k] = s%10 + 48;
            carry = s/10;
            i--;
            j--;
            k--;
        }

        if(i>=0)
        {
            while(i>=0)
            {
                s = (c[i]-48)+carry;
                r[k] = s%10 + 48;
                carry = s/10;
                i--;
                k--;
            }
        }
        else if(j>=0)
        {
            while(j>=0)
            {
                s = (d[j]-48)+carry;
                r[k] = s%10 + 48;
                carry = s/10;
                j--;
                k--;
            }
        }

        if(carry>0)
        {
            int len = strlen(r);
            for(i=len; i>=0; i--)
            {
                r[i+1] = r[i];
            }
            r[0] = carry+48;
        }

        int len1 = strlen(r);

        for(i=len1-1,j=0; i>=0; i--,j++)
        {
            rev[j]=r[i];
        }

        for(i=0; i<len1; i++)
        {
            if(rev[i]>='1' && rev[i]<='9')
            {
                int index = i;
                break;
            }
        }

        for(j=i; j<len1; j++)
        {
            printf("%c",rev[j]);
        }
        cout<<endl;
    }

    return 0;
}
