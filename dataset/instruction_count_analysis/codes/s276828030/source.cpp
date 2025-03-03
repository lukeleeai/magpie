// In the name of God



#include "stdc++.h"



using namespace std;



int main() {

	ios_base::sync_with_stdio(0), cin.tie(0);

	long long n, k;

	cin >> n >> k;

	long long ans = n / k;

	ans = ans * ans * ans;

	if(k % 2 == 0) {

		long long cnt = n / k;

		if(n % k >= k / 2) cnt++;

		ans += cnt*cnt*cnt;

	}

	cout << ans;

	return 0;

}
