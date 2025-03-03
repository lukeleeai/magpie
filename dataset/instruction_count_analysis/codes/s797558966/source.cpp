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

const int MOD = (1e9 + 7);

struct Combi

{

	vector<int> fact;

	vector<int> ifact;

	vector<int> inv;

	vector<int> pow2;

	const int MOD = (1e9 + 7);

	int add(int a, int b)

	{

		a+=b;

		while(a>=MOD) a-=MOD;

		return a;

	}

	int mult(int a, int b)

	{

		return (a*1LL*b)%MOD;

	}

	int modpow(int a, int b)

	{

		int r=1;

		while(b)

		{

			if(b&1) r=mult(r,a);

			a=mult(a,a);

			b>>=1;

		}

		return r;

	}

	int choose(int a, int b)

	{

		if(a<b) return 0;

		if(b==0) return 1;

		if(a==b) return 1;

		return mult(fact[a],mult(ifact[b],ifact[a-b]));

	}

	int inverse(int a)

	{

		return modpow(a,MOD-2);

	}

	void init(int _n)

	{

		fact.clear(); ifact.clear(); inv.clear(); pow2.clear();

		fact.resize(_n+1);

		ifact.resize(_n+1);

		inv.resize(_n+1);

		pow2.resize(_n+1);

		pow2[0]=1;

		ifact[0]=1;

		fact[0]=1;

		for(int i=1;i<=_n;i++)

		{

			pow2[i]=add(pow2[i-1],pow2[i-1]);

			fact[i]=mult(fact[i-1],i);

			//ifact[i]=mult(ifact[i-1],inv[i]);

		}

		ifact[_n] = inverse(fact[_n]);

		for(int i=_n-1;i>=1;i--)

		{

		    ifact[i] = mult(ifact[i + 1], i + 1);

		}

		for(int i=1;i<=_n;i++)

		{

		    inv[i] = mult(fact[i-1],ifact[i]);

		}

	}

};



int dp[3011][3011][2];

Combi combi;



void add(int &a, int b)

{

	a+=b;

	while(a>=MOD) a-=MOD;

}



int main()

{

	ios_base::sync_with_stdio(0); cin.tie(0);

	combi.init(3111);

	ll n, m; cin>>n>>m;

	for(int i=0;i<=n;i++) 

	{

		dp[0][i][i==0] = 1;

	}

	for(int i=0;i<m;i++)

	{

		for(int j=0;j<=n;j++)

		{

			for(int k=0;k<2;k++)

			{

				int v=dp[i][j][k];

				//cerr<<i<<' '<<j<<' '<<k<<' '<<v<<'\n';

				if(v==0) continue;

				//RR

				if(j>=1)

				{

					add(dp[i+1][j-1][k|(j-1==0)],v);

				}

				//BB

				if(j+1<=n)

				{

					add(dp[i+1][j+1][k|(j==0)],v);

				}

				//RB

				if(j-1>=0)

				{

					add(dp[i+1][j][k|(j-1==0)],v);

				}

				//BR

				if(j+1<=n)

				{

					add(dp[i+1][j][k|(j==0)],v);

				}

			}

		}

	}

	int ans=0;

	for(int i=0;i<=n;i++)

	{

		add(ans,dp[m][i][1]);

	}

	cout<<ans<<'\n';

}
