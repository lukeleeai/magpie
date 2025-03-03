#include "stdc++.h"



char buf[1 << 20], *p1, *p2;

#define getchar() ((p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)



template<typename T>

void read(T &x) 

{

	x = 0;

	int f = 1; char c = getchar();

	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }

	while (isdigit(c)) { x = x * 10 + c - 48; c = getchar(); }

	x *= f;

}



const int Mod = 1e9 + 7;



inline int add(int a, int b) { return a + b >= Mod ? a + b - Mod : a + b; }

inline int sub(int a, int b) { return a - b < 0 ? a - b + Mod : a - b; }

inline int mul(int a, int b) { return 1LL * a * b % Mod; }

inline void updateA(int &a, int b) { a = add(a, b); }

inline void updateM(int &a, int b) { a = mul(a, b); }



const int MAXN = 2e5 + 9;



int fac[MAXN], inv[MAXN], ifac[MAXN];



void Call(int n) 

{

	fac[0] = 1; for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);

	inv[1] = 1; for (int i = 2; i <= n; ++i) inv[i] = mul(sub(Mod, Mod / i), inv[Mod % i]);

	ifac[0] = 1; for (int i = 1; i <= n; ++i) ifac[i] = mul(ifac[i - 1], inv[i]);

}



int n;



struct Edge { int ver, nxt; } e[MAXN << 2];

int head[MAXN], tot = 0, Head[MAXN];



inline void Add(int x, int y) { e[++tot].ver = y, e[tot].nxt = head[x], head[x] = tot; }

inline void Add_(int x, int y) { e[++tot].ver = y, e[tot].nxt = Head[x], Head[x] = tot; }



int ans = 0;



std::vector<int> G;

bool vis[MAXN];

int edge = 0, s, t;

void GetLoop(int x, int Fa) 

{

	G.push_back(x);

	vis[x] = true;

	for (int i = head[x]; i; ++edge, i = e[i].nxt)

	{

		int y = e[i].ver;

		if (!vis[y]) GetLoop(y, x);

		else if (y != Fa)

			s = x, t = y;

	}

}



int pr[MAXN];

void GetPr(int x) 

{

	for (int i = head[x]; i; i = e[i].nxt) 

	{

		int y = e[i].ver;

		if (y == pr[x] || y == s) continue;

		pr[y] = x;

		GetPr(y);

	}

}



int deg[MAXN];

void Build()

{

	for (auto x : G)

		for (int i = head[x]; i; i = e[i].nxt) 	

		{

			int y = e[i].ver;

			if (y < pr[x]) Add_(x, y), ++deg[y];

			// 令每个点认领它的入边

			// 按照限制关系建边 

		}

}



int sz[MAXN];

void Dfs(int x) 

{

	sz[x] = 1;

	for (int i = Head[x]; i; i = e[i].nxt)

	{

		int y = e[i].ver;

		if (y == pr[x]) continue;

		Dfs(y);

		sz[x] += sz[y];

	}

}



int Calc() 

{

	for (auto i : G)

		Head[i] = deg[i] = 0;

	

	int res = fac[G.size()];

	

	pr[s] = t;

	GetPr(s);

	Build();



	for (auto i : G)

		if (!deg[i])

			Dfs(i);

	for (auto i : G) 

		updateM(res, inv[sz[i]]);

		

	return res;

}



int main() 

{

	read(n);

	for (int i = 1; i <= n << 1; ++i)

	{

		int x, y;

		read(x), read(y);

		Add(x, y + n), Add(y + n, x); 

	}



	n <<= 1; 

	Call(n);



	ans = fac[n];



	for (int i = 1; i <= n; ++i) 

		if (!vis[i])

		{

			GetLoop(i, 0);

			if (G.size() << 1 != edge) { ans = 0; break; } // 是否是基环树 

			updateM(ans, ifac[G.size()]);

			int res = 0;

			updateA(res, Calc());

			std::swap(s, t); // 换个方向 

			updateA(res, Calc());

			updateM(ans, res);

	

			G.clear();

			edge = 0;

		}



	printf("%d\n", ans);	



	return 0;

}