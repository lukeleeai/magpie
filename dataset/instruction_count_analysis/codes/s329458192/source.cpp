#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int mod=998244353;

inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}

inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}

inline int kpow(int a,int b)

{

	int s=1;

	for(;b;b>>=1,a=1ll*a*a%mod)

		if(b&1)s=1ll*s*a%mod;

	return s;

}

int n,a[410],b[410],jc[410],jcv[410],Sa,Sb,Sv,ans;

int dp[410][410],A[410];

void init()

{

	jc[0]=1;

	for(int i=1;i<=400;++i)jc[i]=1ll*jc[i-1]*i%mod;

	jcv[400]=kpow(jc[400],mod-2);

	for(int i=400;i;--i)jcv[i-1]=1ll*jcv[i]*i%mod;

}

int main()

{

	scanf("%d",&n);

	init();

	for(int i=1;i<=n;++i)scanf("%d %d",&a[i],&b[i]),Sa+=a[i];

	Sv=kpow(Sa,mod-2);

	dp[0][0]=1;

	for(int i=1;i<=n;++i)

	{

		int tmp=1ll*a[i]*Sv%mod,cur=1;

		for(int j=0;j<b[i];++j)

		{

			A[j]=1ll*(mod-cur)*jcv[j]%mod;

			cur=1ll*cur*tmp%mod;

		}

		for(int j=Sa-1;~j;--j)

			for(int k=Sb;~k;--k)

			{

				for(int l=1;l<b[i];++l)dp[j][k+l]=(dp[j][k+l]+1ll*dp[j][k]*A[l])%mod;

				dp[j][k]=mod-dp[j][k];

				if(j>=a[i])add(dp[j][k],dp[j-a[i]][k]);

			}

		Sb+=b[i]-1;

	}

	for(int i=0;i<Sa;++i)

	{

	//	for(int j=0;j<5;++j)printf("%9d ",dp[i][j]);printf("\n");

		int na=1ll*i*Sv%mod,tmp=kpow(mod+1-na,mod-2),w=tmp;

		for(int j=0;j<=Sb;++j)ans=(ans+1ll*dp[i][j]*w%mod*jc[j])%mod,w=1ll*w*tmp%mod;

	}

	if(ans)ans=mod-ans;

	printf("%d",ans);

	return 0;

}
