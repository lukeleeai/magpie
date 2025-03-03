#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

typedef pair<long long,long long> pll;

#define ep emplace_back

#define pb push_back

#define mp make_pair

#define rep(i,n) for(int i=0;i<(n);++i)

constexpr int mod=1000000007;

constexpr int mod1=998244353;

vector<int> dx={0,1,0,-1},dy={-1,0,1,0};

bool inside(int y,int x,int h,int w){

	if(y<h && y>=0 && x<w && x>=0) return true;

	return false;

}











int main(){

	cin.tie(0);

	ios::sync_with_stdio(false);

	int n,k;cin >> n >> k;

	vector<int> a(n);

	rep(i,n) cin >> a.at(i);

	sort(a.begin(),a.end());

	int ng = 0,ok = n + 1;

	while(ok - ng > 1){

		int mid = (ok + ng) / 2;

		if(a.at(mid - 1) >= k){

			ok = mid;

			continue;

		}

		vector<bitset<5010>> dp(n + 1);

		dp[0].set(0);

		rep(i,n){

			if(i == mid - 1) dp[i + 1] |= dp[i];

			else dp[i + 1] |= dp[i] | (dp[i] << a.at(i));

		}

		bool flg = false;

		for(int i = k - a.at(mid - 1); i < k; i++){

			if(dp[n][i]){

				flg = true;

				break;

			}

		}

		if(flg) ok = mid;

		else ng = mid;

	}

	cout << ng << endl;

}
