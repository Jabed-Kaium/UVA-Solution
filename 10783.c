#include<stdio.h>

int main()

{
    int t,a,b,i,j,sum=0;

    scanf("%d", &t);

    for(i=1; i<=t; i++)
    {
        scanf("%d %d", &a,&b);
        for(j=a; j<=b; j++)
        {
            if(j%2!=0)
            {
                sum = sum+j;
            }
        }

        printf("Case %d: %d\n", i,sum);
        sum=0;
    }

    return 0;
}
