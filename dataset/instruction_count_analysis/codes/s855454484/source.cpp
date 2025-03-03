#include "stdc++.h"

using namespace std;



int main() {

	ios::sync_with_stdio(0);cin.tie(0);

	int n;

	cin >> n;

	int t[3] = {0,0,0};

	long long ans = 1;

	for(int i=0; i<n; i++) {

		int a;

		cin >> a;

		int p = -1, cnt = 0;

		for(int j=0; j<3; j++) {

			if(t[j] == a) {

				p = j;

				cnt++;

			}

		}

		ans *= cnt;

		t[p]++;

		ans %= (int)(1e9+7);

	}

	cout << ans;

}