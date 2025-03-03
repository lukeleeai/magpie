#include<cstdio>

#include<cstring>

#include<algorithm>

#define ll long long

#define mod 998244353

#define MN 4000

using namespace std;

inline int in(){

    int x=0;bool f=0;char c;

    for (;(c=getchar())<'0'||c>'9';f=c=='-');

    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');

    return f?-x:x;

}

int fac[MN+5],pw[MN+5],inv[MN+5];

int n,k,res,num;

inline int qpow(int x,int k){

	int res=1;

	while (k){

		if (k&1) res=(1ll*res*x)%mod;

		x=(1ll*x*x)%mod;k>>=1;

	}return res;

}

inline int C(int x,int y){

	if (x<y||y<0) return 0;

	return (1ll*fac[x]*inv[y]%mod*inv[x-y]%mod);

}

inline int calc(int x,int p,int n){

	int res=0;

	for (int i=0;i<=x;++i)

	res=(1ll*res+(1ll*pw[i]*C(x,i)%mod*C(n+p-1,p+i-1)%mod))%mod;

	return res;

}

int main()

{

	fac[0]=pw[0]=1;

	for (int i=1;i<=MN;++i)

	fac[i]=(1ll*fac[i-1]*i)%mod,pw[i]=(pw[i-1]*2)%mod;

	inv[MN]=qpow(fac[MN],mod-2);

	for (int i=MN-1;i>=0;--i)

	inv[i]=(1ll*inv[i+1]*(i+1))%mod;

	k=in();n=in();

	for (int i=2;i<=(k<<1);++i){

		num=min(i-1,k)-max(i-k-1,0);

		if (i&1) printf("%d\n",calc((num>>1),k-num,n));

		else printf("%d\n",(calc(((num-1)>>1),k-num,n)+calc(((num-1)>>1),k-num,n-1))%mod);

	}return 0;

}