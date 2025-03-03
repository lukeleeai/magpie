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

	int s=0,f=1;char ch=getchar();

	while(!isdigit(ch) && ch!='-')ch=getchar();

	if(ch=='-')ch=getchar(),f=-1;

	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();

	return ~f?s:-s;

}



const int maxn=420;

const int mod=998244353;

inline int power(int a,int b)

{

	int ans=1;

	while(b)

	{

		if(b&1)ans=(ll)ans*a%mod;

		b>>=1;

		a=(ll)a*a%mod;

	}

	return ans;

}



int jc[maxn],jcn[maxn],inv[maxn];

inline void prepare()

{

	jc[0]=jc[1]=jcn[0]=jcn[1]=inv[1]=1;

	REP(i,2,400)jc[i]=(ll)i*jc[i-1]%mod,inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jcn[i]=(ll)jcn[i-1]*inv[i]%mod;

}



int n,a[maxn],b[maxn],sa,sainv,p[maxn];



inline void init()

{

	n=read();

	REP(i,1,n)a[i]=read(),b[i]=read(),sa+=a[i];

	sainv=power(sa,mod-2);

	REP(i,1,n)p[i]=(ll)a[i]*sainv%mod;

}



int dp[maxn][maxn];



inline void doing()

{

	dp[0][0]=1;

	REP(i,1,n)

	{

		DREP(j,400,0)DREP(k,400,0)if(dp[j][k])

		{

			int t=dp[j][k]; dp[j][k]=0;

			int xs=1;

			dp[j][k+a[i]]=(dp[j][k+a[i]]+t)%mod;

			REP(x,0,b[i]-1)

			{

				dp[j+x][k]=(dp[j+x][k]-(ll)t*xs%mod+mod)%mod;

				xs=(ll)xs*p[i]%mod*inv[x+1]%mod;

			}

		}

	}

	int ans=0;

	REP(j,0,400)REP(k,0,sa-1)if(dp[j][k])

	{

		int v=(ll)k*sainv%mod;

		int c=(mod-dp[j][k])%mod;

		ans=(ans+(ll)c*power(1-v+mod,mod-j-2)%mod*jc[j])%mod;

	}

	printf("%d\n",ans);

}



int main()

{

	prepare();

	init();

	doing();

	return 0;

}
