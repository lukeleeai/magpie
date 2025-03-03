#include <cstdio>

#include <algorithm>

using namespace std;



int arr[100010];

int cta[100010], ctb[100010];



int main() {

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)

		scanf("%d", arr + i);

	for (int i = 0; i < n; ++i) {

		if (i % 2) ++ctb[arr[i]];

		else ++cta[arr[i]];

	}

	int mx1 = 0, mx2 = 0;

	for (int i = 1; i <= 100000; ++i)

		if (cta[i] > cta[mx1])

			mx1 = i;

	for (int i = 1; i <= 100000; ++i)

		if (ctb[i] > ctb[mx2])

			mx2 = i;

	if (mx1 != mx2)

		printf("%d\n", n - cta[mx1] - ctb[mx2]);

	else {

		int smx1 = 0, smx2 = 0;

		for (int i = 1; i <= 100000; ++i)

			if (i != mx1 && cta[i] > cta[smx1])

				smx1 = i;

		for (int i = 1; i <= 100000; ++i)

			if (i != mx2 && ctb[i] > ctb[smx2])

				smx2 = i;

		printf("%d\n", min(n - cta[mx1] - ctb[smx2], n - cta[smx1] - ctb[mx2]));

	}

	return 0;

}
