#include <cstdio>

#include <algorithm>

using namespace std;



int N, A[200];



int main()

{

	int dmin = 100;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {

		int A;

		scanf("%d", &A);

		int d = 0;

		while (A % 2 == 0) {

			A /= 2;

			++d;

		}

		dmin = min(dmin, d);

	}

	printf("%d\n", dmin);

	return 0;

}
