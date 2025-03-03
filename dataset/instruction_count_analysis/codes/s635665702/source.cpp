#include "stdc++.h"

using namespace std;

vector<long long> res1; 

vector<long long> res2;

long long mod=1e9+7;

long long fact[200010];

long long poww(long long x,long long n)

{

	if(n==0)

	return 1*1LL;

	else if(n%2==0)

	{

		return poww(x,n/2)*poww(x,n/2)%mod;

	}

	else if(n%2!=0)

	{

		return poww(x,n/2)*poww(x,n/2)%mod*x%mod;

	}

}

long long C(long long k,long long n)

{

	if(k==0||n==0) return 1*1LL;

	if(k>n) return 0*1LL;

	return poww(fact[k],mod-2)%mod * poww(fact[n-k],mod-2)%mod * fact[n]%mod;

}

int main()

{

	//ios_base::sync_with_stdio(0);

	//cin.tie(0);

	//cout.tie(0);

	fact[0]=1*1LL;

	for(long long i=1;i<=200000;i++)

	{

		fact[i]=(fact[i-1]*i)%mod;

	}

	long long h,w,a,b;

	long long ans=0;

	cin >> h>>w>>a>>b;

	for(int i=1;i<=w-b;i++){

		ans+=C(h-a-1,h-a+b+i-2)*C(a-1,a+w-b-i-1)%mod;

		ans=ans%mod;

	}

	cout<<ans%mod;

	//cout  << C(99,1000);

}

//yyyyyyy