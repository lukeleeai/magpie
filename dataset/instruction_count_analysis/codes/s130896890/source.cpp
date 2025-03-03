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

	typedef long long ll;

	typedef pair<int, int> pii;

	const int N = 2e5 + 10;

	int n, sufmx[N], sufmn[N];

	pii arr[N];

	int work()

	{

		read(n);

		int mx = 0, mn = 1e9;

		for (int i = 1; i <= n; i++)

		{

			read(arr[i].first), read(arr[i].second);

			if (arr[i].first > arr[i].second)

				swap(arr[i].first, arr[i].second);

			mx = max(mx, arr[i].second), mn = min(mn, arr[i].second);

		}

		sort(arr + 1, arr + n + 1);

		ll ans = ll(arr[n].first - arr[1].first) * (mx - mn), k = mx - arr[1].first;

		mn = 1e9, mx = 0;

		sufmx[n + 1] = 0, sufmn[n + 1] = 1e9;

		for (int i = n; i > 0; i--)

			sufmx[i] = max(sufmx[i + 1], arr[i].first), sufmn[i] = min(sufmn[i + 1], arr[i].first);

		for (int i = 1; i <= n; i++)

		{

			mn = min(mn, arr[i].second), mx = max(mx, arr[i].second);

			ans = min(ans, k * (max(sufmx[i + 1], mx) - min(sufmn[i + 1], mn)));

		}

		write(ans);

		return 0;

	}

}

int main()

{

	return zyt::work();

}