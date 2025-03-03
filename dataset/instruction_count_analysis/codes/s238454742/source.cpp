#include<cstdio>

#include<algorithm>

int n, k;

long long ans;

long long c[200010], val[200010], sum[200010];



inline void add(long long x, long long y){

	for(;x <= n;x += x & -x) c[x] += y;

}



inline long long ask(long long x){

	long long ans = 0;

	for(;x;x -= x & -x) ans += c[x];

	return ans;

}



int main(){

	scanf("%d %d", &n, &k);

	for(int i = 1;i <= n;++i){

		scanf("%lld", &val[i]);

		val[i] -= k; 

	}

	for(int i = 1;i <= n;++i){

		sum[i] = (val[i] += val[i - 1]);

		if (sum[i] >= 0) ++ans;

	}

	std::sort(sum + 1, sum + 1 + n);int t = std::unique(sum + 1, sum + 1 + n) - (sum + 1);

	for(int i = 1;i <= n;++i) val[i] = std::lower_bound(sum + 1, sum + 1 + t, val[i]) - sum;

	for(int i = 1;i <= n;++i){

		ans += ask(val[i]);add(val[i], 1);

	}

	printf("%lld\n", ans);

	return 0;

}

/*

对区间[l, r] average = (sum[r] - sum[l - 1]) / (r - l + 1) >= k

等价于sum[r]-r*k>=sum[l-1]-(l-1)*k

*/