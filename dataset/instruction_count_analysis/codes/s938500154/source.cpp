#include"stdc++.h"

using namespace std;

#define reg register

#define MaxN 100003

#define hhhhhhh 1000000



int N;

int fa[MaxN];

long long ans, cnty[MaxN], cntx[MaxN];

map<int, bool> bk[MaxN];

struct Nd {

	int x, y;

}a[MaxN];



inline int Rd() {

	int x = 0, f = 1; char ch = getchar();

	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }

	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();

	return x * f;

}

inline int Find(int d) {

	if(fa[d] == d) return d;

	else return fa[d] = Find(fa[d]);

} 

inline bool cmp(Nd aa, Nd bb) {

	return aa.x < bb.x;

}



int main() {

	N = Rd();

	for(reg int i = 1; i <= 100000; ++i)

		fa[i] = i;

	for(reg int i = 1; i <= N; ++i)

		a[i].x = Rd(), a[i].y = Rd();

	sort(a + 1, a + 1 + N, cmp);

	for(reg int i = 1; i < N; ++i)

		if(a[i].x == a[i + 1].x)

			fa[Find(a[i].y)] = Find(a[i + 1].y);

	for(reg int i = 1; i <= 100000; ++i)

		++cnty[Find(i)];

	for(reg int i = 1; i <= N; ++i)

		if(!bk[Find(a[i].y)][a[i].x]) {

			++cntx[Find(a[i].y)];

			bk[Find(a[i].y)][a[i].x] = true;

		}

	for(reg int i = 1; i <= 100000; ++i)

		ans += cnty[i] * cntx[i];

	cout << ans - N << endl;

	return 0;

}
