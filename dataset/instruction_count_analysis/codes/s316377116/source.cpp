#include <cstdio>



const int MN = 200005;



int N, A[MN];



int stkp[MN], stkv[MN], tp;

inline bool check(int M) {

	tp = 0;

	for (int i = 1; i <= N; ++i) {

		if (A[i] <= A[i - 1]) {

			while (stkp[tp] > A[i]) --tp;

			int pos = A[i];

			while (pos) {

				if (stkp[tp] != pos || stkv[tp] != M - 1) {

					if (stkp[tp] != pos)

						stkp[++tp] = pos,

						stkv[tp] = 0;

					++stkv[tp];

					break;

				} else --tp, --pos;

			}

			if (!pos) return 0;

		}

	}

	return 1;

}



int main() {

	int ok = 1;

	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {

		scanf("%d", &A[i]);

		if (A[i] <= A[i - 1]) ok = 0;

	}

	if (ok) return puts("1"), 0;

	int lb = 2, rb = N, mid = 0, ans = 0;

	while (lb <= rb) {

		mid = (lb + rb) >> 1;

		if (check(mid)) ans = mid, rb = mid - 1;

		else lb = mid + 1;

	}

	printf("%d\n", ans);

	return 0;

}