#pragma GCC optimize ("Ofast")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<cstdio>

#include<cstring>

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



char S[200005];



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	fread(S, 1, 200005, stdin);

	int L = 0, R = 200005;

	while (L + 1 < R) {

		int M = (L + R) / 2;

		if (S[M] >= '0') L = M;

		else R = M;

	}



	int N = R;

	int a = 0;

	int A[2020] = {};

	A[0] = 1;



	ll kotae = 0;

	int tmp = 0;

	int are = 1;

	int shou = N / 5;

	int i = N - 1;

	int amari = N % 5;

	rep(j, shou) {

		tmp += (S[i--] - '0') * are;

		tmp %= 2019;

		kotae += A[tmp]++;

		are *= 10;



		tmp += (S[i--] - '0') * are;

		tmp %= 2019;

		kotae += A[tmp]++;

		are *= 10;



		tmp += (S[i--] - '0') * are;

		tmp %= 2019;

		kotae += A[tmp]++;

		are *= 10;



		tmp += (S[i--] - '0') * are;

		tmp %= 2019;

		kotae += A[tmp]++;

		are *= 10;



		tmp += (S[i--] - '0') * are;

		tmp %= 2019;

		kotae += A[tmp]++;

		are *= 10;

		are %= 2019;

	}

	rep(j, amari) {

		tmp += (S[i--] - '0') * are;

		tmp %= 2019;

		kotae += A[tmp]++;

		are *= 10;

	}



	printf("%lld\n", kotae);





	Would you please return 0;

}