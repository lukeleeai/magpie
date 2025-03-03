#include"stdc++.h"

using namespace std;

#define ll long long

#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)

#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)

#define EREP(i,u) for(int i=start[u];i;i=e[i].next)

#define fi first

#define se second

#define mkr(a,b) make_pair(a,b)

#define SZ(A) ((int)A.size())

template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}

template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}

inline int read()

{

	int s=0,f=1; char ch=getchar();

	while(!isdigit(ch) && ch!='-')ch=getchar();

	if(ch=='-')ch=getchar(),f=-1;

	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();

	return ~f?s:-s;

}



const int maxn=5e3+20;



int n,mod;

int dp[maxn];



inline void init()

{

	n=read();mod=read();

}



inline void pls(int &a,int b){ a+=b; a-=a>=mod?mod:0;}



int f[maxn][maxn];



inline void doing()

{

	int len=n-1>>1;

	dp[0]=1;

	REP(i,1,len+(~n&1))

	{

		int w=i;

		for(int j=w;j<=n;j++)

			pls(dp[j],dp[j-w]);

	}

	f[0][0]=1;

	REP(i,1,n)

	{

		REP(j,0,n)f[i][j]=f[i-1][j];

		REP(j,i,n)pls(f[i][j],f[i][j-i]);

	}

	DREP(i,n,1)

	{

		int s=0;

		REP(j,0,n)

		{

			pls(s,f[i-1][j]);

			int nj=j+len+1;

			if(nj<=n)pls(f[i][nj],mod-s);

		}

	}

	int ans=0;

	REP(x,1,n)

	{

		int a=x-1,mx=n-x;

		int suf=0;

		DREP(j,a,0)

		{

			suf=(suf+dp[a-j])%mod;

			ans=(ans+(ll)suf*f[mx][j])%mod;

		}

	}

	printf("%d\n",ans);

}



int main()

{

	init();

	doing();

	return 0;

}
