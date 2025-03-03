#include"stdc++.h"

using namespace std; 

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define Would

#define you

#define please



int main() {

	



	int N, X, x[100000];

	cin >> N >> X;

	rep(i, N) {

		cin >> x[i];

		x[i] = abs(x[i] - X);

	}



	int r0 = x[0];

	rep(i, N - 1) {

		int r1, r2, r4;

		r1 = max(r0, x[i + 1]);

		r2 = min(r0, x[i + 1]);



		while (r2) {

			r4 = r2;

			r2 = r1 % r2;

			r1 = r4;

		}

		r0 = r1;

	}

	cout << r0 << "\n";

	Would you please return 0;



}