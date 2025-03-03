//想的时间太长了，打表不能一下找到规律的话，还是手推吧，不要浪费时间 

//用long long！！ 

#include <cstdio>

#include <cstring>

long long k, ans, x, y, n, m;



int main(){

	//freopen("atcoderarc091b.out", "w", stdout);

	scanf("%lld%lld", &n, &k);

	if (k == 0){

		printf("%lld", n * n);

		return 0;

	}

	ans = 0;

	ans += (n - k) * (n - k + 1) / 2;

	//printf("%d\n", ans);

	for (int i=k+1; i<=n-1; i++){

		x = n / i;

		y = n % i;

		ans += (x - 1) * (i - k);

		if (y >= k) ans += y - k + 1;

	} 

	printf("%lld", ans);

	

	//以下为打表找规律（其实最后也没找到，还是手推的） 

	/*n = 100;

	for (int i=1; i<=n; i++){

		for (int j=0; j<=i-1; j++){

			ans = 0;

			for (int a=1; a<=i; a++){

				for (int b=1; b<=i; b++) 

					if (a % b >= j) ans++;

			}

			printf("%d %d %d\n", i, j, ans); 

			//ans = 0;

		}

	}*/

	

	return 0;

} 