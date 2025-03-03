#include "stdc++.h"



template <class T>

inline void read(T &x) {

	static char ch; 

	static bool opt; 

	while (!isdigit(ch = getchar()) && ch != '-'); 

	x = (opt = ch == '-') ? 0 : ch - '0'; 

	while (isdigit(ch = getchar()))

		x = x * 10 + ch - '0'; 

	if (opt)

		x = ~x + 1; 

}



template <class T>

inline void putint(T x) {

	static char buf[45], *tail = buf; 

	if (!x)

		putchar('0'); 

	else {

		if (x < 0)

			putchar('-'), x = ~x + 1; 

		for (; x; x /= 10) *++tail = x % 10 + '0'; 

		for (; tail != buf; --tail) putchar(*tail); 

	}

}



template <class T>

inline bool tense(T &x, const T &y) {

	return y < x ? x = y, true : false; 

}



template <class T>

inline bool relax(T &x, const T &y) {

	return x < y ? x = y, true : false; 

}



template <class T>

inline T getAbs(const T &x) {

	return x < 0 ? -x : x; 

}



typedef long long s64; 

typedef long double ld; 

typedef std::vector<int> vi; 

typedef std::pair<int, int> pii; 

#define mp(x, y) std::make_pair(x, y)



const int MaxN = 2e5 + 5; 



int n; 

s64 a[MaxN], b[MaxN], ans; 

std::vector<int> divisor, son[110], par[110]; 



ld t[MaxN]; 

int cnt[110][110];  



inline s64 gcd(s64 a, s64 b) {

	return b ? gcd(b, a % b) : a; 

}



int main() {

#ifdef orzczk

	freopen("a.in", "r", stdin); 

#endif



	std::ios::sync_with_stdio(false);

	std::cin.tie(0);



	s64 M = 1e9; 

	for (int i = 1; i * i <= M; ++i)

		if (M % i == 0) {

			divisor.push_back(i); 

			divisor.push_back(M / i); 

		}

	

	int S = divisor.size(); 

	for (int i = 0; i < S; ++i)

		for (int j = 0; j < S; ++j)

			if (divisor[i] % divisor[j] == 0) {

				son[i].push_back(j); 

				par[j].push_back(i); 

			}

	

	// std::cerr << divisor.size() << '\n'; 

	

	std::cin >> n; 

	for (int i = 1; i <= n; ++i) {

		std::cin >> t[i]; 



		a[i] = (s64)(t[i] * (ld)M + 1e-3); 

		s64 g = gcd(a[i], M), m = M / g; 



		// std::cout << a[i] << ' ' << g << '\n'; 



		int posM = 0, posA = 0; 

		s64 tg = gcd(a[i] / g, M); 

		for (int i = 0; i < S; ++i) {

			if (divisor[i] == m) {

				posM = i; 

			}

			if (divisor[i] == tg) {

				posA = i; 

			}

		}



		// std::cerr << '>' << posA << ' ' << posM << '\n'; 



		for (int x : son[posA])

			for (int y : par[posM]) {

				// std::cout << ':' << x << ' ' << y << '\n'; 

				ans += cnt[y][x]; 

			}



		++cnt[posA][posM]; 

	}



	std::cout << ans << '\n'; 



	return 0; 

}