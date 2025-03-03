#include<cstdio>

#include<algorithm>

using namespace std;

const int MAXN = 2 * int(1E5);

struct node{

	int A, B;

}a[MAXN + 5];

int main() {

	int N;

	scanf("%d", &N);

	bool flag = true;

	long long Sum = 0, Min = (1ll << 60);

	for(int i=1;i<=N;i++) {

		scanf("%d%d", &a[i].A, &a[i].B);

		if( a[i].A > a[i].B )

			Min = min(Min, 1ll*a[i].B);

		if( a[i].A != a[i].B )

			flag = false;

		Sum += a[i].A;

	}

	if( flag ) {

		printf("0\n");

		return 0;

	}

	printf("%lld", Sum - Min);

}
