#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[1000];
    long long sum;
    int i;

    while(1){
        cin>>s;
        if(strlen(s)==1 && s[0]=='0')break;
        int l = strlen(s);
        sum=0,i=1;
        for(int j=l-1; j>=0; j--){
            if(s[j]!='0'){
                sum += (s[j]-48)*(pow(2,i)-1);
            }
            i++;
        }
        if(sum<2147483648)cout<<sum<<endl;
    }

    return 0;
}
