#include <stdio.h>

#include <algorithm>

using namespace std;

int N, Q, L, R; unsigned long long h, v[300002], p[300002], sum[300002]; char str[300002], com[5];

int main() {

	scanf("%d %d %s", &N, &Q, str); R = 1, p[0] = 1, sum[0] = 0;

	for(int i = 1; i < N; i++) p[i] = p[i - 1] * 257;

	for(int i = 1; i <= N; i++) sum[i] = sum[i - 1] * 257 + str[i - 1];

	for(int i = 0; i < Q; i++) {

		scanf("%s", com);

		switch(com[0] + com[1]) {

			case 119: L++; break;

			case 121: L--; break;

			case 125: R++; break;

			case 127: R--; break;

		}

		v[i] = sum[R] - sum[L] * p[R - L];

	}

	sort(v, v + Q);

	int ret = 1;

	for(int i = 1; i < Q; i++) {

		if(v[i - 1] != v[i]) ret++;

	}

	printf("%d\n", ret);

	return 0;

}