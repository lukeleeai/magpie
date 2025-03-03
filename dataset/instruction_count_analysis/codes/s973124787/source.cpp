#include "stdc++.h" 

using namespace std; 

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i <= i##_end_; ++i)

#define drep(i, a, b) for (int i = (a), i##_end_ = (b); i >= i##_end_; --i)

#define clar(a, b) memset((a), (b), sizeof(a))

#define debug(...) fprintf(stderr, __VA_ARGS__)

template <typename T> bool chkmax(T &a, const T &b) { return a < b ? a = b, true : false; }

template <typename T> bool chkmin(T &a, const T &b) { return a > b ? a = b, true : false; }

template <typename T> T sgn(const T&a) { return (a > T(0)) - (a < T(0)); }

typedef long long LL;

typedef long double LD;

const int BUF_SIZE = (int)2e7 + 10;

struct fastIO {

    char buf[BUF_SIZE], buf1[BUF_SIZE];

    int cur, cur1; FILE *in, *out;

    fastIO() { cur = BUF_SIZE, in = stdin, out = stdout; cur1 = 0; __builtin_prefetch(buf);__builtin_prefetch(buf1);}

    inline char getchar() { if(cur == BUF_SIZE) fread(buf, BUF_SIZE, 1, in), cur = 0; return *(buf + (cur++)); }

    inline void putchar(char ch) { *(buf1 + (cur1++)) = ch; if (cur1 == BUF_SIZE) fwrite(buf1, BUF_SIZE, 1, out), cur1 = 0; }

    inline int flush() { if (cur1 > 0) fwrite(buf1, cur1, 1, out); return cur1 = 0; }

}IO;

#define getchar IO.getchar

LL read() {

	LL x = 0, flag = 1;

	char ch = getchar();

	for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag *= -1;

	for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;

	return x * flag;

}

void write(LL x) {

	if (x < 0) putchar('-'), x = -x;

	if (x >= 10) write(x / 10);

	putchar(x % 10 + '0');

} 



const int Maxn = 1e5 + 9;

struct edge {

	int to, nxt;

}g[Maxn << 1];

int n, head[Maxn];

void add(int u, int v) { 

	static int e = 0;

	g[++e] = (edge){v, head[u]}, head[u] = e; 

}



int ans = 0;

static int bit[Maxn];



void dfs(int u, int pa) {

	int same = 0;

	for (int i = head[u]; ~i; i = g[i].nxt) {

		int v = g[i].to;

		if (v != pa) {

			dfs(v, u);

			same |= bit[u] & bit[v];

			bit[u] |= bit[v];

		}

	}

	int mx = same ? 32 - __builtin_clz(same) : 0;

	while (bit[u] & (1 << mx)) ++mx;

	bit[u] |= (1 << mx);

	chkmax(ans, mx), bit[u] = bit[u] >> mx << mx;

}



int main() {



	clar(head, -1);

	n = read();

	rep (i, 1, n - 1) {

		int u = read(), v = read();

		add(u, v), add(v, u);

	}

	dfs(1, 0);

	cout << ans << endl;



#ifdef Qrsikno

	debug("\nRunning time: %.3lf(s)\n", clock() * 1.0 / CLOCKS_PER_SEC);

#endif

	return 0;

}
