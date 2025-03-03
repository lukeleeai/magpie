#include <cstdio>

#include <algorithm>

#include <vector>

#include <utility>

using namespace std;



typedef long long LL;

typedef pair <LL, LL> PII;



vector<PII> a;

LL dp[2005][2005];

int n;



LL solve(int l, int r){

	if (l > r) return 0;

	if (dp[l][r]) return dp[l][r];

	int i = n - (r - l + 1);

	return dp[l][r] = max(solve(l, r - 1) + a[i].first * (r - a[i].second), solve(l + 1, r) + a[i].first * (a[i].second - l));

}



int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++){

		int x;

		scanf("%d", &x);

		a.push_back({x, i});

	}

	sort(a.rbegin(), a.rend());

	solve(0, n - 1);

	printf("%lld\n", dp[0][n - 1]);

	return 0;

}
