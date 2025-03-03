#include <cstdio>

#include <algorithm>

#include <cstring>

using namespace std;

 

namespace MF {

	#define MAXN 50000

	#define MAXM 500000

	#define wint int

	const wint wEPS = 0;

	const wint wINF = 1001001001;

	int n, m, ptr[MAXN], next[MAXM], zu[MAXM];

	wint capa[MAXM], tof;

	int lev[MAXN], see[MAXN], que[MAXN], *qb, *qe;

	void init(int _n) {

		n = _n; m = 0; memset(ptr, ~0, n * 4);

	}

	void ae(int u, int v, wint w0, wint w1 = 0) {

		next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w0; ++m;

		next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = w1; ++m;

	}

	wint augment(int src, int ink, wint flo) {

		if (src == ink) return flo;

		wint f;

		for (int &i = see[src]; ~i; i = next[i]) if (capa[i] > wEPS && lev[src] < lev[zu[i]]) {

			if ((f = augment(zu[i], ink, min(flo, capa[i]))) > wEPS) {

				capa[i] -= f; capa[i ^ 1] += f; return f;

			}

		}

		return 0;

	}

	bool solve(int src, int ink, wint flo = wINF) {

		wint f;

		int i, u, v;

		for (tof = 0; tof + wEPS < flo; ) {

			qb = qe = que;

			memset(lev, ~0, n * 4);

			for (lev[*qe++ = src] = 0, see[src] = ptr[src]; qb != qe; ) {

				for (i = ptr[u = *qb++]; ~i; i = next[i]) if (capa[i] > wEPS && !~lev[v = zu[i]]) {

					lev[*qe++ = v] = lev[u] + 1; see[v] = ptr[v];

					if (v == ink) goto au;

				}

			}

			return 0;

		au:	for (; (f = augment(src, ink, flo - tof)) > wEPS; tof += f);

		}

		return 1;

	}

}

 

int H, W;

char A[110][110];

 

int main()

{

	scanf("%d%d", &H, &W);

	for (int i = 0; i < H; ++i) {

		scanf("%s", A[i]);

	}

 

	int s, t;

	MF::init(H * W * 2 + H + W);

 

	for (int i = 0; i < H; ++i) {

		for (int j = 0; j < W; ++j) {

			int id = i * W + j;

 

			if (A[i][j] == 'S') s = id;

			if (A[i][j] == 'T') t = id;

 

			if (A[i][j] != '.') {

				MF::ae(id * 2, id * 2 + 1, 1, 0);

				MF::ae(id * 2 + 1, H * W * 2 + j, 1000);

				MF::ae(id * 2 + 1, H * W * 2 + W + i, 1000);

				MF::ae(H * W * 2 + j, id * 2, 1000);

				MF::ae(H * W * 2 + W + i, id * 2, 1000);

			}

		}

	}

	

	MF::solve(s * 2 + 1, t * 2);

	int ret = MF::tof;

	if (ret > 200) ret = -1;

	printf("%d\n", ret);

 

}