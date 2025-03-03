#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<cstring>

using namespace std;

#define MAXN 1000000

#define MOD 998244353

#define LL long long

int n,m;

int inv[MAXN+5],fac[MAXN+5];

int ans;

int fst_pow(int a,int b)

{

	int res=1;

	while(b)

	{

		if(b&1)res=(1LL*res*a)%MOD;

		a=(1LL*a*a)%MOD;

		b>>=1;

	}

	return res;

}

void prepare()

{

	fac[0]=1;

	for(int i=1;i<=n+m;i++)

	fac[i]=(1LL*fac[i-1]*i)%MOD;

	inv[n+m]=fst_pow(fac[n+m],MOD-2);

	for(int i=n+m-1;i>=0;i--)

	inv[i]=(1LL*inv[i+1]*(i+1))%MOD;

}

int Comb(int a,int b)

{

	return 1LL*(1LL*fac[a]*inv[a-b]%MOD)*inv[b]%MOD;

}

int main()

{

	scanf("%d%d",&n,&m);

	if(n<m)swap(n,m);

	prepare();

	for(int i=1;i<=m;i++)

		ans=(ans+1LL*Comb(2*i,i)*Comb(n+m-2*i,n-i)%MOD)%MOD;

	ans=1LL*ans*fst_pow(Comb(m+n,n),MOD-2)%MOD;

	ans=1LL*ans*fst_pow(2,MOD-2)%MOD;

	printf("%d",ans+n);

}
