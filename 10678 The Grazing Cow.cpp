#include<bits/stdc++.h>
using namespace std;
#define pi 2*acos(0)
int main()
{
	double d,l;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>d>>l;
		double a=l/2;
		double b=sqrt(((l/2)*(l/2))-((d/2)*(d/2)));
		double res = pi*a*b;
		printf("%.3lf\n", res);
	}
	
	return 0;
}
