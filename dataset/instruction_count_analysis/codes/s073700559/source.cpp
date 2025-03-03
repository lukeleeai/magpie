#include<iostream>

#include<string>

#include<cstdio>

#include<vector>

#include<cmath>

#include<algorithm>

#include<functional>

#include<iomanip>

#include<queue>

#include<ciso646>

#include<random>

#include<map>

#include<set>

#include<bitset>

#include<stack>

#include<unordered_map>

#include<utility>

#include<cassert>

#include<complex>

#include<numeric>

using namespace std;



//#define int long long

typedef long long ll;



#define rep(i,n) for(int i=0;i<n;i++)







int dp[101][401];

void solve() {

	dp[0][0] = 1;

	int x, y; cin >> x >> y;

	rep(i, x) {

		rep(j, 4*i+1) {

			dp[i + 1][j + 2] += dp[i][j];

			dp[i + 1][j + 4] += dp[i][j];

		}

	}

	if (dp[x][y] > 0) {

		cout << "Yes\n";

	}

	else {

		cout << "No\n";

	}

}





signed main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	solve();

		return 0;

}
