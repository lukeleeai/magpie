#include <cstdio>

#define N 100010

using namespace std;



int n, a, t[N];



inline void ef(int a) {

	int l = 1, r = t[0];

	while (l <= r) {

		int mid = (l + r) >> 1;

		if (t[mid] < a)

			r = mid - 1;

		else

			l = mid + 1;

	}

	t[l] = a;

}



int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {

		scanf("%d", &a);

		if (i == 1)

			t[++t[0]] = a;

		else if (a <= t[t[0]])

			t[++t[0]] = a;

		else

			ef(a);

	}

	printf("%d", t[0]);

	return 0;

}
