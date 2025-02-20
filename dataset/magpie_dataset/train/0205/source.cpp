#include<cstdio>

#include<algorithm>

using namespace std;

typedef long long int ll;

static const int MAX_N = 2000;



int N;

ll A[MAX_N];

ll memo[MAX_N][2 * MAX_N];



ll memoize(int i, int j){

	if(memo[i][j] != -1) return memo[i][j];

	int i2 = (i == N - 1 ? 0 : i + 1);

	int j2 = (j == 0 ? N - 1 : j - 1);

	int itv = (i > j ? N + j - i : j - i);

	if((N - itv) % 2 == 1){

		if(i == j) return memo[i][j] = A[i];

		else return memo[i][j] = max(memoize(i2, j) + A[i], memoize(i, j2) + A[j]);

	}else{

		if(i == j) return memo[i][j] = 0LL;

		else if(A[i] > A[j]) return memo[i][j] = memoize(i2, j);

		else return memo[i][j] = memoize(i, j2);

	}

	return 0;

}



int main(){

	scanf("%d", &N);

	for(int i = 0; i < N; i++) scanf("%lld", &A[i]);

	fill(memo[0], memo[N], -1);

	for(int i = 0; i < N; i++){

		for(int j = 0; j < N; j++){

			memo[i][j] = memoize(i, j);

		}

	}

	ll res = 0LL;

	for(int i = 0; i < N; i++){

		for(int j = 0; j < N; j++){

			res = max(res, memo[i][j]);

		}

	}

	printf("%lld\n", res);

	return 0;

}


