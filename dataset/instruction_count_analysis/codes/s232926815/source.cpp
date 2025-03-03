#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define fbo find_by_order

#define ook order_of_key



typedef long long ll;

typedef pair<ll,ll> ii;

typedef vector<int> vi;

typedef long double ld; 

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

typedef set<int>::iterator sit;

typedef map<int,int>::iterator mit;

typedef vector<int>::iterator vit;



ll n;

ll a[100001];



int main()

{

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin>>n;

	for(int i = 0; i < n; i++)

	{

		cin>>a[i];

	}

	ll sum = 0;

	for(int i = 0; i < n; i++)

	{

		sum+=a[i];

	}

	ll tot = (ll(n)*ll(n+1))/2;

	if(sum%tot==0)

	{

		ll xsum = sum/tot;

		for(int i = 1; i <= n; i++)

		{

			int u = i; int v = i-1;

			if(u==n) u=0;

			ll diff = a[u] - a[v];

			ll nx2 = xsum - diff;

			if(nx2<0)

			{

				cout<<"NO\n";

				return 0;

			}

			if(nx2%n==0)

			{

				

			}

			else

			{

				cout<<"NO\n";

				return 0;

			}

		}	

		cout<<"YES\n";

	}

	else

	{

		cout<<"NO\n";

	}

}
