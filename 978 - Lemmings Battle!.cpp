#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,battlefield,SG_size,SB_size,size_min;
    scanf("%d", &n);
    while(n--){
        multiset <int> SG,SB,SG_temp,SB_temp;
        multiset <int>::iterator sg;
        multiset <int>::iterator sb;
        int b,num_sg,num_sb;
        scanf("%d %d %d", &b,&num_sg,&num_sb);
        while(num_sg--){
            scanf("%d", &x);
            SG.insert(x);
        }
        while(num_sb--){
            scanf("%d", &x);
            SB.insert(x);
        }

        while(!SG.empty() && !SB.empty()){
            SG_size = SG.size();
            SB_size = SB.size();
            size_min = min(SG_size,SB_size);
            battlefield = min(b,size_min);
            while(battlefield--){
                sg = SG.end();
                sg--;
                sb = SB.end();
                sb--;
                if(*sg == *sb){
                    SG.erase(sg);
                    SB.erase(sb);
                }
                else if(*sg > *sb){
                    SG_temp.insert(*sg - *sb);
                    SG.erase(sg);
                    SB.erase(sb);
                }
                else if(*sg < *sb){
                    SB_temp.insert(*sb - *sg);
                    SG.erase(sg);
                    SB.erase(sb);
                }
            }
            for(sg = SG_temp.begin(); sg!=SG_temp.end(); sg++)SG.insert(*sg);
            for(sb = SB_temp.begin(); sb!=SB_temp.end(); sb++)SB.insert(*sb);
            SG_temp.clear();
            SB_temp.clear();
        }

        if(SG.empty() && SB.empty()){
            printf("green and blue died\n");
        }
        else if(!SG.empty()){
            printf("green wins\n");
            while(!SG.empty()){
                sg = SG.end();
                sg--;
                cout<<*sg<<"\n";
                SG.erase(sg);
            }
        }
        else if(!SB.empty()){
            printf("blue wins\n");
            while(!SB.empty()){
                sb = SB.end();
                sb--;
                cout<<*sb<<"\n";
                SB.erase(sb);
            }
        }
        SG.clear();
        SB.clear();

        if(n)printf("\n");
    }

    return 0;
}