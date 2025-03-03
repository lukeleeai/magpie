#include <cstdio>



using namespace std;



int N;

int A[110000];



int main () {

	scanf ("%d", &N);

	for (int i = 0; i < N; i++) scanf ("%d", &A[i]);

	int ans = 1, pos = A[1] - A[0];

	for (int i = 2; i < N; i++) {

		if (pos == 0) pos = A[i] - A[i - 1];

		if (1LL * pos * (A[i] - A[i - 1]) < 0) {

			ans++;

			pos = 0;

		}

	}

	printf ("%d\n", ans);

}


