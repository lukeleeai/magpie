#include <cstdio>

#include <cstring>



char arr[100010];

int prv[100010];



int main() {

	scanf("%s", arr + 1);

	int n = strlen(arr + 1);

	if (arr[1] == '0' || arr[n] == '1') {

		puts("-1");

		return 0;

	}

	for (int i = n - 1; i; --i)

		if (arr[i] != arr[n - i]) {

			puts("-1");

			return 0;

		

		}

	int pos = 1;

	for (int i = 2; i < n; ++i)

		if (arr[i] == '1') {

			prv[i] = pos;

			pos = i;

		}

	int ct = 1, pp = n, cur = 1;

	for (int i = pos; i; i = prv[i]) {

		int nx = ct;

		for (int j = i; j < pp; ++j) {

			printf("%d %d\n", cur, ++ct);

		}

		cur = nx + 1;

		pp = i;

	}

	return 0;

}
