#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
  double s,a,r=6440,arc_dis,chord_dis,b;
  string str;
  while(cin>>s>>a>>str){
    if(str[0]=='d'){
      if(a>180)a=360-a;
      a = a*(pi/180);
    }
    else if(str[0]=='m'){
      a=a/60;
      if(a>180)a=360-a;
      a = a*(pi/180);
    }

    double length = r+s;

    arc_dis = 2*pi*length*((a*(180/pi))/360);

    b = a/2;

    chord_dis = 2*(length*sin(b));

    printf("%.6lf %.6lf\n", abs(arc_dis),abs(chord_dis));

  }

  return 0;

}
