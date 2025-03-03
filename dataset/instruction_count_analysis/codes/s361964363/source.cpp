#include "stdc++.h"

using namespace std;

int n,ans,s;

map<int,int> m;

vector<int> v;

int main()

{

	cin>>n;

	for(int i=0;i<n;i++) {

		cin>>s;

		if(m[s]==0) v.push_back(s);

		m[s]++;

	}

	for(int i=0;i<v.size();i++) 

		if(m[v[i]]>=v[i]) ans+=m[v[i]]-v[i];

		else ans+=m[v[i]];

	cout<<ans<<endl;

	return 0;

}