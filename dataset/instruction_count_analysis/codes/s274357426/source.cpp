#include <iostream>

using namespace std;

int n, c, a[100005];

int main() {

	int i;

	scanf("%d", &n);

	if(n==1) {puts("1"); return 0;}

	for(i=0; i<n; i++) scanf("%d", &a[i]);

	for(i=1; i<n; i++) {

		if(a[i] - a[i-1] > 0) {

			c++;

			for(; a[i] - a[i-1] >= 0; i++);

		} else if(a[i] - a[i-1] < 0) {

			c++;

			for(; a[i] - a[i-1] <= 0; i++);

		}

		if(i==n-1) c++;

	}

	printf("%d", c);

	return 0;

}