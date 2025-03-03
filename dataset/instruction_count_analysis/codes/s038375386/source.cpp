#include <iostream>

#include <cstdio>

#include <algorithm>

using namespace std;

int n, a[100005];

double m;

int main() {

	int i, k;

	scanf("%d", &n);

	for(i=0; i<n; i++) scanf("%d", &a[i]);

	sort(a, a+n);

	m = a[n-1] / 2.0;

	k = lower_bound(a, a+n, m) - a;

	if(m-a[k-1]<=a[k]-m) printf("%d %d", a[n-1], a[k-1]);

	else printf("%d %d", a[n-1], a[k]);

	return 0;

}