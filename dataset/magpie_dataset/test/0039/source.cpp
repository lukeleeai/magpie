#pragma GCC optimize ("O3")

#include "stdc++.h"

#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

ll n , k ,arr[100005] , memo[100005];

ll solve(ll i)

{

	if(i == n - 1)

		return 0;

	ll &ans = memo[i];

	if(~ans)

		return ans;

	ans = 1e9;

	for(int j = 1;j <= k && j + i < n;j++)

		ans = min(ans , abs(arr[i] - arr[i + j]) + solve(i + j));

	return ans;

}

int main()

{

	abdelrahman010

	cin >> n >> k;

	memset(memo , -1 , sizeof memo);

	for(int i = 0;i < n;i++)

		cin >> arr[i];

	cout << solve(0);

	return 0;

}
