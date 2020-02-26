#include<stdio.h>

int main()
{
    int t,i,a,b,c;

    scanf("%d", &t);

    for(i=1; i<=t; i++)
    {
        scanf("%d %d %d", &a,&b,&c);

        if((a>=1000 && a<=10000) && (b>=1000 && b<=10000) && (b>=1000 && b<=10000))
        {

        if((a>b && a<c) || (a>c && a<b))
        {
            printf("Case %d: %d\n", t,a);
        }
        else if((b>c && b<a) || (b>a && b<c))
        {
            printf("Case %d: %d\n", t,b);
        }
        else if((c>a && c<b) || (c>b && c<a))
        {
            printf("Case %d: %d\n", t,c);
        }
        }
    }

    return 0;
}
