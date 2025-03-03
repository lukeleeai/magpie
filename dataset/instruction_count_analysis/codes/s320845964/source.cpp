#include<cstdio>

using namespace std;

#define N 16400

#define M 204

#define mod 998244353

int dp[M][N],n,m,fr[N],ifr[N],rev[N],a[N],b[N],ntt[N];

int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}

int c(int a,int b){if(a<b)return 0;return 1ll*fr[a]*ifr[b]%mod*ifr[a-b]%mod;}

void dft(int s,int *a,int t)

{

	for(int i=0;i<s;i++)rev[i]=(rev[i>>1]>>1)|(i&1?s>>1:0),ntt[rev[i]]=a[i];

	for(int i=2;i<=s;i<<=1)

	{

		int st=pw(3,(mod-1)/i);

		if(t==-1)st=pw(st,mod-2);

		for(int j=0;j<s;j+=i)

		for(int k=j,t=1;k<j+(i>>1);k++,t=1ll*t*st%mod)

		{

			int v1=ntt[k],v2=1ll*ntt[k+(i>>1)]*t%mod;

			ntt[k]=(v1+v2)%mod;ntt[k+(i>>1)]=(v1-v2+mod)%mod;

		}

	}

	int inv=t==-1?pw(s,mod-2):1;

	for(int i=0;i<s;i++)a[i]=1ll*ntt[i]*inv%mod;

}

int main()

{

	scanf("%d%d",&n,&m);

	dp[0][0]=1;

	fr[0]=ifr[0]=1;for(int i=1;i<=8020;i++)fr[i]=1ll*fr[i-1]*i%mod,ifr[i]=pw(fr[i],mod-2);

	for(int i=1;i<=m;i++)

	{

		int l=1;while(l<=n*2)l<<=1;for(int j=0;j<l;j++)a[j]=b[j]=0;

		for(int j=0;j<=n;j++)a[j]=1ll*dp[i-1][j]*ifr[j]%mod;

		for(int j=1;j<=n;j++)b[j]=ifr[j+2];

		dft(l,a,1);dft(l,b,1);for(int j=0;j<l;j++)a[j]=1ll*a[j]*b[j]%mod;dft(l,a,-1);

		for(int j=0;j<=n;j++)dp[i][j]=(1ll*a[j]*fr[j+2]+1ll*(1ll*j*(j-1)%mod*499122177%mod+j+1)%mod*dp[i-1][j])%mod;

	}

	int as=0;

	for(int j=0;j<=n;j++)as=(as+1ll*dp[m][j]*c(n,j))%mod;

	printf("%d\n",as);

}//