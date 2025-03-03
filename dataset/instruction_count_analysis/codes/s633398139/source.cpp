#include "stdc++.h"

using namespace std;



int main() {

	ios::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	string s; cin >> s;

	for (int i = 0; i < s.length() - 1; i++) if (s[i] == 'A' && s[i + 1] == 'C') {

		cout << "Yes" << endl;

		return 0;

	}

	cout << "No" << endl;

	return 0;

}


