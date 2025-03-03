#include "stdc++.h"



using namespace std;



#define el				'\n'

#define sz(v)			((int)((v).size()))

#define all(v)          ((v).begin()),((v).end())

#define clr(v, d)		memset(v, d, sizeof(v))



double const EPS = 1e-8, PI = acos(-1);

const int N = 2e5 + 9, M = 50 + 9, OO = (int) 1e9 + 1;

const long long MOD = 1e9 + 7;



typedef long long ll;



void OUTPUT() {

	cout << fixed << setprecision(12);

	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

}



void INPUT() {

#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);

#endif

	cout << fixed << setprecision(12);

//	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

}



vector<vector<int>> edges(N);

ll n, q, x, y;

ll counter[N];

bool vis[N];



int main() {

	OUTPUT();

//	INPUT();

	cin >> n;

	x = n;

	x--;

//	ll ans = (double(1 + x) / 2.0) * x;

	ll ans = x + (x * x);

	ans /= 2;

	cout << ans;

//	for (int i = 1; i <= n; i++) {

//		y += i % x;

//		cout << i % x << " " << i << el;

//		x--;

//	}

//	cout << y;



	return 0;



}
