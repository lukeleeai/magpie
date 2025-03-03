#include"stdc++.h"

#define rep(i,n)for(int i=0;i<n;i++)

using namespace std;



bool is_prime[100000];

double prime[10000];



int main() {

	memset(is_prime, 1, sizeof(is_prime));

	is_prime[0] = is_prime[1] = false;

	int p = 0;

	for (int i = 2; i < 100000; i++) {

		if (is_prime[i]) {

			prime[p++] = i;

			for (int j = i * 2; j < 100000; j += i)is_prime[j] = false;

		}

	}

	int m; double a, b;

	while (scanf("%d%lf%lf", &m, &a, &b), m) {

		int Max = 0, P, Q;

		for (int i = 0; prime[i] * 2 <= m; i++) {

			int j = upper_bound(prime, prime + p, prime[i] / a*b) - prime - 1;

			int k = upper_bound(prime, prime + p, m / prime[i]) - prime - 1;

			j = min(j, k);

			if (j < 0)continue;

			if (Max < prime[i] * prime[j] && prime[j] / (double)prime[i] >= a / b) {

				Max = prime[i] * prime[j]; P = prime[i]; Q = prime[j];

			}

		}

		printf("%d %d\n", P, Q);

	}

}