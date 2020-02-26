#include<stdio.h>
#include<math.h>

int main()

{
    int t,i;
    double total,f,c,d,final_celcius;

    scanf("%d", &t);

    for(i=1; i<=t; i++)
    {
        scanf("%lf %lf", &c,&d);
        f =((9*c)/5)+32;
        total = (f+d);
        final_celcius = ((total-32)*5)/9;

        printf("Case %d: %0.2lf\n", i,final_celcius);
    }

    return 0;
}
