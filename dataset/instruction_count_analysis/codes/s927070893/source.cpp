#include "stdc++.h"

using namespace std;

string s;

int main() {

	cin >> s;

	int l = -1, r = -1;

	for(int i = 1; i < s.size(); i++) {

		if(s[i - 1] == s[i]) l = i, r = i + 1;

	}

	for(int i = 2; i < s.size(); i++) {

		if(s[i - 2] == s[i]) l = i - 1, r = i + 1;

	}

	cout << l << ' ' << r << endl;

	return 0;

}