#include "stdc++.h"

#define INF 1000000000

#define LINF 1000000000000000000

#define MOD 1000000007

#define mod 1000007

#define INF63 1061109567

#define INF127 9187201950435737471

#define UINF 18446744073709551615

#define F first

#define S second

#define ll long long

#define N 200010

#define HASH 813234241

using namespace std;

ll n,a[N],b[N],dxa[N],dxb[N],phs=0,ehs=0,pres;

ll ksm(ll x,ll y)

{

	if(y==0)

	{

		return 1;

	}

	if(y==1)

	{

		return x;

	}

	ll ret=ksm(x,y/2);

	if(y%2==1)

	{

		return (((ret*ret)%MOD)*x)%MOD;

	}

	return (ret*ret)%MOD;

}

int main(){

	ll i,j,cnt=0;

	cin>>n;

	for(i=0;i<n;i++)

	{

		cin>>a[i];

	}

	for(i=0;i<n;i++)

	{

		cin>>b[i];

	}

	for(i=0;i<n;i++)

	{

		dxa[i]=a[i]^a[(i+1)%n];

		phs=(phs*HASH+dxa[i])%MOD;

	}

	for(i=0;i<n;i++)

	{

		dxb[i]=b[i]^b[(i+1)%n];

		ehs=(ehs*HASH+dxb[i])%MOD;

	}

	pres=ksm(HASH,n-1);

	for(i=0;i<n;i++)

	{

		if(phs==ehs)

		{

			cout<<i<<" "<<(a[0]^b[(n-i)%n])<<endl;

		}

		phs=(((phs-(pres*dxa[i])%MOD)%MOD)+MOD)%MOD;//减去多余的前缀 

		phs=(phs*HASH+dxa[i])%MOD;//加上第i个 

	}

	return 0;

}