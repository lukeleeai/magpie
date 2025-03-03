#include <iostream>

#include <algorithm>

#include <cmath>

#include <stdio.h>

#include <stdlib.h>

#include <vector>

#include <map>

//#include <self/operator>

#include <queue>

#include <set>

#include <string>

#include <string.h>

#include <stack>

#include <assert.h>

#include <bitset>

#define Endl endl

#define mp make_pair

#define ll long long 

#define ull unsigned long long

#define pii pair<int,int>

#define pll pair<ll,ll>

#define over(A) {cout<<A<<endl;exit(0);}

#define all(A) A.begin(),A.end()

#define ceil(a,b) ((a-1)/b+1)

#define quickcin ios_base::sync_with_stdio(false);

const int mod=1e9+7;

const int inf=1039074182;

const ll llinf=1LL*inf*inf;

using namespace std;

template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}

template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}

template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}

template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}

template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}

int n;

int a[2005];

vector <int> vec[2005];

bool block[2005];



inline vector <int> merge(vector <int> a,vector <int> b)

{

	vector <int> res;

	int la=(int)a.size();

	int lb=(int)b.size();

	res.push_back(a[0]);

	for(int i=1,j=0;;)

	{

		if(i==la && j==lb) break;

		if(i==la) res.push_back(b[j++]);

		else if(j==lb) res.push_back(a[i++]);

		else if(a[i]>b[j]) res.push_back(a[i++]);

		else res.push_back(b[j++]);

	}

	return res;

}



//#include <self/operator>

vector <int> dfs(int x)

{

	vector <int> res;

	res.push_back(a[x]);

	block[x]=true;

	for(auto &u:vec[x])

	{

		if(block[u]) continue;

		res=merge(res,dfs(u));

	}

	return res;

}



bool compare(int x,int y)

{

	return a[x]<a[y];

}



void build_graph()

{

	a[n]=0;

	for(int i=0;i<n;i++)

	{

		for(int j=0;j<n;j++)

		{

			if(i==j) continue;

			if(__gcd(a[i],a[j])!=1) vec[i].push_back(j);

		}

	}

	for(int i=0;i<n;i++)

	{

		vec[i].push_back(n);

		vec[n].push_back(i);

	}

	for(int i=0;i<=n;i++)

	{

		sort(all(vec[i]),compare);

	}

}



void print_graph()

{

	cout<<"--------Graph is below--------"<<endl;

	for(int i=0;i<n;i++)

	{

		for(int &j:vec[i])

		{

			cout<<i<<' '<<j<<endl;

		}

	}

	cout<<"--------Graph is above--------"<<endl;

}



int main()

{

//	freopen("input.txt","r",stdin);

	cin>>n;

	for(int i=0;i<n;i++)

	{

		cin>>a[i];

	}

	build_graph();

	for(auto &x:dfs(n))

	{

		if(x==0) continue;

		cout<<x<<' ';

	}

	cout<<endl;

	return 0;

}