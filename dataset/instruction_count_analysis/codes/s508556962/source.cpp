#include<iostream>

#include<queue>

#include<map>

#include<cassert>



using namespace std;



typedef long long ll;



int N;

ll A[100000 + 10];



const ll MOD = 1000000007;



int main() {

	cin >> N;

	for (int i = 0; i < N; i++)cin >> A[i];



	ll ans = 1;

	int cnt[3] = {};

	for (int i = 0; i < N; i++) {

		bool mode = false;

		ll times = 0;

		for (int j = 0; j < 3; j++) {

			if (!mode && A[i] == cnt[j]) {

				mode = true, cnt[j]++, times++;

			}

			else if (mode && A[i] == cnt[j]) {

				times++;

			}

		}

		(ans *= times) %= MOD;

	}

	cout << ans << endl;

	return 0;

}