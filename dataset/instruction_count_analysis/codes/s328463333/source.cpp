#include <cstdio>

#include <cstring>

#define ll long long

using namespace std;

inline int read(){

	int x=0,f=1;char c=getchar();

	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}

	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}

	return x*f;

}

const int mod(1e9+7),maxn(405);

int n,c;

ll sum[maxn],f[maxn][maxn];

int a[maxn],b[maxn];

void init(){

	n=read(),c=read();

	for (int i(1);i<=n;++i) a[i]=read();

	for (int i(1);i<=n;++i) b[i]=read();

	f[0][0]=1;

}



void calc(int a,int b){

	memset(sum,0,sizeof(sum));

	for (int i(a);i<=b;++i){

		ll t=1;

		for (int j(0);j<=c;++j){

			sum[j]=sum[j]+t,sum[j]%=mod;

			t=t*i%mod;

		}

	}

}



signed main(){

	init();

	for (int i(1);i<=n;++i){

		calc(a[i],b[i]);

		for (int j(0);j<=c;++j)

			for (int k(0);k<=j;++k)

				f[i][j]=(f[i][j]+f[i-1][j-k]*sum[k])%mod;

	}

	printf("%d\n",f[n][c]);					 

	return 0; 

}
