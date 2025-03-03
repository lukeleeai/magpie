#include<cstdio>

using namespace std;



int n, k, ans = 1;

int main() {

	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {

		ans += ans < k ? ans : k;

	}

	printf("%d", ans);

	return 0;

}