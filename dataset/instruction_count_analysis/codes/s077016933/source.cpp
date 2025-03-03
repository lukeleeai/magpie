/*   In The Name Of God   */

// Hunt...

/*

ID: alimora2

LANG: C++11

TASK: PROB

*/

#include "stdc++.h"



#define sqr(A) (A) * (A)

using namespace std;

typedef long long ll;



int main() {

	ios::sync_with_stdio(false), cin.tie(0);

	string s;

	int ans;

	stack<char> t;

	cin >> s;

	ans = s.size();

	for (int i = 0; i < s.size(); i++) {

		if (s[i] == 'S')

			t.push(s[i]);

		if (!t.empty() && s[i] == 'T') {

			t.pop();

			ans -= 2;

		}

	}

	cout << ans << endl;

}