#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ll long long

int arr[20];
int check[20];
set < stack<int> > s;
int sum,n;

void printSet(){

    if(s.size() == 0){
        printf("NONE\n");
        return;
    }

    stack <int> ans;
    vector <int> v;
    set <stack<int> >::iterator it;
    it = s.end();
    it--;

    for( ; it!=s.begin(); it--){
        v.clear();
        ans = *it;
        while(!ans.empty()){
            v.pb(ans.top());
            ans.pop();
        }

        for(int i=v.size()-1; i>=0; i--){
            if(i == v.size()-1)printf("%d", v[i]);
            else printf("+%d", v[i]);
        }
        printf("\n");
    }
    v.clear();

    ans = *it;
    while(!ans.empty()){
        v.pb(ans.top());
        ans.pop();
    }

    for(int i=v.size()-1; i>=0; i--){
        if(i == v.size()-1)printf("%d", v[i]);
        else printf("+%d", v[i]);
    }
    printf("\n");
}

void solve(stack<int> q,int total,int i){
    if(total == sum){
        s.insert(q);    //if total of the arrangement == sum,add the arrangement to answer
        return;
    }

    //checking all possible arrangements
    for(int j=0; j<n; j++){
        if(check[j] == 0 && i<=j && total+arr[j] <= sum){
            check[j] = 1;
            q.push(arr[j]);

            solve(q,total+arr[j],j);    //recursively add element to total
            
            check[j] = 0;
            q.pop();
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(scanf("%d %d", &sum,&n)){
        if(sum == 0 && n == 0)break;

        stack<int> q;

        memset(check,0,sizeof(check));

        s.clear();

        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }

        printf("Sums of %d:\n", sum);
        solve(q,0,0);

        printSet();
    }

    return 0;
}