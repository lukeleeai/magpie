#include <cstdio>

#include <algorithm>

using namespace std;

#define LL long long

#define MAX_SIZE 1010

int n, m;

LL r, a;

LL x[MAX_SIZE], y[MAX_SIZE], z[MAX_SIZE], t[MAX_SIZE];



int main()

{

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)

		scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);



	int P[8][3] = { { 1,1,1 },{ 1,1,-1 },{ 1,-1,1 },{ 1,-1,-1 },{ -1,1,1 },{ -1,1,-1 },{ -1,-1,1 },{ -1,-1,-1 } };

	for (int i = 0; i < 8; ++i) {

		for (int j = 0; j < n; ++j)

			t[j] = x[j] * P[i][0] + y[j] * P[i][1] + z[j] * P[i][2];

		sort(t, t + n);

		a = 0;

		for (int k = n - m; k < n; ++k)

			a += t[k];

		if (r < a)

			r = a;

	}

	printf("%lld\n", r);

	return 0;

}