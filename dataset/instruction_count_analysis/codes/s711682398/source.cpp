#include<stdio.h>

#include<stdlib.h>

#include<math.h>

typedef long long ll;

bool isPrime(ll n);

int count(ll n);

int main(void)

{

	ll n;

	scanf("%lld", &n);

	if (isPrime(n))

		printf("%d\n", count(n));

	else

	{

		for (int i = sqrt(n); i >= 1; i--)

			if (n % i == 0) {

				int a = count(i), b = count(n / i);

				printf("%d\n", a > b ? a : b);

				break;

			}

	}

	return 0;

}

bool isPrime(ll n)

{

	if (n < 5)return n == 2 || n == 3 ? true : false;

	if ((n + 1) % 6 != 0 && (n - 1) % 6 != 0)return false;

	if (n % 2 == 0)return false;

	for (int i = 3; i <= sqrt(n); i += 2)

		if (n % i == 0)

			return false;

	return true;

}

int count(ll n)

{

	int cnt = 0;

	while (n)

		n /= 10, cnt++;

	return cnt;

}