#include <cstdio>

#include <algorithm>

using namespace std;

int n, a[100005];

int main() {

	int i;

	scanf("%d", &n);

	for(i=0; i<n; i++) scanf("%d", &a[i]);

	sort(a, a+n);

	for(i=0; 2*a[i]<a[n-1]; i++);

	printf("%d %d", a[n-1], a[n-1]-2*a[i-1] <= 2*a[i]-a[n-1] ? a[i-1] : a[i]);

	return 0;

}