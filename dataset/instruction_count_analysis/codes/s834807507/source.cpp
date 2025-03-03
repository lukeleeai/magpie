#include "stdc++.h"



using namespace std;



const int N = 1e5 + 10;



int n, m;

char s[N], t[N];

map<long long, char> Map;



int main()

{

	scanf("%d%d", &n, &m);

	scanf("%s", s + 1);

	scanf("%s", t + 1);

	if(s[1] != t[1])

	{

		puts("-1");

		return 0;

	}

	if(n % m == 0)

	{

		int flag = 1;

		for(int i = 1; i <= m; i++)

			if(t[i] != s[1ll * (i - 1) * n / m + 1])flag = 0;

		if(!flag)

		{

			puts("-1");

		}

		else printf("%d\n", n);

		return 0;

	}

	if(m % n == 0)

	{

		int flag = 1;

		for(int i = 1; i <= n; i++)

			if(s[i] != t[1ll * (i - 1) * m / n + 1])flag = 0;

		if(!flag) 	

		{

			puts("-1");

		}

		else printf("%d\n", m);

		return 0;

	}

	long long nowans = 1ll * n * m / __gcd(n, m);

	for(int i = 1; i <= n; i++)

		Map[1ll * (i - 1) * (nowans / n) + 1] = s[i];

	for(int i = 1; i <= m; i++)

	{

		long long nowx = 1ll * (i - 1) * (nowans / m) + 1;

		if(Map.find(nowx) != Map.end())

		{

			if(t[i] != Map[nowx])

			{

				puts("-1");

				return 0;

			}

		}

	}

	printf("%lld\n", nowans);

}