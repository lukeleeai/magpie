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

const int N = 110;

int n, s[N];



int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", s + i);

	int sm = 0, mn = N, ans;

	for (int i = 0; i < n; i++) sm += s[i];

	if (sm % 10) ans = sm; 

	else {

		for (int i = 0; i < n; i++) if (s[i] % 10)

			mn = min(mn, s[i]);

		if (mn == N) ans = 0;

		else ans = sm - mn;

	}

	printf("%d\n", ans);

}
