#include "stdc++.h"

using namespace std;

typedef long long ll;



int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	string s, t; cin >> s >> t;

	s += t[t.size()-1];

	cout << ((s==t)?"Yes":"No") << '\n';

	return 0;

}