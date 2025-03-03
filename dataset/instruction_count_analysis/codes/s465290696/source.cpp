#include <cstdio>

#include <vector>

using namespace std;



using i64 = long long;



#define REP(i, stop) for (int i = 0, i##_len = stop; i < i##_len; ++i)



signed main() {

	i64 n;

	scanf("%lld", &n);

	vector<i64> A(n + 1), B(n);

	REP(i, n + 1) {

		scanf("%lld", &A[i]);

	}

	REP(i, n) {

		scanf("%lld", &B[i]);

	}

	i64 s = 0;

	REP(i, n) {

		i64 m = A[i] < B[i] ? A[i] : B[i];

		s += m;

		B[i] -= m;

		m = A[i + 1] < B[i] ? A[i + 1] : B[i];

		s += m;

		A[i + 1] -= m;

	}

	printf("%lld", s);

}
