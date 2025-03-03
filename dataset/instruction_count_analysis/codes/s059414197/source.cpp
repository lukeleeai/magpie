#include <cstdio>

#include <cstring>

char s[1000009], t[1000009]; int c[1000009];

int main() {

	scanf("%s", s);

	int n = strlen(s);

	int p = 0, z = 0;

	for (int i = 1; s[i - 1]; i++) {

		if (s[i] != s[i - 1]) {

			t[z] = s[i - 1];

			c[z] = i - p;

			p = i; z++;

		}

	}

	int ret = 0;

	for (int i = 1; i < z - 1; i++) {

		if (t[i - 1] != 'J' || t[i] != 'O' || t[i + 1] != 'I') continue;

		if (c[i - 1] < c[i] || c[i] > c[i + 1]) continue;

		if (ret < c[i]) ret = c[i];

	}

	printf("%d\n", ret);

	return 0;

}