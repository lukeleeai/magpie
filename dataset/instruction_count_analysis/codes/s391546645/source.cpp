#include <cstdio>



int pri[101000], tot = 0;

bool is[101000];



void init()

{

	for(int i = 2; i <= 100000; i++)

	{

		if(!is[i]) pri[++tot] = i;

		for(int j = 1; j <= tot && i * pri[j] <= 100000; j++)

		{

			is[i * pri[j]] = 1;

			if(i % pri[j] == 0) break;

		}

	}

}

long long m[1010][1010];



long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);} 

void lcm(long long &a, long long b)

{

	a = a / gcd(a, b) * b; 

}

int main()

{

	int n; scanf("%d", &n);

	if(n == 2)

	{

		printf("4 7\n23 10");

		return 0;

	}

	init();

	int j = 2;

	for(int i = 2; i <= 2 * n; i += 2)

	{

		for(int k = 0; k <= n; k++)

		{

			if(k + 1 >= 1 && k + 1 <= n && i - k >= 1 && i - k <= n) m[k + 1][i - k] = pri[j];

		}

		j++;

	}

	

	for(int i = (n / 2 * 2); i >= - n; i -= 2)

	{

		for(int k = 0; k <= n; k++)

		{

			if(k + 1 >= 1 && k + 1 <= n && i + k >= 1 && i + k <= n) m[k + 1][i + k] *= pri[j];

		}

		j++;

	}

	for(int i = 1; i <= n; i++)

		for(int j = 1; j <= n; j++)

		{

			if(!m[i][j])

			{

				m[i][j] = 1;

				if(i != 1) lcm(m[i][j], m[i - 1][j]);

				if(j != 1) lcm(m[i][j], m[i][j - 1]);

				if(i != n) lcm(m[i][j], m[i + 1][j]);

				if(j != n) lcm(m[i][j], m[i][j + 1]);

				m[i][j]++;

			}

		}

	for(int i = 1; i <= n; i++, puts(""))

		for(int j = 1; j <= n; j++) printf("%lld ",m[i][j]);

	return 0;

}