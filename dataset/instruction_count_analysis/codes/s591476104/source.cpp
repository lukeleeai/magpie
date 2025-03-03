#include <cstdio>



int main() {

	char str[110][110];

	int n, m;

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i)

		scanf("%s", str[i]);

	for (int i = 0; i < n; ++i)

		puts(str[i]), puts(str[i]);

	return 0;

}
