#include<iostream>

#include<cmath>

#include<cstdio>

#include<algorithm>

#include<queue>

#include<cstring>

#define ll long long

using namespace std;



const ll mod=1e9+7;



ll ksm(ll b,ll p)

{

	ll ans=1;

	while(p>0)

    {

        if(p%2==1)

            ans=(ans*b)%mod;

        b=(b*b)%mod;

        p/=2;

    }

    return ans;

}



ll f[500010],anss;



int main()

{

	int n,k;

	cin>>n>>k;

	for(ll i=k;i>=1;i--)

	{

		ll cnt=k/i;

		f[i]=ksm(cnt,n);

		for(ll j=2*i;j<=k;j+=i)

		{

			f[i]=(f[i]+mod-f[j])%mod;

		}

	}

	for(ll i=1;i<=k;i++)

	{

		anss+=f[i]*i;

		anss%=mod;

	}

	cout<<anss;

        return 0;

}