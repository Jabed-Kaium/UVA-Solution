#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,x;
    int count,i;
    while(1)
    {
        count=0;
        scanf("%lf %lf", &a,&b);
        if(a==0 && b==0)
        {
            break;
        }
        for(i=a; i<=b; i++)
        {
            x = sqrt(i);
            if(ceil(x)==floor(x))
            {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
