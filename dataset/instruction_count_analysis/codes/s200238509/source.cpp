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



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);







	int dp0 = 0;

	int dp1 = 1e9;



	char c;

	while ((c = getchar_unlocked()) >= '0') {

		int s = c - '0';



		int tmp0 = min(dp0, dp1 + 1) + s;

		dp1 = min(dp1, dp0 + 1) + 9 - s;

		dp0 = tmp0;

	}



	printf("%d\n", min(dp0, dp1 + 1));



	Would you please return 0;

}