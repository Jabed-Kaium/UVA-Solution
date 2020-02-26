#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void printstring(string s)
{
	vector <string> v;
	vector <string>::iterator it;

	string word;

	stringstream iss(s);

	while(iss>>word){
		ll len = word.length();
		for(ll i=0,j=len-1; i<j; i++,j--){
			swap(word[i],word[j]);
		}
		v.push_back(word);
	}
	for(it=v.begin(); it!=v.end(); it++){
		if(it==(v.end()-1)){
			cout<<*it;
		}
		else{
			cout<<*it<<" ";
		}
	}
	v.clear();
	cout<<endl;

}

int main()
{
	string s;
	while(getline(cin,s)){
		printstring(s);

	}

	return 0;
}
