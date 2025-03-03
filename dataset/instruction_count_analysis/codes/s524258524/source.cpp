#include"stdc++.h"

#define ll long long int

#define mp make_pair

#define pb push_back

#define ff first 

#define ss second

#define mod 1000000007

#define lim 100005

#define mx 20005

#define nfs_mw ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;



struct box{

	int w,s,v;

	bool operator<(const box & b)

	{

		return (s+w<b.s+b.w);

	}

};



int main()

{

	ll ans = 0;

	int i,j,n,w,s,v,maxmw = 0;

	cin>>n;

	vector<box> all;

	for(i=0; i<n; i++){

		cin>>w>>s>>v;

		all.pb({w,s,v});

	}

	sort(all.begin(), all.end());

	ll dp[mx] = {};ll dp2[mx] = {};

	dp[0] = 0;

	for(i=0; i<n; i++){

		for(j=1; ((all[i].s + all[i].w) >= j); j++){

			dp2[j] = max({dp2[j-1], ((all[i].w<=j)?(dp[j-all[i].w] + all[i].v):0), dp[j]});

		}

		swap(dp,dp2);

	}

	cout<<dp[all[n-1].s+all[n-1].w];

}