#include<stdio.h>

int a[121212];

int main() {

	int n, i, j, k, ans = 0; scanf("%d", &n);

	for (i = 0; i < n; i++)scanf("%d", &a[i]);

	for (i = 0; i < n; ) {

		for (j = i + 1; j < n&&a[j - 1] <= a[j]; j++);

		for (k = i + 1; k < n&&a[k - 1] >= a[k]; k++);

		i = (j > k ? j : k);

		ans++;

	}

	printf("%d", ans);

	return 0;

}