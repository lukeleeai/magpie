#include "stdc++.h"

using namespace std;



int main() {

	ios::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	string s; cin >> s;

	vector<string> pat;

	pat.push_back("dream");

	pat.push_back("dreamer");

	pat.push_back("erase");

	pat.push_back("eraser");

	vector<bool> f(s.length() + 1, false);

	f[0] = true;

	for (int i = 1; i <= s.length(); i++) {

		for (auto p : pat) {

			if (i >= p.length() && s.substr(i - p.length(), p.length()) == p && f[i - p.length()]) {

				f[i] = true;

			}

		}

	}

	cout << (f[s.length()] ? "YES\n" : "NO\n");

	return 0;

}
