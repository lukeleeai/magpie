#include"stdc++.h"

#define mod 1000000007

using namespace std;

int n,c,a[405],b[405],q[405][405],s[405][405],f[405][405],ans;

inline int read(){

    int x=0,f=1;char ch=getchar();

    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}

    return x*f;

}

int main(){

	n=read(),c=read();

	for(int i=1;i<=400;++i){

		q[i][0]=1;

		for(int j=1;j<=400;++j) q[i][j]=(1ll*q[i][j-1]*i)%mod;

	}

	for(int i=0;i<=400;++i){

		s[i][0]=1;

		for(int j=1;j<=400;++j)

			s[i][j]=(s[i][j-1]+q[j][i])%mod;

	}

	for(int i=1;i<=n;++i) a[i]=read();

	for(int i=1;i<=n;++i) b[i]=read();

	f[0][0]=1;

	for(int i=1;i<=n;++i)

		for(int j=0;j<=c;++j)

			for(int k=0;k<=j;++k)

				f[i][j]=(1ll*f[i][j]+1ll*f[i-1][k]*((s[j-k][b[i]]-s[j-k][a[i]-1]+mod)%mod))%mod;

	printf("%d",f[n][c]);

}