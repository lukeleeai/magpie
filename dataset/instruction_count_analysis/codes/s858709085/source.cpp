#include"stdc++.h"

using namespace std;

inline int read(){

	int x=0,f=1;char ch=getchar();

	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}

	return x*f;

}

#define mod 1000000007

#define MN 405

long long f[MN][MN],pw[MN][MN],qz[MN][MN];

int n,c,a[MN],b[MN];

void add(long long &x,long long y){x+=y;if(x>mod)x-=mod;}

long long Abs(long long x){if(x<0) x+=mod;return x;}

int main(){

	register int i,j,k;

	for(i=1;i<=400;i++) pw[i][0]=1;

	

	for(i=1;i<=400;i++)for(j=1;j<=400;j++) pw[i][j]=(pw[i][j-1]*i)%mod;

	for(i=1;i<=400;i++)for(j=0;j<=400;j++) qz[i][j]=(qz[i-1][j]+pw[i][j])%mod;

	

	n=read(),c=read();

	for(i=1;i<=n;i++) a[i]=read();

	for(i=1;i<=n;i++) b[i]=read();

	

	f[0][0]=1;

	

	for(i=1;i<=n;i++)for(j=0;j<=c;j++)for(k=j;k>=0;k--){

		add(f[i][j],f[i-1][k]*Abs(qz[b[i]][j-k]-qz[a[i]-1][j-k])%mod);

	}

	printf("%lld\n",f[n][c]);

	return 0;

}