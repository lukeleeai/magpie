#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<cmath>

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define pb push_back

#define mp make_pair

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

#define Would

#define you

#define please





int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	ll N;

	scanf("%lld", &N);



	int sq = sqrt(N);

	ll saishou = 1e18;

	for (int i = sq; i >= 1; i--) {

		if ((ll)((double)N / i) * i == N) {

			printf("%lld", N / i + i - 2);

			return 0;

		}

	}



	Would you please return 0;

}