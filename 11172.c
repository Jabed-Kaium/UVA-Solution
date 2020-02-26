#include<stdio.h>

int main()

{
    int t;
    long int a,b;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%ld %ld", &a,&b);

        if(a>b)printf(">\n");
        else if(a<b)printf("<\n");
        else if(a==b)printf("=\n");
    }

    return 0;
}
