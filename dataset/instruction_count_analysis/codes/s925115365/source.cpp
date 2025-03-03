#include"stdc++.h"

#define il inline

#define rg register

using namespace std;

typedef long long ll;

const int O=510;

const ll mod=1e9+7;

il int gi(){

	int o=0,fl=1;char ch=getchar();

	while(!isdigit(ch)&&ch!='-')ch=getchar();

	if(ch=='-')fl=-1,ch=getchar();

	while(isdigit(ch))o=o*10+ch-'0',ch=getchar();

	return fl*o;

}

int n,c,a[O],b[O];

ll f[O][O],bin[O][O];

int main(){

	for(int i=1;i<O;++i)bin[i][0]=1;

	for(int i=1;i<O;++i)

		for(int j=1;j<O;++j)

			bin[i][j]=bin[i][j-1]*i%mod;

	for(int i=1;i<O;++i)

		for(int j=0;j<O;++j)

			bin[i][j]=(bin[i-1][j]+bin[i][j])%mod;

	n=gi();c=gi();

	for(int i=1;i<=n;++i)a[i]=gi();

	for(int i=1;i<=n;++i)b[i]=gi();

	f[0][0]=1;

	for(int i=1;i<=n;++i)

		for(int j=0;j<=c;++j)

			for(int k=0;k<=j;++k)

				(f[i][j]+=f[i-1][j-k]*((bin[b[i]][k]-bin[a[i]-1][k])%mod+mod)%mod)%=mod;

	printf("%lld\n",f[n][c]);

	return 0;

}
