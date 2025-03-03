#include"stdc++.h"

#define LL long long

#define uLL unsigned long long



using namespace std;

const int N=400+10,mod=998244353;

int rd()

{

    int x=0,w=1;char ch=0;

    while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}

    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}

    return x*w;

}

void ad(int &x,int y){x+=y,x-=x>=mod?mod:0;}

int fpow(int a,int b){int an=1;while(b){if(b&1) an=1ll*an*a%mod;a=1ll*a*a%mod,b>>=1;}return an;}

int ginv(int a){return fpow(a,mod-2);}

int n,a,pw[N],b,sa,sb,f[2][N][N],fac[N],iac[N];



int main()

{

	fac[0]=1;

	for(int i=1;i<=N-5;++i) fac[i]=1ll*fac[i-1]*i%mod;

	iac[N-5]=ginv(fac[N-5]);

	for(int i=N-5;i;--i) iac[i-1]=1ll*iac[i]*i%mod;

	n=rd();

	int nw=1,la=0;

	f[la][0][0]=mod-1;

	for(int i=1;i<=n;++i)

	{

		a=rd(),b=rd();

		pw[0]=1;

		for(int j=1;j<b;++j) pw[j]=1ll*pw[j-1]*a%mod;

		for(int j=0;j<=sa;++j)

			for(int k=0;k<=sb;++k)

			{

				if(!f[la][j][k]) continue;

				ad(f[nw][j][k],f[la][j][k]);

				for(int l=0;l<b;++l)

					ad(f[nw][j+a][k+l],mod-1ll*f[la][j][k]*pw[l]%mod*iac[l]%mod);

				f[la][j][k]=0;

			}

		nw^=1,la^=1;

		sa+=a,sb+=b-1;

	}

	int ans=0;

	for(int j=0;j<=sa;++j)

	{

		int w=ginv(j);

		for(int k=0,p=w;k<=sb;++k,p=1ll*p*w%mod)

			ad(ans,1ll*f[la][j][k]*p%mod*fac[k]%mod);

	}

	ans=1ll*ans*sa%mod;

	printf("%d\n",ans);

	return 0;

}
