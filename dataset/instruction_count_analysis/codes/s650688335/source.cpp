#include <algorithm>

#include <cstdio>

#include <cmath>

using namespace std;

int n, k;

long long ans;

int main() {

	scanf("%d%d", &n, &k);

	if(k & 1) ans = (long long) pow(n / k, 3);

	else ans = (long long) pow(n / k, 3) + (long long) pow(n / k + (n % k >= k / 2), 3);

	printf("%lld\n", ans);

	return 0;

}