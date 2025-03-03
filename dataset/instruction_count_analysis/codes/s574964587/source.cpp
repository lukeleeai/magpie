#include "stdc++.h"

#define ll long long

#define pb push_back

#define mp make_pair

#define modulo 1000000007

#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

using namespace std;

string s;

ll k,n;

ll dp[105][105][2];

ll solve(int ind, int digit, int flag){

	if(ind>=n){

		if(digit==k)

			return 1;

		return 0;

	}

	if(dp[ind][digit][flag]!=-1)

		return dp[ind][digit][flag];

	int limit=9;

	if(!flag)

		limit=(s[ind]-'0');

	ll res=0;

	for (int i = 0; i <= limit; ++i){

		if(!flag && i==limit)

			res=res+solve(ind+1,i==0?digit:digit+1,0);

		else

			res=res+solve(ind+1,i==0?digit:digit+1,1);

	}

	dp[ind][digit][flag]=res;

	return dp[ind][digit][flag];

}

int main(){

	fast_io;

	cin>>s>>k;

	n=s.length();

	memset(dp,-1,sizeof(dp));

	ll ans=solve(0,0,0);

	cout<<ans<<"\n";

	return 0;

}