#include<cstdio>

const int maxn = 2e6 + 5;

long long a[maxn];

int main(){

	int n ;

	long long m ;

	scanf("%d%lld",&n,&m);

	for(int i = 1;i <= n;i++){

		scanf("%lld",&a[i]);

		}

	long long sum = m;

	for(int i = n;i > 1;i--){

		if(a[i] - a[i - 1] >= m)sum += m;

		else sum += a[i] - a[i - 1];

		}

	printf("%lld\n",sum);

	return 0;

}