#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<algorithm>

using namespace std;

#define maxn 1005

#define INF ((ll)(1e18)+1)

typedef long long ll;

int T[maxn], A[maxn];

int main(void)

{

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)

		scanf("%d %d", &T[i], &A[i]);

	ll t = T[0], a = A[0];

	for (int i = 1; i < n; i++)

	{

		if (T[i] >= t && A[i] >= a) {

			t = T[i], a = A[i];

			continue;

		}

		ll k = max(t / T[i], a / A[i]);

		if (k < 1)k = 1;

		while (T[i] * k < t || A[i] * k < a)

			k++;

		t = T[i] * k, a = A[i] * k;

	}

	printf("%lld\n", t + a);

	return 0;

}