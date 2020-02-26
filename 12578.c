#include<stdio.h>
#include<math.h>

int main()

{
    double l,area_green,area_red,w,r;
    double pi = acos(-1);
    int t;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%lf", &l);

        w = (l/10)*6;
        r = (l/10)*2;

        area_red = pi*(r*r);
        area_green = (l*w)-area_red;

        printf("%.2lf %.2lf\n", area_red,area_green);
    }

    return 0;
}
