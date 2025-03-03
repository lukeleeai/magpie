#include <cstdio>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/priority_queue.hpp>



#define INF 0x3f3f3f3f

#define mp std::make_pair

#define fi first

#define se second



typedef std::pair<int, std::pair<int, int> > pip;



const int MAXN = 2e5 + 1;



int n, a[MAXN], pos[MAXN];



__gnu_pbds::priority_queue<pip, std::greater<pip> > q;



int f[2][MAXN][30];



namespace ST_Table {

	int Log[MAXN], bin[30];

	

	void Prework() {

		Log[0] = -1;

		for (int i = 1; i <= n; ++i)

			Log[i] = Log[i >> 1] + 1;

		bin[0] = 1;

		for (int i = 1; i <= 20; ++i)

			bin[i] = bin[i - 1] << 1;



		for (int k = 0; k <= 1; ++k)

			for (int j = 1; j <= Log[n]; ++j)

				for (int i = 1; i <= n - bin[j] + 1; ++i)

					f[k][i][j] = std::min(f[k][i][j - 1], f[k][i + bin[j - 1]][j - 1]); 

	}



	inline int Qmin(int op, int l, int r) {

		int k = Log[r - l + 1];

		return std::min(f[op][l][k], f[op][r - bin[k] + 1][k]);

	}



} using namespace ST_Table;



int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {

		scanf("%d", &a[i]);

		pos[a[i]] = i;

		f[i & 1][i][0] = a[i];

		f[i & 1 ^ 1][i][0] = INF;

	}



	Prework();

	q.push(mp(Qmin(1, 1, n), mp(1, n)));



	while (q.size()) {

		pip	Now = q.top();

		q.pop();

		int x = Now.fi, L = Now.se.fi, R = Now.se.se;

		int p1 = pos[x], p2 = pos[Qmin(pos[x] & 1 ^ 1, pos[x] + 1, R)];

		printf("%d %d ", a[p1], a[p2]);



		if (L < p1)

			q.push(mp(Qmin(L & 1, L, p1 - 1), mp(L, p1 - 1)));

		if (p1 < p2 - 1) 

			q.push(mp(Qmin(p1 + 1 & 1, p1 + 1, p2 - 1), mp(p1 + 1, p2 - 1)));

		if (p2 < R)

			q.push(mp(Qmin(p2 + 1 & 1, p2 + 1, R), mp(p2 + 1, R)));

	}



	return 0;

}