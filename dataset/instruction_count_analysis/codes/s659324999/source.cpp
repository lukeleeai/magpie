#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

using namespace std;

const int SIZEN = 100010;

typedef long long LL;

int N;

LL a[SIZEN] = {0};

int main(){

	scanf("%d",&N);

	for(int i = 1;i <= N;i++)scanf("%lld",&a[i]);

	sort(a + 1,a + 1 + N);

	LL ans = 0;

	if(a[1] >= 0){

		for(int i = 2;i <= N;i++)ans += a[i];

		ans -= a[1];

		printf("%lld\n",ans);

		for(int i = 2;i < N;i++){

			printf("%lld %lld\n",a[1],a[i]);

			a[1] -= a[i];

		}

		printf("%lld %lld\n",a[N],a[1]);

	}

	else if(a[N] <= 0){

		for(int i = 1;i < N;i++)ans += a[i];

		ans = a[N] - ans;	

		printf("%lld\n",ans);

		for(int i = 1;i < N;i++){

			printf("%lld %lld\n",a[N],a[i]);

			a[N] -= a[i];

		}

	}

	else{

		for(int i = 1;i <= N;i++)ans += abs(a[i]);

		printf("%lld\n",ans);

		for(int i = 2;i < N;i++){

			if(a[i] < 0)printf("%lld %lld\n",a[N],a[i]),a[N] -= a[i];

			else printf("%lld %lld\n",a[1],a[i]),a[1] -= a[i];

		}

		printf("%lld %lld\n",a[N],a[1]);

	}

	return 0;

} 