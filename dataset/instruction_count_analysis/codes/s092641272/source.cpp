#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

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



//ソートすればいいんですか？

//???

int dp[3000];



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N, T;

	scanf("%d", &N);

	scanf("%d", &T);

	int AB[3000];

	rep(i, N) {

		int a, b;

		scanf("%d %d", &a, &b);

		AB[i] = (a << 12) + b;

	}

	sort(AB, AB + N);



	int saidai = 0;

	rep(i, N) {

		int a = AB[i] >> 12;

		int b = AB[i] & ((1 << 12) - 1);

		chmax(saidai, dp[T - 1] + b);

		for (int j = T - a - 1; j >= 0; j--) {

			chmax(dp[j + a], dp[j] + b);

		}

	}

	printf("%d", saidai);



	Would you please return 0;

}