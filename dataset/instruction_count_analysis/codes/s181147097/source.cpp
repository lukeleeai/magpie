#include "stdc++.h"

using namespace std;



typedef long long ll;

typedef long double ld;

typedef vector<vector<int>> Graph;

const int dx[4] = {1, 0, -1, 0};

const int dy[4] = {0, 1, 0, -1};

#define pi 3.14159265359

#define inf 2147483647

#define INF 9223372036854775807

#define mod 1000000007

#define mod2 998244353



ll f(ll n, ll m) {

	return (n * n) % m;

}



int main() {

	ll N, X, M; cin >> N >> X >> M;

	ll A, preA, ans = 0;

	ll loopcnt = 0, cnt = 0, sum_loop = 0, rec_A;

	vector<bool> visit(100001);

	bool dub = false;

	for(int i = 1; i <= N; i++) {

		if(i == 1) {

			A = X;

			ans += A;

			visit[A] = true;

			cnt++;

			continue;

		}

		preA = A;

		A = f(A, M);

		if(dub) {

			if(A == rec_A) break;

			ans += A; sum_loop += A; loopcnt++; cnt++;

		}

		else {

			if(visit[A]) {

				dub = true; rec_A = A; sum_loop += A; loopcnt++;

			}

			ans += A;

			cnt++;

			visit[A] = true;

		}

	}

	A = preA;

	if(dub) {

		ans += sum_loop * ((N - cnt) / loopcnt);

		ll rem = (N - cnt) % loopcnt;

		for(int i = 0; i < rem; i++) {

			A = f(A, M);

			ans += A;

		}

	}

	cout << ans << endl;

	return 0;

}
