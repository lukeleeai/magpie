#include <cstdio>

#include <algorithm>

#include <cstring>

#include <cctype>

using namespace std;



namespace zyt

{

	template<typename T>

	inline bool read(T &x)

	{

		char c;

		bool f = false;

		x = 0;

		do

			c = getchar();

		while (c != EOF && c != '-' && !isdigit(c));

		if (c == EOF)

			return false;

		if (c == '-')

			f = true, c = getchar();

		do

			x = x * 10 + c - '0', c = getchar();

		while (isdigit(c));

		if (f)

			x = -x;

		return true;

	}

	template<typename T>

	inline void write(T x)

	{

		static char buf[20];

		char *pos = buf;

		if (x < 0)

			putchar('-'), x = -x;

		do

			*pos++ = x % 10 + '0';

		while (x /= 10);

		while (pos > buf)

			putchar(*--pos);

	}

	const int N = 1e5 + 10;

	int n, a[N], b[N], fa[N], ida[N], idb[N];

	int f(const int x)

	{

		return x == fa[x] ? x : fa[x] = f(fa[x]);

	}

	bool cmpa(const int i, const int j)

	{

		return a[i] < a[j];

	}

	bool cmpb(const int i, const int j)

	{

		return b[i] < b[j];

	}

	int work()

	{

		read(n);

		for (int i = 1; i <= n; i++)

			read(a[i]), ida[i] = i;

		for (int i = 1; i <= n; i++)

			read(b[i]), idb[i] = i;

		sort(ida + 1, ida + n + 1, cmpa);

		sort(idb + 1, idb + n + 1, cmpb);

		for (int i = 1; i <= n; i++)

		{

			fa[i] = i;

			if (a[ida[i]] > b[idb[i]])

			{

				puts("No");

				return 0;

			}

		}

		for (int i = 1; i <= n; i++)

			if (i && a[ida[i]] <= b[idb[i - 1]])

			{

				puts("Yes");

				return 0;

			}

		int cnt = 0;

		for (int i = 1; i <= n; i++)

		{

			int x = f(ida[i]), y = f(idb[i]);

			if (x == y)

				++cnt;

			else

				fa[x] = y;

		}

		if (cnt > 1)

			puts("Yes");

		else

			puts("No");

		return 0;

	}

}

int main()

{

	return zyt::work();

}