#include <cstring>

#include <iostream>

#include <vector>

#include <map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

typedef long long int64;

int P[400000];

int M[200000];



int main() {

	memset(P, 0, sizeof(P));

	memset(P, 0, sizeof(M));

	int N;

	cin >> N;

	int tmp;

	int64 ans = 0;

	for (int i = 0; i < N; ++i) {

		cin >> tmp;

		if (tmp < 200000) {

			++P[i+tmp];

			if (i-tmp > 0) ++M[i-tmp];

		}

	}

	for (int i = 1; i < N; ++i) {

		ans += (int64)P[i] * M[i];

	}

	cout << ans << "\n";

	return 0;

}
