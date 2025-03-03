#include <iostream>

#include <cstdio>

long long n, s, t, a[100005], b[100005];

int main() {

	int i;

	scanf("%lld", &n);

	for(i=1; i<=n; i++) scanf("%lld", &a[i]), b[i]=a[i];

	for(i=1; i<=n; i++) {

		a[i] += a[i-1];

		if(i%2) {

			if(a[i]<=0) s += 1-a[i], a[i]=1;

		} else {

			if(a[i]>=0) s += a[i]+1, a[i]=-1;

		}

	}

	for(i=1; i<=n; i++) {

		b[i] += b[i-1];

		if(i%2) {

			if(b[i]>=0) t += b[i]+1, b[i]=-1;

		} else {

			if(b[i]<=0) t += 1-b[i], b[i]=1;

		}

	}

	printf("%lld", std::min(s,t));

	return 0;

}