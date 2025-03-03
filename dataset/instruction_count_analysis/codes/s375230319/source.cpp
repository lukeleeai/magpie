#include <cstdio>

#include <cstring>

#define fail return puts("-1"), 0



const int N = 1e5 + 5;



char s[N];



int main() {

	scanf("%s", s + 1);

	int n = strlen(s + 1);

	if (s[1] == '0' || s[n] == '1') fail;

	for (int i = 1; i < n; i++) {

		if (s[i] != s[n - i]) fail;

	}

	for (int i = 2, r = 1; i <= n; i++) {

		printf("%d %d\n", r, i);

		if (s[i - 1] == '1') r = i;

	}

	return 0;

}