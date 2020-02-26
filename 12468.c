#include<stdio.h>

int main()

{
    int a,b;

    while(1)
    {
        scanf("%d %d", &a,&b);
        if(a==-1 && b==-1)break;

        if(b>a)
        {
        if(b-a>50)
        {
            printf("%d\n", (100-b)+a);
        }
        else
        {
            printf("%d\n", b-a);
        }
        }
        else
        {
            if(a-b<50)
            {
                printf("%d\n", a-b);
            }
            else
            {
                printf("%d\n", (100-a)+b);
            }
        }
    }
    return 0;
}
