#include"stdc++.h"

using namespace std;



typedef long long lint;

typedef long double louble;



template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}

template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}



const char lf = '\n';



namespace ae86

{

	const int bufl = 1 << 15;



	char buf[bufl],*s=buf,*t=buf;



	inline int fetch()

	{

		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}

		return *s++;

	}



	inline int ty()

	{

		int a=0;int b=1,c=fetch();

		while(!isdigit(c))b^=c=='-',c=fetch();

		while(isdigit(c))a=a*10+c-48,c=fetch();

		return b?a:-a;

	}

}

using ae86::ty;



const int _ = 200007 , mo = 998244353;



template<typename T1,typename T2> inline T1 ad(T1 &a,T2 b){return a=a+b>=mo?a+b-mo:a+b;}

template<typename T1,typename T2> inline T1 dl(T1 &a,T2 b){return a=a>=b?a-b:a-b+mo;}

template<typename T1,typename T2> inline T1 add(T1 a,T2 b){return a+b>=mo?a+b-mo:a+b;}

template<typename T1,typename T2> inline T1 del(T1 a,T2 b){return a>=b?a-b:a-b+mo;}



lint powa(lint a,lint t)

{

	lint b=1;a=(a+mo)%mo;

	while(t){if(t&1)b=b*a%mo;a=a*a%mo,t>>=1;}

	return b;

}



inline lint inva(lint a)

{

	return powa(a,mo-2);

}



vector<int> e[_];



int n,fa[_]={0},rt=0,mxdep=0;



void dfs(int x,int ff,int dep)

{

	fa[x]=ff;

	if(dep>mxdep)mxdep=dep,rt=x;

	for(auto b:e[x])if(b!=ff)dfs(b,x,dep+1);

}



int ps[_]={0},lps=0;

lint f[_][3][3]={0};



void dfs2(int x,int ff,int dep)

{

	fa[x]=ff;

	memset(f[x],0,sizeof(f[x]));

	if(dep==lps/2)f[x][1][1]=1;

	else f[x][0][0]=1;



	for(auto b:e[x])

	{

		if(b==ff)continue;

		dfs2(b,x,dep+1);

		lint sf[3][3];memset(sf,0,sizeof(sf));

		for(int i=0;i<3;i++)

			for(int j=0;j<3;j++)

				for(int p=0;p<3;p++)

					for(int q=0;q<3;q++)

						for(int r=-1;r<=1;r++)

						{

							int pp=r==1?p:0,qq=r==-1?q:0;

							pp=min(2,pp+i),qq=min(2,qq+j);

							ad(sf[pp][qq],f[x][i][j]*f[b][p][q]%mo);

						}

		memcpy(f[x],sf,sizeof(sf));

	}

}



int main()

{

	ios::sync_with_stdio(0),cout.tie(nullptr);



	n=ty();

	for(int i=1,a,b;i<n;i++)a=ty(),b=ty(),e[a].emplace_back(b),e[b].emplace_back(a);



	dfs(1,0,1),mxdep=0,dfs(rt,0,1);

	for(int i=rt;i;i=fa[i])ps[++lps]=i;



	if(lps&1)

	{

		int mid=ps[lps/2+1];

		dfs2(mid,0,0);

		cout<<f[mid][1][1]*inva(2)%mo<<lf;

		return 0;

	}

	

	int ll=ps[lps/2],rr=ps[lps/2+1];

	dfs2(ll,rr,1),dfs2(rr,ll,1);

	cout<<add(add(f[ll][1][0],f[ll][1][1]),f[ll][1][2])

		*add(add(f[rr][0][1],f[rr][1][1]),f[rr][2][1])%mo<<lf;



	return 0;

}
