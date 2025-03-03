#include <iostream>

using namespace std;

int n, m, x, s[100];

int main() {

	while(cin >> n >> m, n + m) {

		for(int i = 0; i < m; i++) cin >> s[i];

		for(int i = 0; i < n; i++) {

			for(int j = 0; j < m; j++) cin >> x, s[j] -= x;

		}

		int f = 1;

		for(int i = 0; i < m; i++) {

			if(s[i] < 0) f = 0;

		}

		cout << (f ? "Yes" : "No") << endl;

	}

}