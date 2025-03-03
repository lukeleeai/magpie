#include<cstdio>

#include<cstring>

#include<algorithm>

#define LL long long

using namespace std;

const int M=557,mod=1e9+7,mx=400;

LL read(){

	LL ans=0,f=1,c=getchar();

	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}

	while(c>='0'&&c<='9'){ans=ans*10+(c-'0'); c=getchar();}

	return ans*f;

}

LL n,c;

LL A[M],B[M],p[M][M],f[M][M];

int main(){

	n=read(); c=read();

	for(int i=1;i<=n;i++) A[i]=read();

	for(int i=1;i<=n;i++) B[i]=read();

	for(int i=1;i<=mx;i++) p[i][0]=1;

	for(int i=1;i<=mx;i++)

		for(int j=1;j<=c;j++) p[i][j]=p[i][j-1]*i%mod;

	for(int i=1;i<=mx;i++)

		for(int j=0;j<=c;j++) p[i][j]=(p[i][j]+p[i-1][j])%mod;

	f[0][0]=1;

	for(int i=1;i<=n;i++)

	for(int j=0;j<=c;j++)

	for(int m=0;m<=j;m++)

	f[i][j]=(f[i][j]+f[i-1][j-m]*(((p[B[i]][m]-p[A[i]-1][m])%mod+mod)%mod))%mod;

	printf("%lld\n",f[n][c]);

	return 0;

}