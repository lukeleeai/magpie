#include "stdc++.h"

using namespace std;

#define MAXN 100

#define MAXV 1000

#define MAXW 1000000000

#define INF 10000000000000LL





int w[MAXN], v[MAXN];

int n,C;

long long dp[MAXN*MAXV+1];

int totalV;



int main() {

	int i,j;

	scanf("%d %d",&n, &C);	

	for (totalV=i=0; i<n;i++) {

		scanf("%d %d",&w[i],&v[i]);

		totalV += v[i];

	}

	dp[0]=0;

	for (i=1; i<=totalV;i++) {

		dp[i]=INF;

	}



	for (i=0; i<n; i++) {

		for (j=totalV; j>=v[i]; j--) {

			dp[j]=min(dp[j], dp[j-v[i]]+w[i]);

		}

	}

	for (i=totalV;  i>=0;i--) {

		if (dp[i]<= C) break;

	}

	printf("%d\n", i);

	return 0;

}


