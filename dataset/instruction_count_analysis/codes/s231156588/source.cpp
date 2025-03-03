#include<iostream>

#include<vector>

#include<algorithm>

#include<string>

#include<map>

#include<math.h>

#include<queue>

#include<deque>

#include<stack>

#include<cstdio>

#include<utility>

#include<set>

#include<list>

#include<cmath>

#include<stdio.h>

#include<string.h>

#include<iomanip>

using namespace std;

#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)

#define REP(i, n) FOR(i, 0, n - 1)

#define NREP(i, n) FOR(i, 1, n)

using ll = long long;

using pii = pair<int, int>;

using piii = pair<pii, pii>;

const int dx[4] = { 0, -1, 1, 0 };

const int dy[4] = { -1, 0, 0, 1 };

const int INF = 1e9 + 7;

int gcd(int x, int y) {

	if (x < y)swap(x, y);

	if (y == 0)return x;

	return gcd(y, x%y);

}



template<class T1, class T2> void chmin(T1 &a, T2 b) { if (a>b)a = b; }



template<class T1, class T2> void chmax(T1 &a, T2 b) { if (a<b)a = b; }

template<class T>

void Add(T &a, const T &b, const T &mod = 1000000007) {

	int val = ((a % mod) + (b % mod)) % mod;

	if (val < 0) { val += mod; }

	a = val;

}

////////////////////////////////////////

int main() {

	int N;

	cin >> N;

	int sum = 0;

	vector<int>V;

	for (int i = 0; i < N; ++i) {

		int s;

		cin >> s;

		sum += s;

		V.push_back(s);

	}

	sort(V.begin(), V.end());

	if (sum % 10 != 0) {

		cout << sum << endl;

	}

	else {

		for (int i = 0; i < N; ++i) {

			if ((sum - V[i]) % 10 != 0) {

				cout << sum - V[i] << endl;

				return 0;

			}

		}

		cout << 0 << endl;

	}

	return 0;

}
