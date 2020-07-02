#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ll long long

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    set <int> s;
    bool taken[61][61][61];

    s.insert(50);
    for(int i=0; i<=20; i++){
        s.insert(i);
        s.insert(i*2);
        s.insert(i*3);
    }

    vector <int> v(s.begin(), s.end()); //copying elements from set s

    int n;

    while(cin>>n){
        if(n <= 0){
            printf("END OF OUTPUT\n");
            break;
        }

        memset(taken,false,sizeof(taken));

        int permutations = 0, combinations = 0;
        
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
                for(int k=0; k<v.size(); k++){
                    if(v[i]+v[j]+v[k] != n)continue;

                    permutations++;

                    if(!taken[v[i]][v[j]][v[k]]){

                         combinations++;

                         taken[v[i]][v[j]][v[k]]=true;
                         taken[v[i]][v[k]][v[j]]=true;
                         taken[v[k]][v[i]][v[j]]=true;
                         taken[v[k]][v[j]][v[i]]=true;
                         taken[v[j]][v[i]][v[k]]=true;
                         taken[v[j]][v[k]][v[i]]=true;
                    }
                }
            }
        }

        if(permutations == 0 && combinations ==0){
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
            printf("**********************************************************************\n");
        }
        else{
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n,combinations);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n,permutations);
            printf("**********************************************************************\n");
        }
    }

    return 0;
}