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



std::map<pii, int> cnt; 



int main() {

#ifdef orzczk

	freopen("a.in", "r", stdin); 

#endif



	int n; 



	scanf("%d", &n); 

	while (n--) {

		double x; 

		scanf("%lf", &x); 



		s64 cur = (s64)(x * 1e9 + 0.5); 



		int a = 0, b = 0; 

		while (cur % 2 == 0) cur /= 2, ++a; 

		while (cur % 5 == 0) cur /= 5, ++b;  



		++cnt[pii(a, b)]; 

	}



	s64 res = 0; 

	for (auto a : cnt)

		for (auto b : cnt) {

			if (a.first.first + b.first.first >= 18 && a.first.second + b.first.second >= 18) {

				if (a.first == b.first) {

					res += 1LL * a.second * (a.second - 1); 

				} else {

					res += 1LL * a.second * b.second; 

				} 

			}

		}

	

	std::cout << res / 2 << '\n'; 



	return 0; 

}