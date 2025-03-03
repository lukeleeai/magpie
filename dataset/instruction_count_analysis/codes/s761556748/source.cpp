#include<iostream>

#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<algorithm>

#include<stack>

#include<queue>

#include<vector>

#include<set>

#include<string>

#include<cmath>

#include<map>

#include<bitset>

#include<utility>

//#include<unordered_map>

#ifdef LOCAL

#include"file.h"

#endif



using namespace std;



typedef long long LL;

typedef unsigned long long ULL;

const double eps = 1e-12;

const double Pi = 3.1415926535897932;

const int dir[4][2] = { -1,0,1,0,0,-1,0,1 };

//const int dir[8][2] = { -2,-1,-2,1,2,-1,2,1,-1,2,-1,-2,1,2,1,-2 };











const int maxn = 1e5 + 5;

LL f[maxn];





int main() {

#ifdef LOCAL

	fileopen();

#endif

	int n, C;

	scanf("%d%d", &n, &C);

	memset(f, -1, sizeof(f));

	f[0] = 0;

	for (int i = 1; i <= n; i++) {

		int w, v;

		scanf("%d%d", &w, &v);

		for (int i = C; i >= w; i--)if(f[i-w]!=-1) {

			f[i] = max(f[i], f[i - w] + v);

		}

	}

	LL ans = 0;

	for (int i = 0; i <= C; i++)ans = max(ans, f[i]);

	printf("%lld\n", ans);



#ifdef LOCAL

	fileclose();

#endif

	return 0;

}