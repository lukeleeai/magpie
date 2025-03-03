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

vector <int> vec[2000+2000*8+5];

int visit[2000+2000*8+5];

int colors;

map <int,int> toid;

bool isprime[10005];

vector <int> prime;

bool block[2000+2000*8+5];

bool e[2005][2005];

int tot;



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



pii dfs(int x,int col,int head)

{

//	cout<<x<<' '<<col<<' '<<head<<endl;

	visit[x]=col;

	pii res={inf,-1};

	if(x<n && (head==-1 || e[head][x])) res={a[x],x};

	for(auto u:vec[x])

	{

		if(block[u]) continue;

		if(visit[u]>=col) continue;

		chmin(res,dfs(u,col,head));

	}

	return res;

}



vector <int> solve(int x)

{

	assert(x<n);

	block[x]=true;

	colors++;

	visit[x]=colors;

	vector <int> res;

	res.push_back(a[x]);

	vector <int> adj;

	for(auto &u:vec[x])

	{

		adj.push_back(u);

	}

	for(auto &u:adj)

	{

		if(visit[u]>=colors) continue;

		if(block[u]) continue;

		int minx=dfs(u,colors,x).second;

		if(minx==-1) continue;

		res=merge(res,solve(minx));

	}

	colors--;

	return res;

}



void init()

{

	memset(isprime,true,sizeof(isprime));

	isprime[0]=isprime[1]=false;

	for(int i=2;i<=10000;i++)

	{

		if(isprime[i]) prime.push_back(i);

		for(auto &j:prime)

		{

			if(i*j>10000) break;

			isprime[i*j]=false;

			if(i%j==0) break;

		}

	}

}



void add_edge(int x,int p)

{

	if(toid.find(p)==toid.end()) toid[p]=tot++;

	int y=toid[p];

	vec[x].push_back(y);

	vec[y].push_back(x);

}



void build_graph()

{

	int tn;

	for(int i=0;i<n;i++)

	{

		tn=a[i];

		for(auto &p:prime)

		{

			if(tn%p==0) add_edge(i,p);

			while(tn%p==0) tn/=p;

		}

		if(tn!=1) add_edge(i,tn);

	}

	for(int i=0;i<n;i++)

	{

		for(int j=0;j<n;j++)

		{

			if(i==j) continue;

			if(__gcd(a[i],a[j])!=1) e[i][j]=true;

		}

	}

}



void gogo()

{

	colors++;

	vector <int> res;

	res.push_back(0);

	vector <int> adj;

	for(int i=0;i<n;i++)

	{

		adj.push_back(i);

	}

	for(auto &u:adj)

	{

		if(visit[u]>=colors) continue;

		if(block[u]) continue;

		int minx=dfs(u,colors,-1).second;

		if(minx==-1) continue;

		vector <int> temp=solve(minx);

//		cout<<temp<<endl;

		res=merge(res,temp);

	}

	colors--;

	for(int i=1;i<res.size();i++)

	{

		cout<<res[i]<<' ';

	}

	cout<<endl;

}



void print_graph()

{

	cout<<"--------Graph is below--------"<<endl;

	for(int i=0;i<tot;i++)

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

	init();

	cin>>n;

	tot=n;

	for(int i=0;i<n;i++)

	{

		cin>>a[i];

	}

	build_graph();

//	print_graph();

	gogo();

	return 0;

}