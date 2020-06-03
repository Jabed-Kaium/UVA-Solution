#include<bits/stdc++.h>
using namespace std;

int main()
{
    int froshNum;

    while(scanf("%d", &froshNum)){
        if(froshNum==0)break;
        map <set<int>, int> popularCourse;
        map <set<int>, int>::iterator it;
        set <int> courses;
        int courseCode,max=0;
        while(froshNum--){
            for(int i=0; i<5; i++){
                scanf("%d", &courseCode);
                courses.insert(courseCode);
            }
            
            popularCourse[courses]++;
            it = popularCourse.find(courses);
            if((it->second) > max)
                max = (it->second);
            
            courses.clear();
        }
        int total = 0;
        for(it=popularCourse.begin(); it!=popularCourse.end(); it++){
            if((it->second)==max)total+=max;
        }
        cout<<total<<"\n";
        popularCourse.clear();
    }

    return 0;
}