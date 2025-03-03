#include"stdc++.h"

using namespace std;



typedef long long lint;

typedef long double louble;



template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}

template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

template<typename T1,typename T2> inline T1 gmax(T1 &a,T2 b){return a=a<b?b:a;}

template<typename T1,typename T2> inline T1 gmin(T1 &a,T2 b){return a=a<b?a:b;}





namespace ae86

{

	const int bufl = 1<<15;

	

	char buf[bufl],*s=buf,*t=buf;

	

	inline int fetch()

	{

		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}

		return *s++;

	}

	

	inline int ty()

	{

		int a=0,b=1,c=fetch();

		while(!isdigit(c))b^=c=='-',c=fetch();

		while(isdigit(c))a=a*10+c-48,c=fetch();

		return b?a:-a;

	}

}

using ae86::ty;



const int _ = 200007 , __ = _<<1;



vector<int> e[_];

inline void adde(int a,int b){e[a].emplace_back(b);}

inline void addde(int a,int b){adde(a,b),adde(b,a);}



int n,dep[_]={0},mxdep;



void dfs(int x,int ff)

{

	dep[x]=1;

	for(auto b:e[x])

		if(b!=ff)

		{

			dfs(b,x);

			gmax(mxdep,dep[x]+dep[b]);

			gmax(dep[x],dep[b]+1);

		}

	gmax(mxdep,dep[x]);

}



int main()

{

	n=ty();

	for(int i=1,a,b;i<n;i++)a=ty(),b=ty(),addde(a,b);

	mxdep=0,dfs(1,0);

	puts(mxdep%3==2?"Second":"First");



	return 0;

}
