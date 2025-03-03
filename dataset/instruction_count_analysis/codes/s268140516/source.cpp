#include <algorithm>

#include <cstdio>

using namespace std;



int main() {

	int n, x; scanf("%d%d", &n, &x);

	if(x == 1 || x == 2 * n - 1) return puts("No"), 0;

	puts("Yes"); int t = 1;

	for(int i = 1; i < n - 1; i ++) {

		while(abs(t - x) <= 1) t ++;

		printf("%d\n", t ++);

	}

	printf("%d\n%d\n%d\n", x - 1, x, x + 1);

	for(int i = n + 2; i < 2 * n; i ++) {

		while(abs(t - x) <= 1) t ++;

		printf("%d\n", t ++);

	}

	return 0;

}
