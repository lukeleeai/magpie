#include<cstdio>



using namespace std;



typedef long long ll;



ll x, y;



int main() {

	scanf("%lld %lld", &x, &y);

	if (x == y) {

		printf("-1\n");

		return 0;

	}

	for (int i = 1; i < y; i++) {

		if ((x * i) % y) {

			printf("%lld\n", x * i);

			return 0;

		}

	}

	printf("-1\n");

	return 0;

}