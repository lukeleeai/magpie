/* */



#include <cstdio>

#include <cstring>

#include <cassert>

#include <cmath>

#include <string>

#include <iostream>

#include <algorithm>

#include <vector>

#include <queue>

#include <bitset>

#include <map>

#include <set>

using namespace std;

using ll = long long;

using ii = pair<int, int>;

using pll = pair<ll, ll>;



#ifdef XVENOM

	#define errp(...) fprintf(stderr, __VA_ARGS__)

#else

	#define errp(...)

#endif

#define dbg(x) errp("%s = %s\n", #x, to_string(x).data())

#define dbg_al(s, x) for(auto e:x)s+=to_string(e)+" "

#define dbg_rt(x) string s="[ ";dbg_al(s,x);s+="]";return s;

#define dbg_fd1 template<typename T>string to_string

#define dbg_fd2 template<typename U, typename V>string to_string

#define dbg_d1(c) dbg_fd1(c<T>);

#define dbg_d2(c) dbg_fd2(c<U, V>);

#define dbg_f1(c) dbg_fd1(c<T> v){dbg_rt(v);}

#define dbg_f2(c) dbg_fd2(c<U, V> v){dbg_rt(v);}

string to_string (char s) { return "\'"+string(1, s)+"\'"; }

string to_string (string s) { return "\"" + s + "\""; }

dbg_d1(vector) dbg_d1(set) dbg_d2(map)

dbg_fd2(pair<U, V> p) { return "("+to_string(p.first)+", "+to_string(p.second)+")"; }

dbg_f1(vector) dbg_f1(set) dbg_f2(map)

/* ==================== */ 

const int M = 10010;

const int N = 110;

int f[N][M], n, s[N];



int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", &s[i]);

	memset(f, 0, sizeof f);

	f[0][0] = f[0][s[0]] = true;

	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < M; j++) if (f[i][j]) {

			f[i + 1][j] = 1;

			f[i + 1][j + s[i + 1]] = 1;

		}

	}

	int mx = 0;

	for (int i = 0; i < M; i++) if (f[n - 1][i] && i % 10)

		mx = i;

	printf("%d\n", mx);

}
