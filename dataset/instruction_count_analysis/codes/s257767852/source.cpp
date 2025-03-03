#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <climits>

#include <cfloat>

#include <ctime>

#include <map>

#include <utility>

#include <set>

#include <iostream>

#include <memory>

#include <string>

#include <vector>

#include <algorithm>

#include <functional>

#include <sstream>

#include <complex>

#include <stack>

#include <queue>

#include <numeric>



using namespace std;



#ifdef _MSC_VER

#define __typeof__ decltype



template <class T>

int __builtin_popcount(T n) { return n ? 1 + __builtin_popcount(n & (n - 1)) : 0; }

#endif



#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)

#define all(c) (c).begin(), (c).end()

#define rall(c) (c).rbegin(), (c).rend()

#define popcount __builtin_popcount



const double EPS = 1e-8;

typedef long long ll;

typedef pair<int, int> pint;





int main()

{

	int x, y, z;

	while (scanf("%d%d%d", &x, &y, &z), x|y|z)

	{

		float p = 1.0 / x;

		int v[4], e[51], a[51];

		for (int i = 0; i < x; ++i)

			scanf("%d", v + i);

		memset(e, 0, sizeof(e));

		for (int i = 0; i < z; ++i)

		{

			int t;

			scanf("%d", &t);

			scanf("%d%d", e + t, a + t);

		}

		int max_money = 0;

		for (int i = 0; i < y; ++i)

			if (e[i] == 2)

				max_money += a[i];



		static float dp[51][5001];

		for (int i = 0; i <= y; ++i)

			for (int j = 0; j <= max_money; ++j)

				dp[i][j] = 0;

		dp[0][0] = 1;

		for (int i = 0; i < y; ++i)

		{

			for (int j = 0; j <= max_money; ++j)

			{

				if (dp[i][j] == 0)

					continue;



				for (int k = 0; k < x; ++k)

				{

					int to = min(y, i + v[k]);

					int money = j;

					if (e[to] == 1)

						to = min(y, to + a[to]);

					else if (e[to] == 2)

						money += a[to];

					else if (e[to] == 3)

						money = max(0, money - a[to]);



					dp[to][money] += dp[i][j] * p;

				}

			}

		}



		float res = 0;

		for (int i = 0; i <= max_money; ++i)

			res += i * dp[y][i];



		printf("%d\n", (int)res);

	}



	return 0;

}