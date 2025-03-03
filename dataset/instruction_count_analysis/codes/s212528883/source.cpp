#include <iostream>

#include <cstdlib>

#include <cstdio>

#include <cstring>

#include <algorithm>



#include <vector>



using namespace std;





typedef long long LL;





typedef pair <int, int> pr;





const int N = 2e5 + 10;



const int INF = 2e9;





const LL mod = 1e9 + 7;





inline LL power(LL a, LL n, LL mod)

{

	LL Ans = 1;

	while (n)

	{

		if (n & 1) Ans = Ans * a % mod;

		a = a * a % mod;

		n >>= 1;

	}

	return Ans;

}





namespace ufs

{

	int parent[N];



	void init(int n) { for (int i = 1; i <= n; i++) parent[i] = i; }



	inline int findrt(int x) { return parent[x] == x ? x : parent[x] = findrt(parent[x]); }



	void merge(int x, int y)

	{

		x = findrt(x), y = findrt(y);

		parent[x] = y;

	}

}





int col[N], w[N];

int n, X, Y;



pr minv[N];

vector <int> vec[N];

int cnt[N];





LL fac[N], ifac[N];



inline LL calc(int n, int m) { return n < m ? 0 : fac[n] * ifac[m] % mod * ifac[n-m] % mod; }





int main()

{

	cin >> n >> X >> Y;

	

	fac[0] = 1;

	for (int i = 1; i <= n; i++) fac[i] = fac[i-1] * i % mod;

	ifac[n] = power(fac[n], mod-2, mod);

	for (int i = n-1; i >= 0; i--) ifac[i] = ifac[i+1] * (i+1) % mod;

	

	int maxc = 0;

	for (int i = 1; i <= n; i++)

	{

		scanf("%d %d", &col[i], &w[i]);

		maxc = max(maxc, col[i]);

	}

	for (int i = 1; i <= maxc; i++) minv[i] = make_pair(INF, INF);

	

	for (int i = 1; i <= n; i++)

	{

		minv[col[i]] = min(minv[col[i]], make_pair(w[i], i));

		vec[col[i]].push_back(i);

	}

	

	ufs::init(n);

	

	for (int i = 1; i <= maxc; i++)

	{

		for (auto id : vec[i])

			if (w[id] + minv[i].first <= X)

				ufs::merge(id, minv[i].second);

	}

	

	pr mn = make_pair(INF, INF), mn2 = make_pair(INF, INF);

	for (int i = 1; i <= n; i++)

	{

		pr tmp = make_pair(w[i], i);

		mn = min(mn, tmp);

	}

	for (int i = 1; i <= n; i++)

	{

		pr tmp = make_pair(w[i], i);

		if (col[i] != col[mn.second])

			mn2 = min(mn2, tmp);

	}

	

	for (int i = 1; i <= n; i++)

		if (col[mn.second] != col[i] && mn.first + w[i] <= Y)

			ufs::merge(mn.second, i);

		else if (mn2.first != INF && col[mn2.second] != col[i] && mn2.first + w[i] <= Y)

			ufs::merge(mn2.second, i);

	

	for (int i = 1; i <= n; i++)

		if (ufs::findrt(i) == ufs::findrt(mn.second))

			cnt[col[i]]++;

	

	int all = 0;

	for (int i = 1; i <= maxc; i++)

		all += cnt[i];

	

	LL Ans = 1;

	for (int i = 1; i <= maxc; i++)

		if (cnt[i])

		{

			Ans = Ans * calc(all, cnt[i]) % mod;

			all -= cnt[i];

		}

	

	printf("%lld\n", Ans);

	

	return 0;

}