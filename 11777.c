#include<stdio.h>

int main()

{
    int t,i,j,min,total,avg;
    int t1,t2,f,a,test[3];
    scanf("%d", &t);

    for(i=1; i<=t; i++)
    {
        scanf("%d %d %d %d", &t1,&t2,&f,&a);
        int sum=0;
        for(j=0; j<3; j++)
        {
            scanf("%d", &test[j]);
            sum=sum+test[j];
        }
        int min = test[0];
        for(j=1; j<3; j++)
        {
            if(test[j]<min)min = test[j];
        }
        avg = (sum-min)/2;
        total = t1+t2+f+a+avg;
        if(total>=90)printf("Case %d: A\n",i);
        else if(total>=80)printf("Case %d: B\n",i);
        else if(total>=70)printf("Case %d: C\n",i);
        else if(total>=60)printf("Case %d: D\n",i);
        else printf("Case %d: F\n",i);

    }

    return 0;
}
