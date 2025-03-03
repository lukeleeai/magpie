#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

const int MAXS = 1 << 16;

const int MAXN = 1e5 + 5;

int dp[MAXS] , n , S , a[MAXN];

int DP(int now) {

	if(now == 0) return 0;

	if(dp[now] != -1) return dp[now];

	dp[now] = 1e9;

	for (int i = 0; i < 15; ++i) {

		if(!(now & (1 << i))) continue;

		for (int j = i + 1; j < 15; ++j) {

			if(!(now & (1 << j))) continue;

			int nnow = now ^ (1 << i) ^ (1 << j) ^ (1 << (((i+1) ^ (j+1)) - 1));

//			if(now == 7) printf("%d %d %d\n" , nnow);

			int f;

			if(((now ^ (1 << i) ^ (1 << j)) & (1 << (((i+1) ^ (j+1)) - 1)))) f = 1;

			else f = 0;

			dp[now] = min(dp[now] , DP(nnow) + 1 + f);

		}

	}

	return dp[now];	

}

int main() {

	scanf("%d" , &n);

	for (int i = 1; i < n; ++i) {

		int u , v , w;

		scanf("%d %d %d" , &u , &v , &w);

		a[u] ^= w;

		a[v] ^= w;

	}

	int ans = 0;

	for (int i = 0; i < n; ++i) {

//		printf("%d\n" , a[i]);

		if(!a[i]) continue;

		if(S & (1 << (a[i] - 1))) ans ++;

		S ^= (1 << (a[i] - 1));

	} 

//	printf("%d " , S);

	memset(dp , -1 , sizeof dp);

	dp[0] = 0;

	ans += DP(S);

//	for (int now = 1; now < (1 << 15); ++now) {

//		for (int i = 0; i < 15; ++i) {

////			if(!(now & (1 << i))) continue;

//			for (int j = i + 1; j < 15; ++j) {

////				if(!(now & (1 << j))) continue;

//				int nnow = now ^ (1 << i) ^ (1 << j) ^ (1 << (((i+1) ^ (j+1)) - 1));

////				if(now == 7) printf("%d %d %d\n" , nnow);

//				dp[now] = min(dp[now] , dp[nnow] + 1 + ((now ^ (1 << i) ^ (1 << j)) & (1 << (((i+1) ^ (j+1)) - 1))));

//			}

//		}

//	}

	printf("%d" , ans);

	return 0;

}