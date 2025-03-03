#include "stdc++.h"

#define ll long long

using namespace std;

template<typename T>void read(T &x){

	x = 0;int f(1);char c = getchar();

	for(;!isdigit(c);c = getchar()) if(c == '-') f=-1;

	for(;isdigit(c);c = getchar()) x = x * 10 + c -'0';

	x *= f;

}

const ll p = 924844033;

int n,k;

ll inv[2005],jc[2005],invjc[2005];

ll dp[2005];

int line_size(int s){

	int tnum = (n-s) / (k<<1);

	int ret = tnum+1 <<1;

	if(s < k+1)	--ret;

	if(s+tnum*(k<<1)+k > n)	--ret;

	return ret;

}

ll c(int x,int y){return x > y?0:jc[y] * invjc[x] % p * invjc[y-x] % p;}

int main(){

	read(n);read(k);

	jc[0] = jc[1] = invjc[0] = invjc[1] = inv[1] = 1;

	for(int i(2);i<=n;++i){

		jc[i] = jc[i-1] * i % p;

		inv[i] = (p-p/i) * inv[p%i] % p;

		invjc[i] = invjc[i-1] * inv [i] % p;

	}

	dp[0] = 1;

	for(int s(1),asize(0);s<=min(n,k<<1);++s){

		int nsize = line_size(s); asize += ((n-s)/(k<<1)+1);

		for(int i = asize;i >= 0;--i)

			for(int j = i-1;j >= 0&&(i-j<=nsize-i+j+1);--j)

			dp[i] = (dp[i]+dp[j]*c(i-j,nsize-(i-j)+1))%p;

	}

	ll ans = 0;

	for(int i = 0,v = 1;i <= n;++i,v = -v)

		ans = (ans+v*dp[i]%p*jc[n-i]%p+p) %p;

	printf("%lld\n",ans);

	return 0;

}