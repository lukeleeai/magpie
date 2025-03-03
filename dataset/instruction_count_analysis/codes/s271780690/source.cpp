#include "stdc++.h"



using namespace std;



long long mat[505][505];



long long gcd(long long a,long long b)

{

	return b ? gcd(b,a % b) : a;

}



long long lcm(long long a,long long b)

{

	if(!b || !a) return a + b;

	return a / gcd(a,b) * b;

}



int primes[1050];



void sieve()

{

	int cnt = 0;

	for(int i = 2;cnt <= 1020; ++ i)

	{

		int flg = 0;

		for(int j = 2;j * j <= i; ++ j)

			if(i % j == 0)

			{

				flg = 1;

				break;

			}

		if(!flg) primes[++ cnt] = i;

	}

}



int main()

{

	sieve();

	int n; scanf("%d",&n);

	for(int i = 0;i <= n + 1; ++ i)

		for(int j = 0;j <= n + 1; ++ j)

			mat[i][j] = 1;

	for(int i = 0;i <= n + 1; ++ i)

		for(int j = 0;j <= n + 1; ++ j)

			if((i + j) % 2 == 0)

				mat[i][j] *= primes[(i + j) / 2 + 1],mat[i][j] *= primes[(i + (n - j + 1)) / 2 + (n + 1)];

//	long long maxn = 0;

	for(int i = 1;i <= n; ++ i,printf("\n"))

		for(int j = 1;j <= n; ++ j)

		{

			if((i + j) % 2 == 1)

				mat[i][j] = 1 + lcm(lcm(mat[i - 1][j],mat[i][j - 1]),lcm(mat[i + 1][j],mat[i][j + 1]));

			printf("%lld ",mat[i][j]);

		//	maxn = max(maxn,mat[i][j]);

		}

//	cout << maxn << endl;

	return 0;

}