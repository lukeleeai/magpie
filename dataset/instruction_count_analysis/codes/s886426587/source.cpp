#include <cstdio>

long long n, s, x, y, a[100005];

int main() {

	int i;

	scanf("%lld", &n);

	for(i=0; i<n; i++) scanf("%lld", &a[i]);

	for(i=0; i<n; i++) {

		s += a[i];

		if(i%2) {

			if(s<=0) x += 1-s, s=1;

		} else {

			if(s>=0) x += s+1, s=-1;

		}

	}

	for(i=s=0; i<n; i++) {

		s += a[i];

		if(i%2) {

			if(s>=0) y += s+1, s=-1;

		} else {

			if(s<=0) y += 1-s, s=1;

		}

	}

	printf("%lld", x<y ? x:y);

	return 0;

}