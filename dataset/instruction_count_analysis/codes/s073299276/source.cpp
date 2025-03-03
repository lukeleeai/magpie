#include <stdio.h>

int n, m, x, s[100];

int main() {

	while(scanf("%d%d", &n, &m), n + m) {

		for(int i = 0; i < m; i++) scanf("%d", s + i);

		for(int i = 0; i < n; i++) {

			for(int j = 0; j < m; j++) scanf("%d", &x), s[j] -= x;

		}

		int f = 1;

		for(int i = 0; i < m; i++) {

			if(s[i] < 0) f = 0;

		}

		puts(f ? "Yes" : "No");

	}

}