#include<stdio.h>

int main()

{
    int m,n,sum,i;

    while(scanf("%d %d", &m,&n)!=EOF)
    {
        sum = m-1;
        for(i=1; i<=m; i++)
        {
            sum = sum + (n-1);
        }

        printf("%d\n", sum);
    }

    return 0;
}
