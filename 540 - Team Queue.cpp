#include<iostream>
#include<map>
#include<queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string s;
    int cases=1;
    int hash[1005];

    while(cin>>t){
        map<int,int>mp;
        queue<int>q[1005];
        queue<int>q2;
        if(t==0)break;  

        for(int i=1; i<=t; i++){
            int n;
            cin>>n;
            while(n--){
                int x;
                cin>>x;
                mp[x]=i; //mapping the element to which team it belongs
            }
            hash[i]=0; //for hashing teams
        }

        cout<<"Scenario #"<<cases++<<"\n";

        while(cin>>s){
            if(s=="STOP"){
                cout<<"\n";
                break;
            }
            else if(s=="ENQUEUE"){
                int num;
                cin>>num;
                q[mp[num]].push(num);  //push element in the end of the same team
                if(hash[mp[num]]==0){  //check if the team exist in the queue
                    q2.push(mp[num]);  //if not exist,push the team in the queue
                    hash[mp[num]]=1;
                }
            }
            else if(s=="DEQUEUE"){
                if(!q2.empty()){
                cout<<q[q2.front()].front()<<"\n"; //iterate the first element of the first team
                q[q2.front()].pop(); //remove the element from the team
                if(q[q2.front()].empty()){ //if all the elements from the team dequeued,remove the team from the queue
                    hash[q2.front()]=0; //that team is presently not in the queue
                    q2.pop();
                }
                }
            }
        }
    }

    return 0;
}