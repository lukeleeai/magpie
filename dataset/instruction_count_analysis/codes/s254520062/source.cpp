#include<iostream>

#include<algorithm>

#include<vector>



using namespace std;



typedef long long ll;



ll N, A[100000 + 10];



const ll MOD = 1000000007;



vector<ll> memo[100000 + 10];



int main() {

	cin >> N;

	for (int i = 0; i < N; i++)cin >> A[i];



	for (int i = 0; i <= N; i++)memo[i].resize(3, 0);

	ll ans = 1;

	for (int i = 0; i < N; i++) {

		if (count(memo[i].begin(), memo[i].end(), A[i]) == 0) {

			cout << 0 << endl;

			return 0;

		}

		ans *= count(memo[i].begin(), memo[i].end(), A[i]);

		ans %= MOD;

		memo[i + 1] = memo[i];

		int idx = find(memo[i + 1].begin(), memo[i + 1].end(), A[i]) - memo[i + 1].begin();

		memo[i + 1][idx]++;

	}

	cout << ans << endl;

	return 0;

}