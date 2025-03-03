#include "stdc++.h"

#define ll long long

#define ull unsigned long long

#define pii pair<int,int>

#define pil pair<int,along long>

#define pli pair<long long,int>

#define pll pair<long long,long long>

#define pb push_back

#define mk make_pair

#define maxn 100009

#define eps 1e-12

using namespace std;

int main()

{

	ios_base::sync_with_stdio(false);

	ll n,x;

	cin>>n>>x;

	ll base=n;

	ll repeat=n-x;

	ll ans=x;

	if(base%repeat==0)

	{

		ans+=((base/repeat)-1)*2*repeat;

		cout<<ans<<"\n";

		return 0;

	}

	if(base%repeat!=0)

	{

		ans+=(((base/repeat)*2*repeat)-repeat);

		ll temp=base;

		base=repeat;

		repeat=temp%repeat;

	}

	while(base%repeat!=0)

	{

		ans+=((base/repeat)*2*repeat);

		ll temp=base;

		base=repeat;

		repeat=temp%repeat;

	}

	ans+=((base/repeat)*2*repeat);

	ans-=repeat;

	cout<<ans<<"\n";

}