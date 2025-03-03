#include "stdc++.h"

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	int n, s, k;

	cin >> n >> k >> s;

	for (int i = 0; i < k; i++) {

		cout << s << " ";

	}

	n -= k;

	if (n >= s) {

		for (int i = 0; i < n; i++) {

			cout << s + 1 << " ";

		}

	}

	else for (int i = 0; i < n; i++) cout << 1 << " ";

}