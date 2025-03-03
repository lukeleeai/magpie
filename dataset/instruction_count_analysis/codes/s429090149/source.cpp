#include"stdc++.h"



using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

const int N = 10000;



ll a[N]; 

ll r[N],l[N];

int main()

{

	ios::sync_with_stdio(0);

	cin.tie(0);cout.tie(0);

	ll n,k,ans;

	cin>>n>>k;

	for(ll i=1;i<=n;i++) cin>>a[i];

	ll num=0;

	num=(k+1)*k/2;

	num-=k;

	num%=mod;

	ans=0;

	memset(r,0,sizeof(r));

	memset(l,0,sizeof(l));

	for(ll i=1;i<=n;i++)

	{

		for(ll j=1;j<i;j++)

		{

			if(a[i]>a[j])

				l[i]++;//这个数左边小于当前位置的数的个数 

		}

		for(ll j=i+1;j<=n;j++)

		{

			if(a[i]>a[j])

				r[i]++;//这个数右边小于当前位置的数的个数 

		}

	}

//	cout<<num<<endl;

	for(ll i=1;i<=n;i++)

	{

//		cout<<l[i]<<' '<<r[i]<<endl;

		ans=ans+l[i]*num%mod;

		ans=ans+r[i]*(num+k)%mod;

	}

	cout<<ans%mod<<endl;	

	return 0;

}




