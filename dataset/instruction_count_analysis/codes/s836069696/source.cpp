#include "stdc++.h"

#define ll long long

#define ld long double

#define ull unsigned ll

#define ioi exit(0);

 

#define f first

#define s second

 

#define inf (int)1e9 + 7

 

#define NFS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

 

#define mp(x,y) make_pair(x,y)

 

#define lb(x) lower_bound(x)

#define ub(x) upper_bound(x)

 

#define pb push_back

#define ppb pop_back

 

#define bitcoin __builtin_popcount

 

#define endl "\n"

 

#define in(x) insert(x)

 

#define sz(x) (int)x.size()

 

#define all(x) x.begin(),x.end()

 

#define pw2(x) (1ll<<x) //2^x

 

#define forit(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); ++it)

 

#define sqr(x) ((x) * 1ll * (x))

 

#define UpdateRandom srand (time(NULL));

 

using namespace std;

 

const int N = (int)3e3 + 7, MOD = (int)1e9 + 7;



string s,t;



string dp[4][N];



int main(){

		

	NFS



	cin >> s >> t;



	for(int i=1;i<=sz(s);i++){

		for(int j=1;j<=sz(t);j++){

			if(sz(dp[2][j-1])>sz(dp[2][j]))dp[2][j]=dp[2][j-1];

			if(sz(dp[2-1][j])>sz(dp[2][j]))dp[2][j]=dp[2-1][j];

			if(sz(dp[2-1][j-1])>sz(dp[2][j]))dp[2][j]=dp[2-1][j-1];

			if(s[i-1]==t[j-1]){

				if(sz(dp[2-1][j-1])+1>sz(dp[2][j]))dp[2][j]=dp[2-1][j-1]+s[i-1];

			}

		}

		for(int j=1;j<=sz(t);j++)dp[1][j]=dp[2][j],dp[2][j].clear();

	}

	

	cout << dp[1][sz(t)] << endl;

	

	ioi

}