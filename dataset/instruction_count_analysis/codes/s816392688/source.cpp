#include<iostream>

using namespace std;

const long long mod=1e9+7;

long long jc[6060606],_jc[6060606];

long long pow(long long n,long long k)

{

	long long ret=1;

	while(k>0)

	{

		if(k&1)

			ret=ret*n%mod;

		n=n*n%mod;

		k/=2;

	}

	return ret;

}

long long C(int n,int m)

{

	return jc[n]*_jc[m]%mod*_jc[n-m]%mod;

}

int main()

{

	int n,m,k;

	cin>>n>>m>>k;

	jc[0]=1;

	_jc[0]=1;

	for(int i=1;i<=n+m+k;i++)

	{

		jc[i]=jc[i-1]*i%mod;

		_jc[i]=pow(jc[i],mod-2);

	}

	long long tmp=1,ans=0;

	for(int i=0;i<=m+k;i++)

	{

		ans=(ans+C(n+i-1,i)*tmp%mod*pow(3,m+k-i)%mod)%mod;

		tmp*=2;

		if(i+1>k)

			tmp-=C(i,i-k); 

		if(i+1>m)

			tmp-=C(i,m);

		tmp+=2*mod;

		tmp%=mod;

	}

	cout<<ans<<endl;

	return 0;

}