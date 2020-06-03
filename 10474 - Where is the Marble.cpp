#include<iostream>
#include<map>
#include<set>
#include<cstdio>

using namespace std;

int  main()
{
    int marbelNum,query;
    multimap <int,int> sequence;
    multiset<int> marbels;

    int cases = 0;

    while(scanf("%d %d", &marbelNum,&query)!=EOF){
        if(marbelNum==0 && query==0)break;
        ++cases;
        while(marbelNum--){
            int x;
            scanf("%d", &x);
            marbels.insert(x);
        }
        int indx=0;
        for(multiset<int>::iterator it = marbels.begin(); it!=marbels.end(); it++){
            sequence.insert(make_pair(*it,++indx));
        }

        printf("CASE# %d:\n", cases);
        for(int i=1; i<=query; i++){
            int value;
            scanf("%d", &value);
            multimap<int,int >::iterator it;
            it = sequence.find(value);

            if(it!=sequence.end()){
                printf("%d found at %d\n", it->first,it->second);
            }
            else{
                printf("%d not found\n", value);
            }
        }

        sequence.clear();
        marbels.clear();
    }

    return 0;
}