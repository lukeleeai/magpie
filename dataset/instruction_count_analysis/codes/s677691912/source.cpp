#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int mod=998244353,lim=512;

inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}

inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}

inline int kpow(int a,int b)

{

	int s=1;

	for(;b;b>>=1,a=1ll*a*a%mod)

		if(b&1)s=1ll*s*a%mod;

	return s;

}

int n,a[410],b[410],jc[512],jcv[512],S,Sv,ans;

int dp[2][410][512],r[512],w[9][256],A[512];

void init()

{

	jc[0]=1;

	for(int i=1;i<lim;++i)jc[i]=1ll*jc[i-1]*i%mod;

	jcv[lim-1]=kpow(jc[lim-1],mod-2);

	for(int i=lim-1;i;--i)jcv[i-1]=1ll*jcv[i]*i%mod;

	for(int i=1;i<lim;++i)r[i]=(r[i>>1]>>1)|(i&1?lim>>1:0);

	for(int len=1,i=0;len<lim;len<<=1,++i)

	{

		int tmp=kpow(3,(mod-1)/len/2);

		w[i][0]=1;

		for(int j=1;j<len;++j)w[i][j]=1ll*w[i][j-1]*tmp%mod;

	}

}

void ntt(int f[],int opt)

{

	for(int i=1;i<lim;++i)if(i<r[i])swap(f[i],f[r[i]]);

	int x,y;

	for(int len=1,i=0;len<lim;len<<=1,++i)

		for(int j=0;j<lim;j+=len<<1)

			for(int k=0;k<len;++k)

			{

				x=f[j+k],y=1ll*f[j+k+len]*w[i][k]%mod;

				f[j+k]=pl(x,y),f[j+k+len]=pl(x,mod-y);

			}

	if(opt==-1)

	{

		reverse(f+1,f+lim);

		int inv=kpow(lim,mod-2);

		for(int i=0;i<lim;++i)f[i]=1ll*f[i]*inv%mod;

	}

}

int main()

{

//	printf("%d %d",5ll*kpow(72,mod-2)%mod,kpow(216,mod-2));

	scanf("%d",&n);

	init();

	for(int i=1;i<=n;++i)scanf("%d %d",&a[i],&b[i]),S+=a[i];

	for(int i=0;i<lim;++i)dp[0][0][i]=1;

	Sv=kpow(S,mod-2);

	int t=0;

	for(int i=1;i<=n;++i)

	{

		memset(A,0,sizeof(A));

		int tmp=1ll*a[i]*Sv%mod,cur=1;

		for(int j=0;j<b[i];++j)

		{

			A[j]=1ll*(mod-cur)*jcv[j]%mod;

			cur=1ll*cur*tmp%mod;

		}

		ntt(A,1);

		t^=1;memset(dp[t],0,sizeof(dp[t]));

		for(int j=0;j<S;++j)

		{

			for(int k=0;k<lim;++k)dp[t][j][k]=1ll*A[k]*dp[t^1][j][k]%mod;

			if(j>=a[i])for(int k=0;k<lim;++k)add(dp[t][j][k],dp[t^1][j-a[i]][k]);

		}

	}

	for(int i=0;i<S;++i)

	{

		ntt(dp[t][i],-1);

	//	for(int j=0;j<10;++j)printf("%9d ",dp[t][i][j]);printf("\n");

		int na=1ll*i*Sv%mod,tmp=kpow(mod+1-na,mod-2),w=tmp;

		for(int j=0;j<lim;++j)ans=(ans+1ll*dp[t][i][j]*w%mod*jc[j])%mod,w=1ll*w*tmp%mod;

	}

	if(ans)ans=mod-ans;

	printf("%d",ans);

	return 0;

}
