//dfs版 

#include<iostream>

#include<cctype>

#include<queue>

#include<cstdio>

#include<cmath>

#include<sstream>

#include<string>

#include<algorithm>

#include<cstring>

#include<vector>

#include<ctime>

#include<cstdlib>

#include<map>

#include<utility>

#include<iomanip>

#include<set>

#include<stack>

#define lowbit(i) ((i)&(-i))

using namespace std;

typedef long long ll;typedef pair<int,int> pii;

typedef pair<ll,ll> pll;typedef vector<string> vss;

typedef vector<int> vii;typedef vector<pii> vpi;

typedef vector<ll> vll;typedef vector<pll> vpl;typedef long double ld;

typedef unsigned long long ul;typedef queue<int> qii;typedef queue<pii> qpi;

int n,x,y,dp[100005],res,t;

vii v[100005];

int mx=0,deg[1000005];

qii q;

int main()

{

// 	freopen("","r",stdin);

// 	freopen("","w",stdout);

	cin>>n;

	for(int i=1;i<n;i++){

		cin>>x>>y;

		v[x].push_back(y);

		v[y].push_back(x);

		deg[x]++;

		deg[y]++;

	}

	for(int i=0;i<n;i++){

		if(v[i].size()>mx)

			mx=v[i].size();

	}

	if(mx<=2){

		puts("1");

		return 0;

	}

	for(int i=0;i<n;i++){

		if(deg[i]==1) q.push(i);

	}

	while(!q.empty()){

		int p=q.front(),to=-1;q.pop();

		for(int i=0;i<v[p].size();i++){

			to=v[p][i];

			if(deg[to]!=1) break;

		}

		if(deg[to]==2){

			deg[to]=1;

			q.push(to);

		}

	}

	for(int i=0;i<n;i++){

		if(deg[i]==1) continue;

		t=0;

		for(int j=0;j<v[i].size();j++){

			int to=v[i][j];

			if(deg[to]==1) t++;

		}

		res+=max(0,t-1);

	}

	cout<<res<<'\n';

	return 0;

}