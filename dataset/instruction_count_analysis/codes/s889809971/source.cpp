#include <cstdio>



const int MAXN = 1E5 + 10;



int n;

char s[MAXN];

int a[MAXN];



int main(){

	scanf("%d", &n);

	scanf("%s", s);

	s[n] = s[0], s[n + 1] = s[1];



	for (int i = 0; i < 4; ++i){

		a[0] = i & 1, a[1] = i >> 1 & 1;

		for (int j = 2; j <= n + 1; ++j)

			a[j] = s[j - 1] == 'x' ^ a[j - 1] ^ a[j - 2];

		if (a[0] == a[n] && a[1] == a[n + 1]){

			for (int j = 0; j < n; ++j)

				putchar(a[j] ? 'W' : 'S');

			puts("");

			return 0;

		}

	}

	puts("-1");

	return 0;

}
