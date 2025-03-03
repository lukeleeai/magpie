#include <cstdio>

int n, a, b, c, x;

int main() {

	scanf("%d%d", &n, &a);

	for(int i=1; i<n; i++) {

		scanf("%d", &b);

		if(b==a) continue;

		if(x) {if(x==1 && b<a || x==-1 && b>a) x=0, c++;}

		else x = b>a ? 1:-1;

		a = b;

	}

	printf("%d", c+1);

	return 0;

}