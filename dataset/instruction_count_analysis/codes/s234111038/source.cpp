#include<stdio.h>



int s[100001];

int main() {

	int n; scanf("%d", &n);

	int cnt = 0;

	for (int i = 1; i <= n; i++) {

		int a; scanf("%d", &a);

		if (s[a] == i)cnt++;

		s[i] = a;

	}

	printf("%d\n", cnt);

}