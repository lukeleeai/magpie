#include"stdc++.h"

using namespace std;

#define ll long long

vector<int>sc[27];

int main(){

	string s,t;

	cin>>s>>t;

	for(int i=0;i<s.size();i++){

		sc[s[i]-'a'].push_back(i);

	}

	int np = -1;

	ll ans = 0;

	for(int i=0;i<t.size();){

		if(sc[t[i]-'a'].size()==0)return 0*printf("-1\n");

		int pos = upper_bound(sc[t[i]-'a'].begin(),sc[t[i]-'a'].end(),np)-sc[t[i]-'a'].begin();

		if(pos==sc[t[i]-'a'].size()){

			np=-1;

			ans=ans+s.size();

		}

		else np=sc[t[i]-'a'][pos],i++;

	}

	printf("%lld\n",ans+np+1);

}