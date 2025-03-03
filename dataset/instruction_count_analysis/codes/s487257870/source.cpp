#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

typedef long long LL;

 

inline int read(){

	char ch = getchar(); int x = 0, op = 1;

	while (ch < '0' || '9' < ch) { if (ch == '-') op = -1; ch = getchar(); }

	while ('0' <= ch && ch <= '9') { x = x*10 + ch-'0'; ch = getchar(); }

	return op * x;

}

const int maxn = 100009;

LL n, s[maxn], t, res1, res2, op;

 

int main(){

	n = read();

	for (LL i=1; i<=n; i++) s[i] = s[i-1] + read();

	op = 1; t = 0;

	for (LL i=1; i<=n; i++){

		if (op == 1 && (s[i]+t) <= 0){

			res1 += 1 - (s[i]+t);

			t = 1 - s[i];

		}

		if (op == -1 && (s[i]+t) >= 0){

			res1 += (s[i]+t) + 1;

			t = -s[i] - 1;

		}

		op = -op;

	}

	op = -1; t = 0;

	for (LL i=1; i<=n; i++){

		if (op == 1 && (s[i]+t) <= 0){

			res2 += 1 - (s[i]+t);

			t = 1 - s[i];

		}

		if (op == -1 && (s[i]+t) >= 0){

			res2 += (s[i]+t) + 1;

			t = -s[i] - 1;

		}

		op = -op;

	}

	printf("%lld\n", min(res1, res2));

	return 0;

}