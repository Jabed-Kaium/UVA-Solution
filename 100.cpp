#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j;

    while(scanf("%d %d", &i,&j)!=EOF && i>0 && j>0)
    {
        int temp_i=i;
        int temp_j=j;

        if(i>j)swap(i,j);

        int temp=i,cycle_max=0;

        while(temp<=j)
        {
            int cycle_length=1,n=temp;
            while(n!=1)
            {
                if(n%2==0)
                {
                    n = n/2;
                }
                else
                {
                    n = 3*n+1;
                }
                cycle_length++;
            }
            if(cycle_length>cycle_max)
                cycle_max=cycle_length;
            temp++;
        }

        cout<<temp_i<<" "<<temp_j<<" "<<cycle_max<<endl;
    }

    return 0;
}
