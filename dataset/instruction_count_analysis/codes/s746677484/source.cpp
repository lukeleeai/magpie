#include"stdc++.h"

#define ll long long

using namespace std;

const int N=1e5+5;

map<ll,ll>mp;

ll n,m,x,mi;

int main()

{

	cin>>n>>m;

	cin>>mi;

	for(int i=1;i<n;i++)

	{

		cin>>x;

		mp[x-mi]++;

		mi=min(mi,x);

	}

	ll pnt;

	for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++)pnt=it->second;

	cout<<pnt<<endl;

	return 0;

}