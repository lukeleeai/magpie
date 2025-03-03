#include <cstdio>

typedef long long LL;



const int mod = 1e9 + 7;

LL p[1010];



void getp(int x) {

	for(int i = 2; i * i <= x; ++i) {

		if(x % i == 0) {

			while(x % i == 0) {

				p[i]++;

				x /= i;

			}

		}

	}

	if(x > 1) p[x]++;

}



int main() {

	int n;

	scanf("%d", &n);

	for(int i = 2; i <= n; ++i) {

		getp(i);

	}

	LL sum = 1;

	for(int i = 1; i <= n; ++i) {

		sum = (sum * (p[i] + 1)) % mod;

	}

	printf("%lld\n", sum);

	return 0;

}