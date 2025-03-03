#include "stdc++.h"



template <class T>

inline void read(T &res)

{

	char ch; bool flag = false; res = 0;

	while (ch = getchar(), !isdigit(ch) && ch != '-');

	ch == '-' ? flag = true : res = ch ^ 48;

	while (ch = getchar(), isdigit(ch))

		res = res * 10 + ch - 48;

	flag ? res = -res : 0;

}



template <class T>

inline void put(T x)

{

	if (x > 9)

		put(x / 10);

	putchar(x % 10 + 48);

}



template <class T>

inline void CkMax(T &x, T y) {x < y ? x = y : 0;}

template <class T>

inline void CkMin(T &x, T y) {x > y ? x = y : 0;}

template <class T>

inline T Max(T x, T y) {return x > y ? x : y;}

template <class T>

inline T Min(T x, T y) {return x < y ? x : y;}



const int N = 1e5 + 5;

int n, ans;



struct seg

{

	int l, r;



	seg() {}

	seg(int L, int R):

		l(L), r(R) {}



	inline int len()

	{

		return r >= l ? r - l + 1 : 0;

	}



	inline void scan()

	{

		read(l);

		read(r);

	}



	inline bool operator < (const seg &a) const

	{

		return r < a.r || r == a.r && l > a.l;

	}



	inline seg operator & (const seg &a) const 

	{

		return seg(Max(l, a.l), Min(r, a.r));

	}

}p[N], pre[N], suf[N];



inline void solve()

{

	pre[0] = seg(1, 1e9);

	for (int i = 1; i <= n; ++i)

		pre[i] = pre[i - 1] & p[i];

	suf[n + 1] = seg(1, 1e9);

	for (int i = n; i >= 1; --i)

		suf[i] = suf[i + 1] & p[i];

	for (int i = 1; i < n; ++i)

		CkMax(ans, pre[i].len() + suf[i + 1].len());

	for (int i = 1; i <= n; ++i)

		CkMax(ans, (pre[i - 1] & suf[i + 1]).len() + p[i].len());

}



int main()

{

	read(n);

	for (int i = 1; i <= n; ++i)

		p[i].scan();



	std::sort(p + 1, p + n + 1);

	solve();

	for (int i = n; i >= 1; --i)

	{

		p[i].l = 1e9 - p[i].l + 1;

		p[i].r = 1e9 - p[i].r + 1;

	}



	std::sort(p + 1, p + n + 1);

	solve();

	for (int i = 1; i <= 100; ++i)

	{

		for (int j = 1; j <= 100; ++j)

			std::swap(p[1ll * rand() * rand() % n + 1], p[1ll * rand() * rand() % n + 1]);

		solve();

	}

	

	printf("%d\n", ans);



	return 0;

}