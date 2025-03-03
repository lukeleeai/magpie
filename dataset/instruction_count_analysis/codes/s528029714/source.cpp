#include <cstdio>

#include <algorithm>

using namespace std;



long long n, k, a[100005];

int main() {

	int i;

	scanf("%d", &n);

	for(i=1; i<=n; i++) scanf("%d", &a[i]);

	sort(a+1, a+n+1);

	for(i=1; i<n-1; i++) {

		a[i] += a[i-1];

		if(a[i]*2 < a[i+1]) k = i;

	}

	printf("%d", n-k);

	return 0;

}
